/***************************************************************************/
/************* AUTHOR: @ Muhammed Sherif Attia *****************************/
/************* FILE  : @ TIMER1_program.c      *****************************/
/************* breif : @ The TIMER1_program.c file for 	********************/
/*************           Timer 1 prepheral of atmega32 *********************/
/************* DATE  : @ 31/12/2023 ****************************************/
/***************************************************************************/
#ifndef TIMER1_INTERFACE_H_
#define TIMER1_INTERFACE_H_


/***********************************************************************************************************/

/************************************************************************************************************/
/* -> NAME:           @ void TIMER1_voidInit(void)															*/
/* -> DESCRIBTION:    @ this function is used to initialize the timer/counter PREPHIRAL				     	*/
/* 	   			   and select the mode whether {Normal time/ CTC timer/FAST PWM/ PHASE CORRECT PWM}		    */
/* -> Parameters: 	   @ void																				*/
/************************************************************************************************************/
void TIMER1_voidInit(void);

/************************************************************************************************************/
/* -> NAME:           @ void TIMER1_voidSTART(void)															*/
/* -> DESCRIBTION:    @ this function is used to START the timer/counter PREPHIRAL	(Setting the PreScaler)	*/
/* -> Parameters: 	  @ void																				*/
/************************************************************************************************************/
void TIMER1_voidSTART(void);
/************************************************************************************************************/
/* -> NAME:           @ void TIMER1_voidStop(void)															*/
/* -> DESCRIBTION:    @ this function is used to STOP the timer/counter PREPHIRAL	(Clearing the PreScaler)*/
/* -> Parameters: 	  @ void																				*/
/************************************************************************************************************/
void TIMER1_voidStop(void);
/*********************************************************************************************************************/
/* -> NAME:           @ void TIMER1_voidSetIntervalSynchronous(u16 Copy_Counts);									 */
/* -> DESCRIBTION:    @ This function is a Pooling	Function using the timer 1 PREPHIRAL 					         */
/* 	   			   	 it's used to give the timer the number of counts required to wait for before doing			 	 */
/*						 the next instruction, the program can't continue until the counts are done         		 */
/* -> Parameters: 	   @ Copy_Counts-> number of counts until the wait is done  = (PreScaler/SYS_Frequancy)*OVF_count*/
/*********************************************************************************************************************/

void TIMER1_voidSetIntervalSynchronous(u16 Copy_Counts);

/*********************************************************************************************************************/
/* -> NAME:           @ void TIMER1_voidSetIntervalASynchronous(u16 Copy_Counts,void(*PtrFunc)(void));				 */
/* -> DESCRIBTION:    @ This function is an Interrupt Function using the timer PREPHIRAL 				             */
/* 	   			   	    it's used to give the timer the number of counts required to wait for before doing		 	 */
/*						the next instruction and the ISR Function to be done after the wait,                         */
/*                      the program runs Systematically as it's an interrupt function                                */
/* -> Parameters: 	   @ Copy_Counts-> number of counts until the wait is done  = (PreScaler/SYS_Frequancy)*OVF_count*/
/*                     @void(*PtrFunc)(void)-> pointer to the CallBack function to be passed to the ISR              */
/*********************************************************************************************************************/
void TIMER1_voidSetIntervalASynchronous(u16 Copy_Counts,void(*PtrFunc)(void));
/*********************************************************************************************************************/
/* -> NAME:           @ TIMER1_voidSetIntervalSynchronousMS(u16 Copy_MILLESEC);   									 */
/* -> DESCRIBTION:    @ This function is a Pooling	Function using the timer PREPHIRAL 					             */
/* 	   			   	    it's used to give the timer the number of counts required to wait for before doing			 */
/*						the next instruction, the program can't continue until the counts are done         		     */
/* -> Parameters: 	   @ Copy_Counts-> number of mille Seconds required to wait before the action				     */
/*********************************************************************************************************************/

void TIMER1_voidSetIntervalSynchronousMS(u16 Copy_MILLESEC);
/*********************************************************************************************************************/
/* -> NAME:           @ void TIMER1_voidSetIntervalASynchronousMS(u16 Copy_MILLESEC,void(*PtrFunc)(void));			 */
/* -> DESCRIBTION:    @ This function is an Interrupt Function using the timer PREPHIRAL 				             */
/* 	   			   	    it's used to give the timer the number of mille Seconds required to wait for before doing	 */
/*						the next instruction and the ISR Function to be done after the wait,                         */
/*                      the program runs Systematically as it's an interrupt function                                */
/* -> Parameters: 	   @ Copy_MILLESEC-> number of mille seconds to wait until the wait is done     				 */
/*                     @void(*PtrFunc)(void)-> pointer to the CallBack function to be passed to the ISR              */
/*********************************************************************************************************************/

void TIMER1_voidSetIntervalASynchronousMS(u16 Copy_MILLESEC,void(*PtrFunc)(void)); 
/************************************************************************************************************/
/* -> NAME:           @ void TIMER1_voidSetCompareValue(u8 Copy_u8CompareVal)								*/
/* -> DESCRIBTION:    @ this function is used to SET The compare value in the OCR1A Register				*/
/* -> Parameters: 	  @ Copy_u8CompareVal the value to compare with for the OCR1A register 					*/
/************************************************************************************************************/

void TIMER1_voidSetCompareValueOCR1A(u8 Copy_u8CompareVal);
/************************************************************************************************************/
/* -> NAME:           @ void TIMER1_voidSetCompareValue(u8 Copy_u8CompareVal)								*/
/* -> DESCRIBTION:    @ this function is used to SET The compare value in the OCR1B Register				*/
/* -> Parameters: 	  @ Copy_u8CompareVal the value to compare with for the OCR1B register 					*/
/************************************************************************************************************/

void TIMER1_voidSetCompareValueOCR1B(u8 Copy_u8CompareVal);
/************************************************************************************************************/
/* -> NAME:           @ void TIMER1_voidSetPRELOADValue(u8 Copy_u8Value)									*/
/* -> DESCRIBTION:    @ this function is used to set The PreLoad value For CTC Mode							*/
/* -> Parameters: 	  @ Copy_u8Value the value Of CTC MODE		   						 					*/
/************************************************************************************************************/
void TIMER1_voidSetPRELOADValue(u8 Copy_u8Value);
/************************************************************************************************************/
/* -> NAME:           @ void TIMER1_voidSetICR(u16 Copy_u16IcrVal);											*/
/* -> DESCRIBTION:    @ this function is used to SET The input capture unit value						    */
/* -> Parameters: 	  @ Copy_u16IcrVal the value Of input capture unit					 					*/
/************************************************************************************************************/
void TIMER1_voidSetICR(u16 Copy_u16IcrVal);
#endif /* TIMER_INTERFACE_H_ */
