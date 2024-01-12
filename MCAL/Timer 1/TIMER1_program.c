/***************************************************************************/
/************* AUTHOR: @ Muhammed Sherif Attia *****************************/
/************* FILE  : @ TIMER1_program.c      *****************************/
/************* breif : @ The TIMER1_program.c file for 	********************/
/*************           Timer 1 prepheral of atmega32 *********************/
/************* DATE  : @ 31/12/2023 ****************************************/
/***************************************************************************/
/******************includes******************/
#include "STD_TYPES.h"
#include"BIT_MATH.h"
#include "TIMER_config.h"
#include"TIMER_interface.h"
#include "TIMER_private.h"
#include "TIMER_register.h"

/*********Global Variables Declaration*********/

static void(*Global_T1_OVFPtrFunc)(void)=NULL;		/*Global Pointer to the call back function for OVF mode  FOR T1*/
static void(*Global_T1_CTCPtrFunc)(void)=NULL;		/*Global Pointer to the call back function for CTC mode  FOR T1*/
u16 G_u16Counts;							     /*Global variable to pass the OVF counts to the ISR*/

/**********Functions implementations**********/

/************************************************************************************************************/
/* -> NAME:           @ void TIMER1_voidInit(void)															*/
/* -> DESCRIBTION:    @ this function is used to initialize the timer/counter PREPHIRAL				     	*/
/* 	   			   and select the mode whether {Normal time/ CTC timer/FAST PWM/ PHASE CORRECT PWM}		    */
/* -> Parameters: 	   @ void																				*/
/************************************************************************************************************/
void TIMER1_voidInit(void){
#if(TIMER_COUNTER1_MODE==TIMER)
		#if(TIMER1_MODE==TIMER1_NORMAL)
			CLR_BIT(TCCR1A,TCCR1A_WGM10);
			CLR_BIT(TCCR1A,TCCR1A_WGM11);
			CLR_BIT(TCCR1B,TCCR1B_WGM12);
			CLR_BIT(TCCR1B,TCCR1B_WGM13);
		#elif(TIMER1_MODE==TIMER1_PWM_PC8BIT)
			SET_BIT(TCCR1A,TCCR1A_WGM10);
			CLR_BIT(TCCR1A,TCCR1A_WGM11);
			CLR_BIT(TCCR1B,TCCR1B_WGM12);
			CLR_BIT(TCCR1B,TCCR1B_WGM13);
		#elif(TIMER1_MODE==TIMER1_PWM_PC9BIT)
			CLR_BIT(TCCR1A,TCCR1A_WGM10);
			SET_BIT(TCCR1A,TCCR1A_WGM11);
			CLR_BIT(TCCR1B,TCCR1B_WGM12);
			CLR_BIT(TCCR1B,TCCR1B_WGM13);
		#elif(TIMER1_MODE==TIMER1_PWM_PC10BIT)
			SET_BIT(TCCR1A,TCCR1A_WGM10);
			SET_BIT(TCCR1A,TCCR1A_WGM11);
			CLR_BIT(TCCR1B,TCCR1B_WGM12);
			CLR_BIT(TCCR1B,TCCR1B_WGM13);
		#elif(TIMER1_MODE==TIMER1_CTC_OCR1A)
			CLR_BIT(TCCR1A,TCCR1A_WGM10);
			CLR_BIT(TCCR1A,TCCR1A_WGM11);
			SET_BIT(TCCR1B,TCCR1B_WGM12);
			CLR_BIT(TCCR1B,TCCR1B_WGM13);
		#elif(TIMER1_MODE==TIMER1_FASTPWM_8BIT)
			SET_BIT(TCCR1A,TCCR1A_WGM10);
			CLR_BIT(TCCR1A,TCCR1A_WGM11);
			SET_BIT(TCCR1B,TCCR1B_WGM12);
			CLR_BIT(TCCR1B,TCCR1B_WGM13);
		#elif(TIMER1_MODE==TIMER1_FASTPWM_9BIT)
			CLR_BIT(TCCR1A,TCCR1A_WGM10);
			SET_BIT(TCCR1A,TCCR1A_WGM11);
			SET_BIT(TCCR1B,TCCR1B_WGM12);
			CLR_BIT(TCCR1B,TCCR1B_WGM13);
		#elif(TIMER1_MODE==TIMER1_FASTPWM_10BIT)
			SET_BIT(TCCR1A,TCCR1A_WGM10);
			SET_BIT(TCCR1A,TCCR1A_WGM11);
			SET_BIT(TCCR1B,TCCR1B_WGM12);
			CLR_BIT(TCCR1B,TCCR1B_WGM13);
		#elif(TIMER1_MODE==TIMER1_PWM_PFC_ICR1)
			CLR_BIT(TCCR1A,TCCR1A_WGM10);
			CLR_BIT(TCCR1A,TCCR1A_WGM11);
			CLR_BIT(TCCR1B,TCCR1B_WGM12);
			SET_BIT(TCCR1B,TCCR1B_WGM13);
		#elif(TIMER1_MODE==TIMER1_PWM_PFC_OCR1A)
			SET_BIT(TCCR1A,TCCR1A_WGM10);
			CLR_BIT(TCCR1A,TCCR1A_WGM11);
			CLR_BIT(TCCR1B,TCCR1B_WGM12);
			SET_BIT(TCCR1B,TCCR1B_WGM13);
		#elif(TIMER1_MODE==TIMER1_PWM_PC_ICR1)
			CLR_BIT(TCCR1A,TCCR1A_WGM10);
			SET_BIT(TCCR1A,TCCR1A_WGM11);
			CLR_BIT(TCCR1B,TCCR1B_WGM12);
			SET_BIT(TCCR1B,TCCR1B_WGM13);
		#elif(TIMER1_MODE==TIMER1_PWM_PC_OCR1A)
			SET_BIT(TCCR1A,TCCR1A_WGM10);
			SET_BIT(TCCR1A,TCCR1A_WGM11);
			CLR_BIT(TCCR1B,TCCR1B_WGM12);
			SET_BIT(TCCR1B,TCCR1B_WGM13);
		#elif(TIMER1_MODE==TIMER1_CTC_ICR1)
			CLR_BIT(TCCR1A,TCCR1A_WGM10);
			CLR_BIT(TCCR1A,TCCR1A_WGM11);
			SET_BIT(TCCR1B,TCCR1B_WGM12);
			SET_BIT(TCCR1B,TCCR1B_WGM13);
		#elif(TIMER1_MODE==TIMER1_FPWM_ICR1)
			CLR_BIT(TCCR1A,TCCR1A_WGM10);
			SET_BIT(TCCR1A,TCCR1A_WGM11);
			SET_BIT(TCCR1B,TCCR1B_WGM12);
			SET_BIT(TCCR1B,TCCR1B_WGM13);
		#elif(TIMER1_MODE==TIMER1_FPWM_OCR1A)
			SET_BIT(TCCR1A,TCCR1A_WGM10);
			SET_BIT(TCCR1A,TCCR1A_WGM11);
			SET_BIT(TCCR1B,TCCR1B_WGM12);
			SET_BIT(TCCR1B,TCCR1B_WGM13);
		#endif

#elif (TIMER_COUNTER1_MODE==COUNTER)
		#if(COUNTER1_SENSE==RISING_EDGE)
			SET_BIT(TCCR1B,TCCR1B_CS10);
			SET_BIT(TCCR1B,TCCR1B_CS11);
			SET_BIT(TCCR1B,TCCR1B_CS12);
		#elif(COUNTER1_SENSE==FALLING_EDGE)
			CLR_BIT(TCCR1B,TCCR1B_CS10);
			SET_BIT(TCCR1B,TCCR1B_CS11);
			SET_BIT(TCCR1B,TCCR1B_CS12);
		#endif
#endif
}
/*************************************************************************************************************/
/************************************************************************************************************/
/* -> NAME:           @ void TIMER1_voidSTART(void)															*/
/* -> DESCRIBTION:    @ this function is used to START the timer/counter PREPHIRAL	(Setting the PreScaler)	*/
/* -> Parameters: 	  @ void																				*/
/************************************************************************************************************/
void TIMER1_voidSTART(void){
	TCCR1B &= 0xf8;
	TCCR1B |=TIMER1_PRESCALER;
}
/************************************************************************************************************/
/* -> NAME:           @ void TIMER1_voidStop(void)															*/
/* -> DESCRIBTION:    @ this function is used to STOP the timer/counter PREPHIRAL	(Clearing the PreScaler)*/
/* -> Parameters: 	  @ void																				*/
/************************************************************************************************************/
void TIMER1_voidStop(void){
	CLR_BIT(TCCR1B,TCCR1B_CS10);
	CLR_BIT(TCCR1B,TCCR1B_CS11);
	CLR_BIT(TCCR1B,TCCR1B_CS12);

}

/*********************************************************************************************************************/
/* -> NAME:           @ void TIMER1_voidSetIntervalSynchronous(u16 Copy_Counts);									 */
/* -> DESCRIBTION:    @ This function is a Pooling	Function using the timer 1 PREPHIRAL 					         */
/* 	   			   	 it's used to give the timer the number of counts required to wait for before doing			 	 */
/*						 the next instruction, the program can't continue until the counts are done         		 */
/* -> Parameters: 	   @ Copy_Counts-> number of counts until the wait is done  = (PreScaler/SYS_Frequancy)*OVF_count*/
/*********************************************************************************************************************/
void TIMER1_voidSetIntervalSynchronous(u16 Copy_Counts){

	for(u8 Local_u8Counter = 0;Local_u8Counter < Copy_Counts;Local_u8Counter++){
	while(GET_BIT(TIFR,TIFR_TOV1)!=1);
	SET_BIT(TIFR,TIFR_TOV1);
	}
}
/*********************************************************************************************************************/
/* -> NAME:           @ void TIMER1_voidSetIntervalASynchronous(u16 Copy_Counts,void(*PtrFunc)(void));				 */
/* -> DESCRIBTION:    @ This function is an Interrupt Function using the timer PREPHIRAL 				             */
/* 	   			   	    it's used to give the timer the number of counts required to wait for before doing		 	 */
/*						the next instruction and the ISR Function to be done after the wait,                         */
/*                      the program runs Systematically as it's an interrupt function                                */
/* -> Parameters: 	   @ Copy_Counts-> number of counts until the wait is done  = (PreScaler/SYS_Frequancy)*OVF_count*/
/*                     @void(*PtrFunc)(void)-> pointer to the CallBack function to be passed to the ISR              */
/*********************************************************************************************************************/
void TIMER1_voidSetIntervalASynchronous(u16 Copy_Counts,void(*PtrFunc)(void)){
	#if(TIMER1_MODE==TIMER1_NORMAL)
	SET_BIT(TMISK,TMISK_TOIE1);
	Global_T1_OVFPtrFunc=PtrFunc;
	G_u16Counts=Copy_Counts;
#elif((TIMER1_MODE==TIMER1_CTC_OCR1A)||((TIMER1_MODE==TIMER1_PWM_PC_OCR1A)))
	SET_BIT(TMISK,TMISK_OCIE1A);
	Global_T1_CTCPtrFunc=PtrFunc;
	G_u16Counts=Copy_Counts;
#endif
}
/*********************************************************************************************************************/
/* -> NAME:           @ TIMER1_voidSetIntervalSynchronousMS(u16 Copy_MILLESEC);   									 */
/* -> DESCRIBTION:    @ This function is a Pooling	Function using the timer PREPHIRAL 					             */
/* 	   			   	    it's used to give the timer the number of counts required to wait for before doing			 */
/*						the next instruction, the program can't continue until the counts are done         		     */
/* -> Parameters: 	   @ Copy_Counts-> number of mille Seconds required to wait before the action				     */
/*********************************************************************************************************************/

void TIMER1_voidSetIntervalSynchronousMS(u16 Copy_MILLESEC){
			u16 Local_COUNTS=0;
			/*calculate the required Counts to achieve a wait  in mille seconds*/
			Local_COUNTS=((Copy_MILLESEC)/(OVF_COUNTS_T0));
			Local_COUNTS*=TICK_TIME_T1_ms;
	TIMER1_voidSetIntervalSynchronous(Local_COUNTS);	/*setting the counts number*/
}
/*********************************************************************************************************************/
/* -> NAME:           @ void TIMER1_voidSetIntervalASynchronousMS(u16 Copy_MILLESEC,void(*PtrFunc)(void));			 */
/* -> DESCRIBTION:    @ This function is an Interrupt Function using the timer PREPHIRAL 				             */
/* 	   			   	    it's used to give the timer the number of mille Seconds required to wait for before doing	 */
/*						the next instruction and the ISR Function to be done after the wait,                         */
/*                      the program runs Systematically as it's an interrupt function                                */
/* -> Parameters: 	   @ Copy_MILLESEC-> number of mille seconds to wait until the wait is done     				 */
/*                     @void(*PtrFunc)(void)-> pointer to the CallBack function to be passed to the ISR              */
/*********************************************************************************************************************/

void TIMER1_voidSetIntervalASynchronousMS(u16 Copy_MILLESEC,void(*PtrFunc)(void)){
		u16 Local_COUNTS=0;
		/*calculate the required Counts to achieve a wait  in mille seconds*/
		Local_COUNTS=((Copy_MILLESEC)/(OVF_COUNTS_T1));
		Local_COUNTS*=TICK_TIME_T1_ms;
		TIMER1_voidSetIntervalASynchronous(Local_COUNTS,PtrFunc); /*setting the counts number and passing the ISR Function*/
}/************************************************************************************************************/
/* -> NAME:           @ void TIMER1_voidSetCompareValue(u8 Copy_u8CompareVal)								*/
/* -> DESCRIBTION:    @ this function is used to The compare value in the OCR1A Register					    */
/* -> Parameters: 	  @ Copy_u8CompareVal the value to compare with for the OCR1A register 					*/
/************************************************************************************************************/

void TIMER1_voidSetCompareValueOCR1A(u8 Copy_u8CompareVal){
	OCR1A=Copy_u8CompareVal;					/*SET the OCR reg by the value of counts to set the top value for CTC mode*/
}
/************************************************************************************************************/
/* -> NAME:           @ void TIMER1_voidSetCompareValue(u8 Copy_u8CompareVal)								*/
/* -> DESCRIBTION:    @ this function is used to The compare value in the OCR1B Register					    */
/* -> Parameters: 	  @ Copy_u8CompareVal the value to compare with for the OCR1B register 					*/
/************************************************************************************************************/

void TIMER1_voidSetCompareValueOCR1B(u8 Copy_u8CompareVal){
	OCR1B=Copy_u8CompareVal;					/*SET the OCR reg by the value of counts to set the top value for CTC mode*/
}
/************************************************************************************************************/
/* -> NAME:           @ void TIMER1_voidSetPRELOADValue(u8 Copy_u8Value)										*/
/* -> DESCRIBTION:    @ this function is used to The PreLoad value For CTC Mode							    */
/* -> Parameters: 	  @ Copy_u8Value the value Of CTC MODE		   						 					*/
/************************************************************************************************************/
void TIMER1_voidSetPRELOADValue(u8 Copy_u8Value){
	/**/
	TCNT1=Copy_u8Value;
}
void TIMER1_voidSetICR(u16 Copy_u16IcrVal)
{
	ICR1 = Copy_u16IcrVal;
}
/**************************************************************************************************************/
/**************************************************************************************************************/
/*ISR FOR TIMER 1 OVF MODE*/
void __vector_9(void) __attribute__((signal));
void __vector_9(void){
	static u16 Local_Su8Itterator=0;
	if(Local_Su8Itterator==G_u16Counts){
		Global_T1_OVFPtrFunc();
		Local_Su8Itterator=0;
	}
	Local_Su8Itterator++;


}
/*ISR FOR TIMER 1 CTC OCR1B MODE*/
void __vector_8(void) __attribute__((signal));
void __vector_8(void){
	static u16 Local_Su8Itterator=0;
	if(Local_Su8Itterator==G_u16Counts){
		Global_T1_CTCPtrFunc();
		Local_Su8Itterator=0;
	}
	Local_Su8Itterator++;


}
/*ISR FOR TIMER 1 CTC OCR1A MODE*/
void __vector_7(void) __attribute__((signal));
void __vector_7(void){
	static u16 Local_Su8Itterator=0;
	if(Local_Su8Itterator==G_u16Counts){
		Global_T1_CTCPtrFunc();
		Local_Su8Itterator=0;
	}
	Local_Su8Itterator++;


}
/*ISR FOR TIMER 1 CAPTURE EVENT MODE*/
void __vector_6(void) __attribute__((signal));
void __vector_6(void){
	


}

/**************************************************************************************************************/
/**************************************************************************************************************/
/**************************************************************************************************************/
/**************************************************************************************************************/