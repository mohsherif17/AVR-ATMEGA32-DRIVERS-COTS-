/***************************************************************************/
/************* AUTHOR: @ Muhammed Sherif Attia *****************************/
/************* FILE  : @ USART_private.h       *****************************/
/************* breif : @ The private.h file for 		********************/
/*************           the USART Communication protocol in atmega32 ******/
/************* DATE  : @ 31/12/2023 ****************************************/
/***************************************************************************/
#ifndef USART_PRIVATE_H_
#define USART_PRIVATE_H_

/*******parity options *******/
#define 	USART_NO_PARITY			0
#define  	USART_EVEN_PARITY			0b00100000
#define  	USART_ODD_PARITY			0b00110000
/******* USART modes *******/
#define  	USART_SYNC		1
#define	 	USART_ASYNC		0
/******* Stop bit option *******/
#define		USART_STOP_1B	0
#define		USART_STOP_2B	1
/******* DATA SIZE *******/
#define		USART_MODE_5B	5
#define		USART_MODE_6B	6
#define		USART_MODE_7B	7
#define		USART_MODE_8B	8
#define		USART_MODE_9B	9

#endif /* USART_PRIVATE_H_ */
