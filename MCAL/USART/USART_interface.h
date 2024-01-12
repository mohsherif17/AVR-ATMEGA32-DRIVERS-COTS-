/***************************************************************************/
/************* AUTHOR: @ Muhammed Sherif Attia *****************************/
/************* FILE  : @ USART_interface.h     *****************************/
/************* breif : @ The interface.h file for 		********************/
/*************           the USART Communication protocol in atmega32 ******/
/************* DATE  : @ 31/12/2023 ****************************************/
/***************************************************************************/

#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_
/****************includes*********************/
/*********************************************/

/****************defines*********************/
/*******************************************/

/********************* FUNCTIONS PROTOTYPES **********************/
/*********************************************************/
/*-> NAME: 		@ void USART_voidInit(void)		         */
/*-> breif:		@ this function is used to set and 	 	 */
/*				  intialize the config of the USART		 */
/*-> Prameters: @ void							       	 */
/*********************************************************/
void USART_voidInit(void);

/******************************************************************/
/*-> NAME: 		@ void USART_voidSyncSendData(u8 Copy_u8Data);    */
/*-> breif:		@ this function is used to SEND DATA using     	  */
/*				  USART in SYNC mode					          */
/*-> Prameters: @ u8 Copy_u8Data-> the data require to send       */
/******************************************************************/
void USART_voidSyncSendData(u8 Copy_u8Data);

/******************************************************************/
/*-> NAME: 		@ u8   USART_u8SyncReadData(void);				  */
/*-> breif:		@ this function is used to RECIVE DATA using      */
/*				  USART in SYNC mode					          */
/*              @ return u8 data that was recived from the USART  */
/*-> Prameters: @ void											  */
/******************************************************************/
u8   USART_u8SyncReadData(void);

/****************************************************************************/
/*-> NAME: 		@ void USART_voidSyncSendString(u8 *Copy_u8Data); 			*/
/*-> breif:		@ this function is used to SEND a STRING using     			*/
/*				  USART in SYNC mode					          			*/
/*              @ return u8 data that was recived from the USART  			*/
/*-> Prameters: @ u8 *Copy_u8Data-> pointer to the string require to be sent*/
/****************************************************************************/
void USART_voidSyncSendString(u8 *Copy_u8Data);


/******************************************************************/
/*-> NAME: 		@ u8   USART_u8AsyncReadData(void);				  */
/*-> breif:		@ this function is used to RECIVE DATA using      */
/*				  USART in ASYNC mode		(using interrupt)	  */
/*              @ return u8 data that was recived from the USART  */
/*-> Prameters: @ void											  */
/******************************************************************/
u8   USART_u8AsyncReadData(void);

/******************************************************************/
/*-> NAME: 		@ void USART_voidAsyncSendData(u8 Copy_u8Data);   */
/*-> breif:		@ this function is used to SEND DATA using     	  */
/*				  USART in ASYNC mode		(using interrupt)     */
/*-> Prameters: @ u8 Copy_u8Data-> the data require to send       */
/******************************************************************/
void USART_voidAsyncSendData(u8 Copy_u8Data);

/***********************************************************/
/*-> NAME: 		@ void USART_voidEnable_TXinterrupt(void)   */
/*-> breif:		@ this function is used to Enable transmit */
/*				  interrupt using the USART			       */
/*-> Prameters: @ void							       	   */
/***********************************************************/
void USART_voidEnable_TXinterrupt(void);

/***********************************************************/
/*-> NAME: 		@ void USART_voidDisable_TXinterrupt(void)  */
/*-> breif:		@ this function is used to Disable transmit*/
/*				  interrupt using the USART			       */
/*-> Prameters: @ void							       	   */
/***********************************************************/
void USART_voidDisable_TXinterrupt(void);


/***********************************************************/
/*-> NAME: 		@ void USART_voidEnable_RXinterrupt(void)   */
/*-> breif:		@ this function is used to Enable recive   */
/*				  interrupt using the USART			       */
/*-> Prameters: @ void							       	   */
/***********************************************************/
void USART_voidEnable_RXinterrupt(void);
/***********************************************************/
/*-> NAME: 		@ void USART_voidDisable_RXinterrupt(void)  */
/*-> breif:		@ this function is used to Disable recive  */
/*				  interrupt using the USART			       */
/*-> Prameters: @ void							       	   */
/***********************************************************/
void USART_voidDisable_RXinterrupt(void);


/*********************************************************************************/
/*-> NAME: 		@ void USART_voidSetCallBackTX(void(*Copy_pvoidTXCallBacl)(void))*/
/*-> breif:		@ this function is used to SET the ISR function while using the  */
/*				  tansmit interrupt in USART									 */
/*-> Prameters: @ void(*Copy_pvoidTXCallBacl)(void)-> pointer to the ISR FUNCTION*/
/*********************************************************************************/
void USART_voidSetCallBackTX(void(*Copy_pvoidTXCallBacl)(void));

/*********************************************************************************/
/*-> NAME: 		@ void USART_voidSetCallBackRX(void(*Copy_pvoidTXCallBacl)(void))*/
/*-> breif:		@ this function is used to SET the ISR function while using the  */
/*				  recive interrupt in USART										 */
/*-> Prameters: @ void(*Copy_pvoidTXCallBacl)(void)-> pointer to the ISR FUNCTION*/
/*********************************************************************************/
void USART_voidSetCallBackRX(void(*Copy_pvoidRXCallBacl)(void));






















#endif /* USART_INTERFACE_H_ */
