/***************************************************************************/
/************* AUTHOR: @ Muhammed Sherif Attia *****************************/
/************* FILE  : @ USART_register.h      *****************************/
/************* breif : @ The register.h file for 		********************/
/*************           the USART Communication protocol in atmega32 ******/
/************* DATE  : @ 31/12/2023 ****************************************/
/***************************************************************************/

#ifndef USART_REGISTER_H_
#define USART_REGISTER_H_
/******* DATA REgister *******/
#define   UDR    	*((volatile u8*)(0x2C))
/********************************************/
#define   UCSRA    	*((volatile u8*)(0x2B))

#define USART_RXC					7
#define USART_TXC					6
#define USART_UDRE					5
#define USART_FE					4
#define USART_DOR					3
#define USART_PE					2
#define USART_U2X					1
#define USART_MPCM					0

/********************************************/
#define   UCSRB    	*((volatile u8*)(0x2A))

#define USART_RXCIE					7
#define USART_TXCIE					6
#define USART_UDRIE					5
#define USART_RXEN					4
#define USART_TXEN					3
#define USART_UCSZ2					2
#define USART_RXB8					1
#define USART_TXB8					0
/********************************************/
#define   UCSRC  	*((volatile u8*)(0x40))


#define USART_URSEL					7
#define USART_UMSEL					6
#define USART_UPM1					5
#define USART_UPM0					4
#define USART_USBS					3
#define USART_UCSZ1					2
#define USART_UCSZ0					1
#define USART_UCPOL					0


/********************************************/
#define   UBRRL  	*((volatile u8*)(0x29))

#endif /* USART_REGISTER_H_ */
