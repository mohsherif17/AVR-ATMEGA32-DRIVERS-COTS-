/***************************************************************************/
/************* AUTHOR: @ Muhammed Sherif Attia *****************************/
/************* FILE  : @ TWI_interface.h       *****************************/
/************* breif : @ The interface.h file for 		********************/
/*************           the TWI(I2C) Communication protocol in atmega32 ***/
/************* DATE  : @ 31/12/2023 ****************************************/
/***************************************************************************/

#ifndef TWI_INTERFACE_H_
#define TWI_INTERFACE_H_
/****************includes*********************/
/*********************************************/

/****************defines*********************/
/*******************************************/

/**********USER DEFINEID DATA TYPES**********/
typedef enum{
	No_error,
	StartConditionError,
	RpeatedStartConditionError,
	SlaveAddressWriteError,
	SlaveAddressReadError,
	MasterSendDataACKError,
	MasterSendDataNACKError,
	MasterReciveDataACKError,
	MasterReciveDataNACKError
}TWI_ERRORSTATE;
/******************************************************/
/*******FUNCTIONS PROTOTYPES********/
/***************************************************************/
/*-> NAME: 		@ void TWI_voidMasterInit(u8 Copy_u8Address)   */
/*-> breif:		@ this function is used to set and 	intialize  */
/*				  the MCU as MATER OF the I2c network 		   */
/*-> Prameters: @ u8 Copy_u8Address-> address the MCU as master*/
/***************************************************************/
void TWI_voidMasterInit(u8 Copy_u8Address);

/***************************************************************/
/*-> NAME: 		@ void TWI_voidSlaveInit(u8 Copy_u8Address)    */
/*-> breif:		@ this function is used to set and 	intialize  */
/*				  the MCU as SLAVE in the I2c network 		   */
/*-> Prameters: @ u8 Copy_u8Address-> address the MCU as SLAVE */
/***************************************************************/
void TWI_voidSlaveInit(u8 Copy_u8Address);

/***************************************************************/
/*-> NAME: 		@ TWI_ERRORSTATE TWI_SendStartCond(void)	   */
/*-> breif:		@ this function is used to send start condition*/
/*				  to the network to start reciveing sent data  */
/*				@ returns the error state					   */
/*-> Prameters: @ void										   */
/***************************************************************/
TWI_ERRORSTATE TWI_SendStartCond(void);

/***********************************************************************/
/*-> NAME: 		@ TWI_ERRORSTATE TWI_SendRepeatedStartCond(void)	   */
/*-> breif:		@ this function is used to send repeted start condition*/
/*				  to the network to start reciveing sent data  		   */
/*				@ returns the error state					   		   */
/*-> Prameters: @ void										   		   */
/***********************************************************************/
TWI_ERRORSTATE TWI_SendRepeatedStartCond(void);

/*****************************************************************************/
/*-> NAME: 		@ TWI_ERRORSTATE TWI_SendSlaveAddressRead(u8 Copy_u8Address) */
/*-> breif:		@ this function is used to set the address of slave MCU	     */
/*				  to select a slave to READ the data from				   	 */
/*				@ returns the error state					   		  		 */
/*-> Prameters: @ u8 Copy_u8Address-> the address of the slave MCU           */
/*****************************************************************************/
TWI_ERRORSTATE TWI_SendSlaveAddressRead(u8 Copy_u8Address);

/*****************************************************************************/
/*-> NAME: 		@ TWI_ERRORSTATE TWI_SendSlaveAddressWrite(u8 Copy_u8Address)*/
/*-> breif:		@ this function is used to set the address of slave MCU	     */
/*				  to select a slave to send the data to					   	 */
/*				@ returns the error state					   		  		 */
/*-> Prameters: @ u8 Copy_u8Address-> the address of the slave MCU           */
/*****************************************************************************/
TWI_ERRORSTATE TWI_SendSlaveAddressWrite(u8 Copy_u8Address);

/*****************************************************************************/
/*-> NAME: 		@ TWI_ERRORSTATE TWI_MasterSendData_ACK(u8 Copy_u8Data)	     */
/*-> breif:		@ this function is used to send data from master MCU         */
/*				  with acknowldgment bit 									 */
/*				@ returns the error state					   		  		 */
/*-> Prameters: @ u8 Copy_u8Data-> the data to be sent 				 	 	 */
/*****************************************************************************/
TWI_ERRORSTATE TWI_MasterSendData_ACK(u8 Copy_u8Data);

/*****************************************************************************/
/*-> NAME: 		@ TWI_ERRORSTATE TWI_MasterSendData_NACK(u8 Copy_u8Data)     */
/*-> breif:		@ this function is used to send data from master MCU         */
/*				  without acknowldgment bit 								 */
/*				@ returns the error state					   		  		 */
/*-> Prameters: @ u8 Copy_u8Data-> the data to be sent 				 	 	 */
/*****************************************************************************/
TWI_ERRORSTATE TWI_MasterSendData_NACK(u8 Copy_u8Data);

/*****************************************************************************/
/*-> NAME: 		@ TWI_ERRORSTATE TWI_MasterReciveData_ACK(u8 *Copy_u8Data)   */
/*-> breif:		@ this function is used to recive data in MASTER MCU         */
/*				  with acknowldgment bit 									 */
/*				@ returns the error state					   		  		 */
/*-> Prameters: @ u8 *Copy_u8Data-> pointer to recive the data  	  	  	 */
/*****************************************************************************/
TWI_ERRORSTATE TWI_MasterReciveData_ACK(u8 *Copy_u8Data);

/*****************************************************************************/
/*-> NAME: 		@ TWI_ERRORSTATE TWI_MasterReciveData_NACK(u8 *Copy_u8Data)   */
/*-> breif:		@ this function is used to recive data in MASTER MCU         */
/*				  without acknowldgment bit 								 */
/*				@ returns the error state					   		  		 */
/*-> Prameters: @ u8 *Copy_u8Data-> pointer to recive the data  	  	  	 */
/*****************************************************************************/
TWI_ERRORSTATE TWI_MasterReciveData_NACK(u8 *Copy_u8Data);

/***************************************************************/
/*-> NAME: 		@ void TWI_SendStopCond(void)	   			   */
/*-> breif:		@ this function is used to send start condition*/
/*				  to the network to END the communication      */
/*-> Prameters: @ void										   */
/***************************************************************/
void TWI_SendStopCond(void);

/***********************************************************/
/*-> NAME: 		@ void TWI_voidInterruptDisable(void) 	   */
/*-> breif:		@ this function is used to enable  	   	   */
/*				  interrupt using the TWI(I2C)		       */
/*-> Prameters: @ void							       	   */
/***********************************************************/
void TWI_voidInterruptDisable(void);

/***********************************************************/
/*-> NAME: 		@ void TWI_voidInterruptDisable(void) 	   */
/*-> breif:		@ this function is used to Disable  	   */
/*				  interrupt using the TWI(I2C)		       */
/*-> Prameters: @ void							       	   */
/***********************************************************/
void TWI_voidInterruptEnable(void);

/**********************************************************************************/
/*-> NAME: 		@ void TWI_voidSetCallBack(void(*Copy_pvoidCallBackTWI)(void))	  */
/*-> breif:		@ this function is used to SET the ISR function while using the   */
/*			      interrupt in TWI(I2C)											  */
/*-> Prameters: @ void(*Copy_pvoidCallBackTWI)(void)-> pointer to the ISR FUNCTION*/
/**********************************************************************************/
void TWI_voidSetCallBack(void(*Copy_pvoidCallBackTWI)(void));

#endif /* TWI_INTERFACE_H_ */
