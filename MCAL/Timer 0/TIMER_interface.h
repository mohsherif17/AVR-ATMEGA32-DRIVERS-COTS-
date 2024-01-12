/****************************************************************************/
/*************           file   : TIMER_interface.h             *************/
/*************           author : Muhammed Sherif               *************/
/*************           date   :  21/12/2023          		    *************/
/****************************************************************************/
#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

/************************************************************************************************************/
/* -> NAME:           @ void TIMER_voidInit(void)															*/
/* -> DESCRIBTION:    @ this function is used to initialize the timer/counter 0 PREPHIRAL				     	*/
/* 	   			   and select the mode whether {Normal time/ CTC timer/FAST PWM/ PHASE CORRECT PWM}		    */
/* -> Parameters: 	   @ void																				*/
/************************************************************************************************************/

	void TIMER0_voidInit(void);

/*********************************************************************************************************************/
/* -> NAME:           @ void TIMER_voidSetIntervalSynchronous(u16 Copy_Counts);										 */
/* -> DESCRIBTION:    @ This function is a Pooling	Function using the timer 0 PREPHIRAL 					         */
/* 	   			   	 it's used to give the timer the number of counts required to wait for before doing			 	 */
/*						 the next instruction, the program can't continue until the counts are done         		 */
/* -> Parameters: 	   @ Copy_Counts-> number of counts until the wait is done  = (PreScaler/SYS_Frequancy)*OVF_count*/
/*********************************************************************************************************************/
	void TIMER0_voidSetIntervalSynchronous(u16 Copy_Counts);
/*********************************************************************************************************************/
/* -> NAME:           @ void TIMER_voidSetIntervalASynchronous(u16 Copy_Counts,void(*PtrFunc)(void));				 */
/* -> DESCRIBTION:    @ This function is an Interrupt Function using the timer 0 PREPHIRAL 				             */
/* 	   			   	    it's used to give the timer the number of counts required to wait for before doing		 	 */
/*						the next instruction and the ISR Function to be done after the wait,                         */
/*                      the program runs Systematically as it's an interrupt function                                */
/* -> Parameters: 	   @ Copy_Counts-> number of counts until the wait is done  = (PreScaler/SYS_Frequancy)*OVF_count*/
/*                     @void(*PtrFunc)(void)-> pointer to the CallBack function to be passed to the ISR              */
/*********************************************************************************************************************/
void TIMER0_voidSetIntervalASynchronous(u16 Copy_Counts,void(*PtrFunc)(void));
/*********************************************************************************************************************/
/* -> NAME:           @ TIMER_voidSetIntervalSynchronousMS(u16 Copy_MILLESEC);   									 */
/* -> DESCRIBTION:    @ This function is a Pooling	Function using the timer 0 PREPHIRAL 					         */
/* 	   			   	    it's used to give the timer the number of counts required to wait for before doing			 */
/*						the next instruction, the program can't continue until the counts are done         		     */
/* -> Parameters: 	   @ Copy_Counts-> number of mille Seconds required to wait before the action				     */
/*********************************************************************************************************************/
void TIMER0_voidSetIntervalSynchronousMS(u16 Copy_MILLESEC);

/*********************************************************************************************************************/
/* -> NAME:           @ void TIMER_voidSetIntervalASynchronousMS(u16 Copy_MILLESEC,void(*PtrFunc)(void));			 */
/* -> DESCRIBTION:    @ This function is an Interrupt Function using the timer 0 PREPHIRAL 				             */
/* 	   			   	    it's used to give the timer the number of mille Seconds required to wait for before doing	 */
/*						the next instruction and the ISR Function to be done after the wait,                         */
/*                      the program runs Systematically as it's an interrupt function                                */
/* -> Parameters: 	   @ Copy_MILLESEC-> number of mille seconds to wait until the wait is done     				 */
/*                     @void(*PtrFunc)(void)-> pointer to the CallBack function to be passed to the ISR              */
/*********************************************************************************************************************/
void TIMER0_voidSetIntervalASynchronousMS(u16 Copy_MILLESEC,void(*PtrFunc)(void));
/************************************************************************************************************/
/* -> NAME:           @ void TIMER_voidSetCompareValue(u8 Copy_u8CompareVal)								*/
/* -> DESCRIBTION:    @ this function is used to The compare value in the OCR0 Register					    */
/* -> Parameters: 	  @ Copy_u8CompareVal the value to compare with for the OCR register 					*/
/************************************************************************************************************/
void TIMER0_voidSetCompareValue(u8 Copy_u8CompareVal);

/************************************************************************************************************/
/* -> NAME:           @ void TIMER_voidStop(void)															*/
/* -> DESCRIBTION:    @ this function is used to STOP the timer/counter 0 PREPHIRAL	(Clearing the PreScaler)*/
/* -> Parameters: 	  @ void																				*/
/************************************************************************************************************/
void TIMER0_voidStop(void);
/************************************************************************************************************/
/* -> NAME:           @ void TIMER_voidSetPRELOADValue(u8 Copy_u8Value)										*/
/* -> DESCRIBTION:    @ this function is used to The PreLoad value For CTC Mode	in timer 0				    */
/* -> Parameters: 	  @ Copy_u8Value the value Of CTC MODE		   						 					*/
/************************************************************************************************************/
void TIMER0_voidSetPRELOADValue(u8 Copy_u8Value);

/************************************************************************************************************/
/* -> NAME:           @ void TIMER_voidSTART(void)															*/
/* -> DESCRIBTION:    @ this function is used to START the timer/counter 0 PREPHIRAL (Setting the PreScaler)*/
/* -> Parameters: 	  @ void																				*/
/************************************************************************************************************/
void TIMER0_voidSTART(void);

void PWM_voidSetCompareValue(u8 Copy_u8CompareVal);

#endif /* TIMER_INTERFACE_H_ */
