/***************************************************************************/
/************* AUTHOR: @ Muhammed Sherif Attia *****************************/
/************* FILE  : @ USART_program.c       *****************************/
/************* breif : @ The program.c file for 		********************/
/*************           the USART Communication protocol in atmega32 ******/
/************* DATE  : @ 31/12/2023 ****************************************/
/***************************************************************************/

/*********************************** includes *****************************************/
/***** standard libs *****/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/***** USART files *****/
#include "USART_config.h"
#include "USART_interface.h"
#include "USART_private.h"
#include "USART_register.h"
/*********************************** GLOBAL VARIABLES *****************************************/

static void (*USART_TX_CallBack)(void) = NULL;	
static void (*USART_RX_CallBack)(void) = NULL;

/***********************************************************************************/
/***************************Functions implementation********************************/

/*********************************************************/
/*-> NAME: 		@ void USART_voidInit(void)		         */
/*-> breif:		@ this function is used to set and 	 	 */
/*				  intialize the config of the USART		 */
/*-> Prameters: @ void							       	 */
/*********************************************************/
void USART_voidInit(void){
	u8 Local_u8UCSRC=0b10000110;
	/* set Character size */
	#if(USART_DATA_MODE==USART_MODE_5B)
	CLR_BIT(UCSRB,USART_UCSZ2);
	CLR_BIT(Local_u8UCSRC,USART_UCSZ1);
	CLR_BIT(Local_u8UCSRC,USART_UCSZ0);
	#elif(USART_DATA_MODE==USART_MODE_6B)
	CLR_BIT(UCSRB,USART_UCSZ2);
	CLR_BIT(Local_u8UCSRC,USART_UCSZ1);
	SET_BIT(Local_u8UCSRC,USART_UCSZ0);
	#elif(USART_DATA_MODE==USART_MODE_7B)
	CLR_BIT(UCSRB,USART_UCSZ2);
	SET_BIT(Local_u8UCSRC,USART_UCSZ1);
	CLR_BIT(Local_u8UCSRC,USART_UCSZ0);
	#elif(USART_DATA_MODE==USART_MODE_8B)
	CLR_BIT(UCSRB,USART_UCSZ2);
	SET_BIT(Local_u8UCSRC,USART_UCSZ1);
	SET_BIT(Local_u8UCSRC,USART_UCSZ0);
	#elif(USART_DATA_MODE==USART_MODE_9B)
	SET_BIT(UCSRB,USART_UCSZ2);
	SET_BIT(Local_u8UCSRC,USART_UCSZ1);
	SET_BIT(Local_u8UCSRC,USART_UCSZ0);
	#endif
	/* Select UCSRC */
	SET_BIT(Local_u8UCSRC,USART_URSEL);
	/* select mode sync/async */
	#if(USART_MODE==USART_ASYNC)
	CLR_BIT(Local_u8UCSRC,USART_UMSEL);
	#elif (USART_MODE==USART_SYNC)
	SET_BIT_BIT(Local_u8UCSRC,USART_UMSEL);
	#endif
	/* select parity mode */
	Local_u8UCSRC &=0b11001111;
	Local_u8UCSRC |= USART_PARITY;
	/*Select stop bits(one)*/
	#if(USART_STOP_MODE==USART_STOP_1B)
	CLR_BIT(Local_u8UCSRC,USART_USBS);
	#elif(USART_STOP_MODE==USART_STOP_2B)
	SET_BIT(Local_u8UCSRC,USART_USBS);
	#endif
	/*set the UCSRC register*/
	UCSRC=Local_u8UCSRC;
	/*BUD rate = 9600*/
	UBRRL=USART_BOD_RATE;
	/* Enable send and receive RX /TX */
	SET_BIT(UCSRB,USART_RXEN);
	SET_BIT(UCSRB,USART_TXEN);
}
/******************************************************************************************************************************************************************************************************************/

/******************************************************************/
/*-> NAME: 		@ void USART_voidSyncSendData(u8 Copy_u8Data);    */
/*-> breif:		@ this function is used to SEND DATA using     	  */
/*				  USART in SYNC mode					          */
/*-> Prameters: @ u8 Copy_u8Data-> the data require to send       */
/******************************************************************/
void USART_voidSyncSendData(u8 Copy_u8Data){
	while((GET_BIT(UCSRA,USART_UDRE))!=1){            /*wait for the enable of transmit*/
		asm("NOP");
	}
	UDR=Copy_u8Data;									/*send data*/
}
/******************************************************************************************************************************************************************************************************************/


/******************************************************************/
/*-> NAME: 		@ u8   USART_u8SyncReadData(void);				  */
/*-> breif:		@ this function is used to RECIVE DATA using      */
/*				  USART in SYNC mode					          */
/*              @ return u8 data that was recived from the USART  */
/*-> Prameters: @ void											  */
/******************************************************************/
u8   USART_u8SyncReadData(void){
	while((GET_BIT(UCSRA,USART_RXC))!=1){		/*wait for the end of the recive*/
			asm("NOP");
		}
	return UDR;									/*return recived data from the UDR register*/
}
/******************************************************************************************************************************************************************************************************************/

/****************************************************************************/
/*-> NAME: 		@ void USART_voidSyncSendString(u8 *Copy_u8Data); 			*/
/*-> breif:		@ this function is used to SEND a STRING using     			*/
/*				  USART in SYNC mode					          			*/
/*              @ return u8 data that was recived from the USART  			*/
/*-> Prameters: @ u8 *Copy_u8Data-> pointer to the string require to be sent*/
/****************************************************************************/
void USART_voidSyncSendString(u8 *Copy_u8Data){
	while(*Copy_u8Data!= NULL){										/*check and wait for the end of the string*/
		USART_voidSyncSendData(*Copy_u8Data);						/*SEND transmited data to the UDR register*/
		*Copy_u8Data++;												/*increment the PTR to move tp the next bit in the string*/
	}
}
/******************************************************************************************************************************************************************************************************************/

/******************************************************************/
/*-> NAME: 		@ void USART_voidAsyncSendData(u8 Copy_u8Data);   */
/*-> breif:		@ this function is used to SEND DATA using     	  */
/*				  USART in ASYNC mode		(using interrupt)     */
/*-> Prameters: @ u8 Copy_u8Data-> the data require to send       */
/******************************************************************/
void USART_voidAsyncSendData(u8 Copy_u8Data){
	UDR=Copy_u8Data;										/*SEND transmited data to the UDR register*/
}
/******************************************************************************************************************************************************************************************************************/

/******************************************************************/
/*-> NAME: 		@ u8   USART_u8AsyncReadData(void);				  */
/*-> breif:		@ this function is used to RECIVE DATA using      */
/*				  USART in ASYNC mode		(using interrupt)	  */
/*              @ return u8 data that was recived from the USART  */
/*-> Prameters: @ void											  */
/******************************************************************/
u8   USART_u8AsyncReadData(void){
	return UDR;													/*return recived data from the UDR register*/
}
/******************************************************************************************************************************************************************************************************************/

/***********************************************************/
/*-> NAME: 		@ void USART_voidEnable_RXinterrupt(void)   */
/*-> breif:		@ this function is used to Enable recive   */
/*				  interrupt using the USART			       */
/*-> Prameters: @ void							       	   */
/***********************************************************/
void USART_voidEnable_RXinterrupt(void){
SET_BIT(UCSRB,USART_RXCIE);						/*set the bit no7 to enable the recive interrupt */
}
/******************************************************************************************************************************************************************************************************************/

/***********************************************************/
/*-> NAME: 		@ void USART_voidDisable_RXinterrupt(void)  */
/*-> breif:		@ this function is used to Disable recive  */
/*				  interrupt using the USART			       */
/*-> Prameters: @ void							       	   */
/***********************************************************/
void USART_voidDisable_RXinterrupt(void){
CLR_BIT(UCSRB,USART_RXCIE);						/*Clear the bit no7 to disable the recive interrupt */
}
/******************************************************************************************************************************************************************************************************************/

/***********************************************************/
/*-> NAME: 		@ void USART_voidEnable_TXinterrupt(void)   */
/*-> breif:		@ this function is used to Enable transmit */
/*				  interrupt using the USART			       */
/*-> Prameters: @ void							       	   */
/***********************************************************/
void USART_voidEnable_TXinterrupt(void){
SET_BIT(UCSRB,USART_TXCIE);							/*SET the bit no6 to enable the transmit interrupt */
}
/******************************************************************************************************************************************************************************************************************/

/***********************************************************/
/*-> NAME: 		@ void USART_voidDisable_TXinterrupt(void)  */
/*-> breif:		@ this function is used to Disable transmit*/
/*				  interrupt using the USART			       */
/*-> Prameters: @ void							       	   */
/***********************************************************/
void USART_voidDisable_TXinterrupt(void){
CLR_BIT(UCSRB,USART_TXCIE);							/*Clear the bit no6 to disable the transmit interrupt */
}
/******************************************************************************************************************************************************************************************************************/

/*********************************************************************************/
/*-> NAME: 		@ void USART_voidSetCallBackRX(void(*Copy_pvoidTXCallBacl)(void))*/
/*-> breif:		@ this function is used to SET the ISR function while using the  */
/*				  recive interrupt in USART										 */
/*-> Prameters: @ void(*Copy_pvoidTXCallBacl)(void)-> pointer to the ISR FUNCTION*/
/*********************************************************************************/
void USART_voidSetCallBackRX(void(*Copy_pvoidRXCallBacl)(void)){
	USART_RX_CallBack=Copy_pvoidRXCallBacl;		/*assign the ISR function address to the Global var*/
}
/******************************************************************************************************************************************************************************************************************/

/*********************************************************************************/
/*-> NAME: 		@ void USART_voidSetCallBackTX(void(*Copy_pvoidTXCallBacl)(void))*/
/*-> breif:		@ this function is used to SET the ISR function while using the  */
/*				  tansmit interrupt in USART									 */
/*-> Prameters: @ void(*Copy_pvoidTXCallBacl)(void)-> pointer to the ISR FUNCTION*/
/*********************************************************************************/
void USART_voidSetCallBackTX(void(*Copy_pvoidTXCallBacl)(void)){
	USART_TX_CallBack=Copy_pvoidTXCallBacl;		/*assign the ISR function address to the Global var*/
}
/******************************************************************************************************************************************************************************************************************/

/******************************************************************************************************************************************************************************************************************/
/*********************************************
the vector function for recive interrupt isr
*********************************************/
void __vector_13(void) __attribute__((signal));
void __vector_13(void){
	if(USART_RX_CallBack != NULL){
		USART_RX_CallBack();
	}
}
/******************************************************************************************************************************************************************************************************************/
/*********************************************
the vector function for transmit interrupt isr
*********************************************/
void __vector_15(void) __attribute__((signal));
void __vector_15(void){
	if(USART_TX_CallBack != NULL){
		USART_TX_CallBack();
	}
}

/******************************************************************************************************************************************************************************************************************/
/******************************************************************************************************************************************************************************************************************/
/******************************************************************************************************************************************************************************************************************/
