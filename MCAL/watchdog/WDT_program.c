/***************************************************************************/
/************* AUTHOR: @ Muhammed Sherif Attia *****************************/
/************* FILE  : @ WDT_program.c         *****************************/
/************* breif : @ The program.c file for 		********************/
/*************           the Watch Dog Timer prephilral of atmega32 ********/
/************* DATE  : @ 31/12/2023 ****************************************/
/***************************************************************************/

/***********************************includes*****************************************/
/***** standard libs *****/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/**** GIE FILE ****/
#include "GIE_interface.h"
/**** WDT FILE ****/

#include "WDT_config.h"
#include "WDT_interface.h"
#include "WDT_private.h"
#include "WDT_register.h"


/***********************************************************************************/
/***************************Functions implementation********************************/

/*********************************************************/
/*-> NAME: 		@ void WDT_voidEnable(void)		    	 */
/*-> breif:		@ ENABLES The WATCHDOG TIMER 			 */
/*-> Prameters: @ void							       	 */
/*********************************************************/
void WDT_voidEnable(void){
	/*Enable the WDT*/
	SET_BIT(WDTCR,WDT_WDE);

}

/*******************************/
/*********************************************************/
/*-> NAME: 		@ void WDT_voidDisable(void)		     */
/*-> breif:		@ DISABLES The WATCHDOG TIMER 			 */
/*-> Prameters: @ void							       	 */
/*********************************************************/
void WDT_voidDisable(void){
	/*Disable GIE*/
	GIE_voidDisable();
	/*Disable WDT*/
	WDTCR=(1<<WDT_Dis)|(1<<WDT_EN);
	WDTCR=0x00;
	/*Enable the GIE Again*/
	GIE_voidEnable();

}

/*******************************/
/*********************************************************/
/*-> NAME: 		@ void WDT_voidSleep(u8 Copy_u8Time)     */
/*-> breif:		@ set the WDT Timer						 */
/*-> Prameters: @ u8 Copy_u8Time				       	 */
/*********************************************************/
void WDT_voidSleep(u8 Copy_u8Time){
/* set the WDT Timer*/
WDTCR &=0b11111000;
WDTCR |=Copy_u8Time;

}
