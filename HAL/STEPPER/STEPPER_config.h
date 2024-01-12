/***************************************************************************/
/************* AUTHOR: @ Muhammed Sherif Attia *****************************/
/************* FILE  : @ STEPPER_config.h     *****************************/
/************* breif : @ driver for controlling 		********************/
/*************            stepper motor with ATMEG32    ********************/
/************* DATE  : @ 31/12/2023 ****************************************/
/***************************************************************************/


#ifndef STEPPER_CONFIG_H_
#define STEPPER_CONFIG_H_
/*
Select THE CONNECTION PORT OF the STEPPER 
				OPTIONS:
							1- DIO_u8PORTA
							2- DIO_u8PORTB
							3- DIO_u8PORTC
							4- DIO_u8PORTD
*/
#define   STEPPER_PORT        DIO_u8PORTA

/*
Select THE CONNECTION PINS OF the STEPPER 
				OPTIONS:
							1- DIO_u8PIN0
							2- DIO_u8PIN1
							3- DIO_u8PIN2
							4- DIO_u8PIN3
							5- DIO_u8PIN4
							6- DIO_u8PIN5
							7- DIO_u8PIN6
							8- DIO_u8PIN7
*/
#define   STEPPER_BluePin     DIO_u8PIN0
#define   STEPPER_PinkPin     DIO_u8PIN1
#define   STEPPER_YellowPin   DIO_u8PIN2
#define   STEPPER_OrangePin   DIO_u8PIN3

#endif /* STEPPER_CONFIG_H_ */
