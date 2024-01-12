/***************************************************************************/
/************* AUTHOR: @ Muhammed Sherif Attia *****************************/
/************* FILE  : @ DC_config.h     *****************************/
/************* breif : @ driver for controlling 		********************/
/*************            DC MOTOR with ATMEG32    ********************/
/************* DATE  : @ 31/12/2023 ****************************************/
/***************************************************************************/

#ifndef DC_CONFIG_H_
#define DC_CONFIG_H_

/*SELECT THE Connection pin1 of the motor (this pin controls CW rotation)
						options:
									1- DIO_u8PIN0
									2- DIO_u8PIN1
									3- DIO_u8PIN2
									4- DIO_u8PIN3
									5- DIO_u8PIN4
									6- DIO_u8PIN5
									7- DIO_u8PIN6
									8- DIO_u8PIN7
*/
#define  DC_u8PIN1   DIO_u8PIN0
/*SELECT THE Connection pin2 of the motor (this pin controls CCW rotation)
						options:
									1- DIO_u8PIN0
									2- DIO_u8PIN1
									3- DIO_u8PIN2
									4- DIO_u8PIN3
									5- DIO_u8PIN4
									6- DIO_u8PIN5
									7- DIO_u8PIN6
									8- DIO_u8PIN7
*/
#define  DC_u8PIN2   DIO_u8PIN1

/*
SELECT the PORT of the 2 pins connection
				options;
						1- DIO_u8PORTA
						2- DIO_u8PORTB
						3- DIO_u8PORTC
						4- DIO_u8PORTD
							
*/
#define  DC_u8PORT	 DIO_u8PORTC
#endif /* DC_CONFIG_H_ */
