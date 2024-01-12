/***************************************************************************/
/************* AUTHOR: @ Muhammed Sherif Attia *****************************/
/************* FILE  : @ EXTI0_program.c 	   *****************************/
/************* breif : @ The program.c file for 		********************/
/*************           the External interrupt prephilral of atmega32 *****/
/************* DATE  : @ 31/12/2023 ****************************************/
/***************************************************************************/


/*********************************** includes *****************************************/
/***** standard libs *****/
#include"STD_TYPES.h"
#include"BIT_MATH.h"
/***** EXTI0 files *****/
#include"EXTI0_config.h"
#include"EXTI0_interface.h"
#include"EXTI0_private.h"
#include"EXTI0_register.h"

/*********************************** GLOBAL VARIABLES *****************************************/

static void (*EXTI0_PvCallBAK)(void);  /*Global Static Void pointer to a function ro recive CALLBACK function of the ISR */

/****************************************************************************************************/
/***********************************Functions implementation*****************************************/

/********************************************************************/
/*-> NAME: 		@ void EXTI0_voidInit(void);		  			    */
/*-> breif:		@ this function is used to intialize   			    */
/*				  the external intterupt mode and enable interrupt  */
/*				@ this function return void							*/
/*-> Prameters: @ void							       	 			*/
/********************************************************************/
void EXTI0_voidInit(void){
	/* Enabling Sense Control */
#if(EXTI0_Sense==EXTI0_LowLevel)
	CLR_BIT(MCUCR,EXTI_ISC01);
	CLR_BIT(MCUCR,EXTI_ISC00);
#elif(EXTI0_Sense==EXTI0_AnyChange)
	CLR_BIT(MCUCR,EXTI_ISC01);
	SET_BIT(MCUCR,EXTI_ISC00);
#elif(EXTI0_Sense==EXTI0_FallingEdge)
	SET_BIT(MCUCR,EXTI_ISC01);
	CLR_BIT(MCUCR,EXTI_ISC00);
#elif(EXTI0_Sense==EXTI0_RisingEdge)
	SET_BIT(MCUCR,EXTI_ISC01);
	SET_BIT(MCUCR,EXTI_ISC00);
#endif
	/*  Enable EXTI0  */
	SET_BIT(GICR,6);
}
/******************************************************************************************************************************************************************************************************************/

/********************************************************************/
/*-> NAME: 		@ void EXTI0_voidEnable(void);		  			    */
/*-> breif:		@ this function is used to enable external intterup */
/*				@ this function return void							*/
/*-> Prameters: @ void							       	 			*/
/********************************************************************/
void EXTI0_voidEnable(void){
	SET_BIT(GICR,EXTI_INT0);    /*SET BIT no 6 in GICR REgister to Enable EXTI0 */
}
/******************************************************************************************************************************************************************************************************************/

/********************************************************************/
/*-> NAME: 		@ void EXTI0_voidDisable(void);		  			    */
/*-> breif:		@ this function is used to disable external intterup*/
/*				@ this function return void							*/
/*-> Prameters: @ void							       	 			*/
/********************************************************************/
void EXTI0_voidDisable(void){
	CLR_BIT(GICR,EXTI_INT0);		/*CLER BIT no 6 in GICR REgister to Disable EXTI0 */
}
/******************************************************************************************************************************************************************************************************************/

/*********************************************************************************/
/*-> NAME: 		@ void EXTI0_voidSetSenseControl(u8 Copy_u8Sense);  			 */
/*-> breif:		@ this function is used to Set sense control in post build config*/
/*				@ this function return void									   	 */
/*-> Prameters: @ u8 Copy_u8Sense -> the selected sense control mode 			 */
/*********************************************************************************/
void EXTI0_voidSetSenseControl(u8 Copy_u8Sense){
/*check on the required sense control */
switch(Copy_u8Sense){
			case EXTI0_LowLevel   :CLR_BIT(MCUCR,EXTI_ISC01);CLR_BIT(MCUCR,EXTI_ISC00);break;     /*ser sense control as Low Level */
			case EXTI0_AnyChange  :CLR_BIT(MCUCR,EXTI_ISC01);SET_BIT(MCUCR,EXTI_ISC00);break;     /*ser sense control as any Change*/
			case EXTI0_FallingEdge:SET_BIT(MCUCR,EXTI_ISC01);CLR_BIT(MCUCR,EXTI_ISC00);break;     /*ser sense control as falling edge*/
			case EXTI0_RisingEdge :SET_BIT(MCUCR,EXTI_ISC01);SET_BIT(MCUCR,EXTI_ISC00);break;     /*ser sense control as rising edge*/
}
}
/******************************************************************************************************************************************************************************************************************/

/*********************************************************************************************/
/*-> NAME: 		@ void EXTI0_voidSetCallBack(void (*Copy_pvCallBack)(void))					 */
/*-> breif:		@ this function is used to Set sense control in post build config	  	 	 */
/*				@ this function return void									   	 	         */
/*-> Prameters: @ void (*Copy_pvCallBack)(void) -> pointer to callback function  			 */
/*												   used to set the ISR for external interrupt*/
/*********************************************************************************************/
void EXTI0_voidSetCallBack(void (*Copy_pvCallBack)(void)){
	EXTI0_PvCallBAK=Copy_pvCallBack;					/*passing the call back function address to the global variable*/
}
/******************************************************************************************************************************************************************************************************************/


/***** The ISR Vector for External interrupt 0 *****/
void __vector_1(void) __attribute__((signal));
void __vector_1(void){
if(EXTI0_PvCallBAK!=NULL){
	EXTI0_PvCallBAK();
}
else{
	asm("NOP");
}
}
/******************************************************************************************************************************************************************************************************************/
/******************************************************************************************************************************************************************************************************************/
/******************************************************************************************************************************************************************************************************************/
