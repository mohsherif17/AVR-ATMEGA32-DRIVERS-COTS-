/****************************************************************************/
/*************           file   : TIMER_program.c               *************/
/*************           author : Muhammed Sherif               *************/
/*************           date   :  21/12/2023          		    *************/
/****************************************************************************/

/******************includes******************/
#include "STD_TYPES.h"
#include"BIT_MATH.h"
#include "TIMER_config.h"
#include"TIMER_interface.h"
#include "TIMER_private.h"
#include "TIMER_register.h"

/*********Global Variables Declaration*********/
static void(*Global_T0_OVFPtrFunc)(void)=NULL;		 /*Global Pointer to the call back function for OVF mode FOR T0*/
static void(*Global_T0_CTCPtrFunc)(void)=NULL;		 /*Global Pointer to the call back function for CTC mode FOR T0*/

u16 G_u16Counts;							     /*Global variable to pass the OVF counts to the ISR*/

/**********Functions implementations**********/

/************************************************************************************************************/
/* -> NAME:           @ void TIMER0_voidInit(void)															*/
/* -> DESCRIBTION:    @ this function is used to initialize the timer/counter PREPHIRAL				     	*/
/* 	   			   and select the mode whether {Normal time/ CTC timer/FAST PWM/ PHASE CORRECT PWM}		    */
/* -> Parameters: 	   @ void																				*/
/************************************************************************************************************/
void TIMER0_voidInit(void){
#if(TIMER_COUNTER0_MODE==TIMER)							/*TIMER/counter0 0 CHECK CONFIG if TIMER*/
		#if(TIMER0_MODE==NORMAL)							/*set TIMER/counter0 as timer in normal mode */
		CLR_BIT(TCCR0,TCCRO_WGM01);
		CLR_BIT(TCCR0,TCCRO_WGM00);
		#elif(TIMER0_MODE==CTC)								/*set TIMER/counter0 as timer in CTC mode */
		SET_BIT(TCCR0,TCCRO_WGM01);
		CLR_BIT(TCCR0,TCCRO_WGM00);
		TCCR0 &=0xCF;
		TCCR0|= CTC_PIN;
		#elif(TIMER0_MODE==FAST_PWM)						/*set TIMER/counter0 as timer in FAST PWM mode */
		SET_BIT(TCCR0,TCCRO_WGM01);
		SET_BIT(TCCR0,TCCRO_WGM00);
		TCCR0 &=0xCF;
		TCCR0|= PWM0_MODE;
		#elif(TIMER0_MODE==PHASE_CORRECT)					/*set TIMER/counter0 as timer in phase correct PWM mode */
		CLR_BIT(TCCR0,TCCRO_WGM01);
		SET_BIT(TCCR0,TCCRO_WGM00);
		TCCR0 &=0xCF;
		TCCR0|= PWM0_MODE;
		#endif

#elif (TIMER_COUNTER0_MODE==COUNTER)					/*timer/COUNTER 0 CHECK CONFIG if COUNTER*/
			#if(COUNTER0_SENSE==RISING_EDGE)					/*SET COUNTER MODE AS RISING EDGE*/
			SET_BIT(TCCR0,TCCRO_CS00);
			SET_BIT(TCCR0,TCCRO_CS01);
			SET_BIT(TCCR0,TCCRO_CS02);
			#elif(COUNTER0_SENSE==FALLING_EDGE)					/*SET COUNTER MODE AS FALLING EDGE*/
			CLR_BIT(TCCR0,TCCRO_CS00);
			SET_BIT(TCCR0,TCCRO_CS01);
			SET_BIT(TCCR0,TCCRO_CS02);
			#endif

#endif

}

/*********************************************************************************************************************/
/* -> NAME:           @ void TIMER0_voidSetIntervalSynchronous(u16 Copy_Counts);									 */
/* -> DESCRIBTION:    @ This function is a Pooling	Function using the timer PREPHIRAL 					             */
/* 	   			   	 it's used to give the timer the number of counts required to wait for before doing			 	 */
/*						 the next instruction, the program can't continue until the counts are done         		 */
/* -> Parameters: 	   @ Copy_Counts-> number of counts until the wait is done  = (PreScaler/SYS_Frequancy)*OVF_count*/
/*********************************************************************************************************************/
void TIMER0_voidSetIntervalSynchronous(u16 Copy_Counts){
/*FOR LOOP to iterate over the number of counts until busy wait is over*/
	for(u8 Local_u8Counter = 0;Local_u8Counter < Copy_Counts;Local_u8Counter++){
	while(GET_BIT(TIFR,TIFR_TOV0)!=1);			/*wait until the timer register flag is up to declare the end of one count*/
	SET_BIT(TIFR,TIFR_TOV0);					/*clear the flag to start a new count */
	}
}
/*********************************************************************************************************************/
/* -> NAME:           @ void TIMER0_voidSetIntervalASynchronous(u16 Copy_Counts,void(*PtrFunc)(void));				 */
/* -> DESCRIBTION:    @ This function is an Interrupt Function using the timer PREPHIRAL 				             */
/* 	   			   	    it's used to give the timer the number of counts required to wait for before doing		 	 */
/*						the next instruction and the ISR Function to be done after the wait,                         */
/*                      the program runs Systematically as it's an interrupt function                                */
/* -> Parameters: 	   @ Copy_Counts-> number of counts until the wait is done  = (PreScaler/SYS_Frequancy)*OVF_count*/
/*                     @void(*PtrFunc)(void)-> pointer to the CallBack function to be passed to the ISR              */
/*********************************************************************************************************************/
void TIMER0_voidSetIntervalASynchronous(u16 Copy_Counts,void(*PtrFunc)(void)){
#if TIMER0_MODE==NORMAL										/*check the timer mode if normal mode*/
	SET_BIT(TMISK,TMISK_TOIE0);								/*Set the timer mask */
	Global_T0_OVFPtrFunc=PtrFunc;							/*pass the OVF call back function to the ISR*/
	G_u16Counts=Copy_Counts;								/*pass the number of counts required to wait for*/
#elif (TIMER0_MODE==CTC)									/*check the timer mode if CTC mode*/
	SET_BIT(TMISK,TMISK_TOIE0);                             /*Set the timer mask */
	Global_T0_CTCPtrFunc=PtrFunc;                           /*pass the CTC call back function to the ISR*/
	G_u16Counts=Copy_Counts;                     	        /*pass the number of counts required to wait for*/
#endif
}
/************************************************************************************************************/
/* -> NAME:           @ void TIMER0_voidSetCompareValue(u8 Copy_u8CompareVal)								*/
/* -> DESCRIBTION:    @ this function is used to The compare value in the OCR0 Register					    */
/* -> Parameters: 	  @ Copy_u8CompareVal the value to compare with for the OCR register 					*/
/************************************************************************************************************/
void TIMER0_voidSetCompareValue(u8 Copy_u8CompareVal){
	OCR0=Copy_u8CompareVal;					/*SET the OCR reg by the value of counts to set the top value for CTC mode*/
}
/************************************************************************************************************/
/* -> NAME:           @ void TIMER0_voidStop(void)															*/
/* -> DESCRIBTION:    @ this function is used to STOP the timer/counter PREPHIRAL	(Clearing the PreScaler)*/
/* -> Parameters: 	  @ void																				*/
/************************************************************************************************************/
void TIMER0_voidStop(void){
	/*CLEAR the PreScaler bits to disable the timer*/
	CLR_BIT(TCCR0,TCCRO_CS00);
	CLR_BIT(TCCR0,TCCRO_CS01);
	CLR_BIT(TCCR0,TCCRO_CS02);
}

/************************************************************************************************************/
/* -> NAME:           @ void TIMER0_voidSetPRELOADValue(u8 Copy_u8Value)										*/
/* -> DESCRIBTION:    @ this function is used to The PreLoad value For CTC Mode							    */
/* -> Parameters: 	  @ Copy_u8Value the value Of CTC MODE		   						 					*/
/************************************************************************************************************/
void TIMER0_voidSetPRELOADValue(u8 Copy_u8Value){
	/**/
	TCNT0=Copy_u8Value;
}
/************************************************************************************************************/
/* -> NAME:           @ void TIMER0_voidSTART(void)															*/
/* -> DESCRIBTION:    @ this function is used to START the timer/counter PREPHIRAL	(Setting the PreScaler)	*/
/* -> Parameters: 	  @ void																				*/
/************************************************************************************************************/
void TIMER0_voidSTART(void){
	/*Bit masking the PreScaler BITS to enable the timer */
	TCCR0 &= 0xf0;
	TCCR0 |=TIMER0_PRESCALER;
}
/*********************************************************************************************************************/
/* -> NAME:           @ TIMER0_voidSetIntervalSynchronousMS(u16 Copy_MILLESEC);   									 */
/* -> DESCRIBTION:    @ This function is a Pooling	Function using the timer PREPHIRAL 					             */
/* 	   			   	    it's used to give the timer the number of counts required to wait for before doing			 */
/*						the next instruction, the program can't continue until the counts are done         		     */
/* -> Parameters: 	   @ Copy_Counts-> number of mille Seconds required to wait before the action				     */
/*********************************************************************************************************************/
void TIMER0_voidSetIntervalSynchronousMS(u16 Copy_MILLESEC){
			u16 Local_COUNTS=0;
			/*calculate the required Counts to achieve a wait  in mille seconds*/
			Local_COUNTS=((Copy_MILLESEC)/(OVF_COUNTS_T0));
			Local_COUNTS*=TICK_TIME_T0_ms;
	TIMER0_voidSetIntervalSynchronous(Local_COUNTS);	/*setting the counts number*/
}
/*********************************************************************************************************************/
/* -> NAME:           @ void TIMER0_voidSetIntervalASynchronousMS(u16 Copy_MILLESEC,void(*PtrFunc)(void));			 */
/* -> DESCRIBTION:    @ This function is an Interrupt Function using the timer PREPHIRAL 				             */
/* 	   			   	    it's used to give the timer the number of mille Seconds required to wait for before doing	 */
/*						the next instruction and the ISR Function to be done after the wait,                         */
/*                      the program runs Systematically as it's an interrupt function                                */
/* -> Parameters: 	   @ Copy_MILLESEC-> number of mille seconds to wait until the wait is done     				 */
/*                     @void(*PtrFunc)(void)-> pointer to the CallBack function to be passed to the ISR              */
/*********************************************************************************************************************/
void TIMER0_voidSetIntervalASynchronousMS(u16 Copy_MILLESEC,void(*PtrFunc)(void)){
		u16 Local_COUNTS=0;
		/*calculate the required Counts to achieve a wait  in mille seconds*/
		Local_COUNTS=((Copy_MILLESEC)/(OVF_COUNTS_T0));
		Local_COUNTS*=TICK_TIME_T0_ms;
		TIMER0_voidSetIntervalASynchronous(Local_COUNTS,PtrFunc); /*setting the counts number and passing the ISR Function*/
}

/*********************************************************************************************************************/
void PWM_voidSetCompareValue(u8 Copy_u8CompareVal){
	u16 Local_PWM=0;
	Local_PWM=OVF_COUNTS_T0-((Copy_u8CompareVal*OVF_COUNTS_T0)/100);
			TIMER0_voidSetCompareValue(Local_PWM);
}
/*************************************************************************************************************/
/*************************************************************************************************************/
/*************************************************************************************************************/



/**************************************************************************************************************/
void __vector_11(void) __attribute__((signal));
void __vector_11(void){
	static u16 Local_Su8Itterator=0;
	if(Local_Su8Itterator==G_u16Counts){
		Global_T0_OVFPtrFunc();
		Local_Su8Itterator=0;
	}
	Local_Su8Itterator++;


}
void __vector_10(void) __attribute__((signal));
void __vector_10(void){
	static u16 Local_Su8Itterator=0;
	if(Local_Su8Itterator==G_u16Counts){
		Global_T0_CTCPtrFunc();
		Local_Su8Itterator=0;
	}
	Local_Su8Itterator++;


}



