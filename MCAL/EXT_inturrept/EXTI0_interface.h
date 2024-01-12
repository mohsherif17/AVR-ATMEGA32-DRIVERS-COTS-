/***************************************************************************/
/************* AUTHOR: @ Muhammed Sherif Attia *****************************/
/************* FILE  : @ EXTI0_interface.h     *****************************/
/************* breif : @ The interface.h file for 		********************/
/*************           the External interrupt prephilral of atmega32 *****/
/************* DATE  : @ 31/12/2023 ****************************************/
/***************************************************************************/


#ifndef EXTI0_INTERFACE_H_
#define EXTI0_INTERFACE_H_
/*********************************************************************************************************/

/******************************** Definations ********************************/
/**** sense control modes ****/
#define    EXTI0_LowLevel             1
#define    EXTI0_AnyChange			  2
#define    EXTI0_FallingEdge 		  3
#define    EXTI0_RisingEdge			  4

/*********************************************************************************************************/

/******************************** Function prototypes ********************************/
/********************************************************************/
/*-> NAME: 		@ void EXTI0_voidInit(void);		  			    */
/*-> breif:		@ this function is used to intialize   			    */
/*				  the external intterupt mode and enable interrupt  */
/*				@ this function return void							*/
/*-> Prameters: @ void							       	 			*/
/********************************************************************/
void EXTI0_voidInit(void);

/********************************************************************/
/*-> NAME: 		@ void EXTI0_voidEnable(void);		  			    */
/*-> breif:		@ this function is used to enable external intterup */
/*				@ this function return void							*/
/*-> Prameters: @ void							       	 			*/
/********************************************************************/
void EXTI0_voidEnable(void);

/********************************************************************/
/*-> NAME: 		@ void EXTI0_voidDisable(void);		  			    */
/*-> breif:		@ this function is used to disable external intterup*/
/*				@ this function return void							*/
/*-> Prameters: @ void							       	 			*/
/********************************************************************/
void EXTI0_voidDisable(void);

/*********************************************************************************/
/*-> NAME: 		@ void EXTI0_voidSetSenseControl(u8 Copy_u8Sense);  			 */
/*-> breif:		@ this function is used to Set sense control in post build config*/
/*				@ this function return void									   	 */
/*-> Prameters: @ u8 Copy_u8Sense -> the selected sense control mode 			 */
/*********************************************************************************/
void EXTI0_voidSetSenseControl(u8 Copy_u8Sense);


/*********************************************************************************************/
/*-> NAME: 		@ void EXTI0_voidSetSenseControl(u8 Copy_u8Sense);  			 			 */
/*-> breif:		@ this function is used to Set sense control in post build config	  	 	 */
/*				@ this function return void									   	 	         */
/*-> Prameters: @ void (*Copy_pvCallBack)(void) -> pointer to callback function  			 */
/*												   used to set the ISR for external interrupt*/
/*********************************************************************************************/
void EXTI0_voidSetCallBack(void (*Copy_pvCallBack)(void));

#endif /* EXTI0_INTERFACE_H_ */
