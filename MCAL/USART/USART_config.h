/***************************************************************************/
/************* AUTHOR: @ Muhammed Sherif Attia *****************************/
/************* FILE  : @ USART_config.h        *****************************/
/************* breif : @ The config.h file for  		********************/
/*************           the USART Communication protocol in atmega32 ******/
/************* DATE  : @ 31/12/2023 ****************************************/
/***************************************************************************/

#ifndef USART_CONFIG_H_
#define USART_CONFIG_H_

/*
*-> USART RUN MODE OPTIONS:  
								1- USART_SYNC
								2- USART_ASYNC
*/

#define   		USART_MODE				 USART_SYNC

/*
*-> USART PARITY MODE OPTIONS:  
								1- USART_NO_PARITY
								2- USART_EVEN_PARITY
								3- USART_ODD_PARITY
*/

#define 		USART_PARITY			 USART_EVEN_PARITY


/*
*-> USART STOP BIT MODE OPTIONS:  
								1- USART_STOP_1B
								2- USART_STOP_2B
*/

#define         USART_STOP_MODE			 USART_STOP_1B

/*-> USART DATA MODE OPTIONS:  
								1- USART_MODE_5B
								2- USART_MODE_6B
								3- USART_MODE_7B
								4- USART_MODE_8B
								5- USART_MODE_9B
*/

#define			USART_DATA_MODE			USART_MODE_8B

/*bod rate */
#define     	USART_BOD_RATE						51


#endif /* USART_CONFIG_H_ */
