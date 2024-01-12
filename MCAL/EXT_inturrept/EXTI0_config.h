/***************************************************************************/
/************* AUTHOR: @ Muhammed Sherif Attia *****************************/
/************* FILE  : @ EXTI0_config.h        *****************************/
/************* breif : @ The config.h file for	 		********************/
/*************           the External interrupt prephilral of atmega32 *****/
/************* DATE  : @ 31/12/2023 ****************************************/
/***************************************************************************/

#ifndef EXTI0_CONFIG_H_
#define EXTI0_CONFIG_H_
/***********************************************************************
select the sense mode of the external interrupt
									options:
												1- EXTI0_LowLevel   
												2- EXTI0_AnyChange	
												3- EXTI0_FallingEdge
												4- EXTI0_RisingEdge	
***********************************************************************/

#define  EXTI0_Sense      EXTI0_FallingEdge

/*********************************************************************/

#endif /* EXTI0_CONFIG_H_ */
