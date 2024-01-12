/***************************************************************************/
/************* AUTHOR: @ Muhammed Sherif Attia *****************************/
/************* FILE  : @ WDT_interface.h       *****************************/
/************* breif : @ The interface.h file for 		********************/
/*************           the Watch Dog Timer prephilral of atmega32 ********/
/************* DATE  : @ 31/12/2023 ****************************************/
/***************************************************************************/

#ifndef WDT_INTERFACE_H_
#define WDT_INTERFACE_H_
/****************includes*********************/
/*********************************************/

/****************defines*********************/
#define  TIME_16ms			0
#define  TIME_32ms			1
#define  TIME_65ms			2
#define  TIME_130ms			3
#define  TIME_260ms			4
#define  TIME_520ms			5
#define  TIME_1s			6
#define  TIME_2s			7
/*********************************************/



/*******FUNCTIONS PROTOTYPES********/
/*********************************************************/
/*-> NAME: 		@ void WDT_voidEnable(void)		    	 */
/*-> breif:		@ ENABLES The WATCHDOG TIMER 			 */
/*-> Prameters: @ void							       	 */
/*********************************************************/
void WDT_voidEnable(void);

/*********************************************************/
/*-> NAME: 		@ void WDT_voidDisable(void)		     */
/*-> breif:		@ DISABLES The WATCHDOG TIMER 			 */
/*-> Prameters: @ void							       	 */
/*********************************************************/
void WDT_voidDisable(void);

/*********************************************************/
/*-> NAME: 		@ void WDT_voidSleep(u8 Copy_u8Time)     */
/*-> breif:		@ set the WDT Timer						 */
/*-> Prameters: @ u8 Copy_u8Time				       	 */
/*********************************************************/
void WDT_voidSleep(u8 Copy_u8Time);


#endif /* WDT_INTERFACE_H_ */
