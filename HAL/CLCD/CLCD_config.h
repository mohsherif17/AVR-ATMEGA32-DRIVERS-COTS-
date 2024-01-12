/***************************************************************************/
/************* AUTHOR: @ Muhammed Sherif Attia *****************************/
/************* FILE  : @ CLCD_config.h         *****************************/
/************* breif : @ driver for controlling 		********************/
/*************            CHARACTER LCD with ATMEG32    ********************/
/************* DATE  : @ 31/12/2023 ****************************************/
/***************************************************************************/

#ifndef CLCD_CONFIG_H_
#define CLCD_CONFIG_H_

/****************includes**********************/
/**********************************************/

/****************defines**********************/

   /* CLCD_CTRL_PORT options:
						   	1-DIO_u8PORTA
			  	  	  	  	2-DIO_u8PORTB
			  	  	  	  	3-DIO_u8PORTC
			  	  	  	  	4-DIO_u8PORTD
   */
#define CLCD_CTRL_PORT                 DIO_u8PORTC
#define CLCD_DATA_PORT                 DIO_u8PORTA
	/*
	 CLCD_CTRL_PINS options:
	 */
#define CLCD_RS_PIN					   DIO_u8PIN0
#define CLCD_RW_PIN					   DIO_u8PIN1
#define CLCD_E_PIN					   DIO_u8PIN2



/**********USER DEFINEID DATA TYPES***********/
/*********************************************/

/***********FUNCTIONS PROTOTYPES***************/
/**********************************************/

#endif /* CLCD_CONFIG_H_ */
