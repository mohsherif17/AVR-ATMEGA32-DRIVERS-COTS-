/***************************************************************************/
/************* AUTHOR: @ Muhammed Sherif Attia *****************************/
/************* FILE  : @ TWI_program.c         *****************************/
/************* breif : @ The program.c file for 		********************/
/*************           the TWI(I2C) Communication protocol in atmega32 ***/
/************* DATE  : @ 31/12/2023 ****************************************/
/***************************************************************************/


/*********************************** includes *****************************************/
/***** standard libs *****/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/***** TWI files *****/
#include"TWI_config.h"
#include "TWI_interface.h"
#include "TWI_private.h"
#include "TWI_register.h"

/*********************************** GLOBAL VARIABLES *****************************************/

static void (*TWI_CallBack)(void) = NULL;

/**********************************************************************************************/


/***************************Functions implementation********************************/

/***************************************************************/
/*-> NAME: 		@ void TWI_voidMasterInit(u8 Copy_u8Address)   */
/*-> breif:		@ this function is used to set and 	intialize  */
/*				  the MCU as MATER OF the I2c network 		   */
/*-> Prameters: @ u8 Copy_u8Address-> address the MCU as master*/
/***************************************************************/
void TWI_voidMasterInit(u8 Copy_u8Address){
if(Copy_u8Address!=0){
	TWAR = Copy_u8Address<<1;
}
CLR_BIT(TWSR,1);
CLR_BIT(TWSR,0);
TWBR=2;
}
/****************************************************/
/***************************************************************/
/*-> NAME: 		@ void TWI_voidSlaveInit(u8 Copy_u8Address)    */
/*-> breif:		@ this function is used to set and 	intialize  */
/*				  the MCU as SLAVE in the I2c network 		   */
/*-> Prameters: @ u8 Copy_u8Address-> address the MCU as SLAVE */
/***************************************************************/
void TWI_voidSlaveInit(u8 Copy_u8Address){
	TWAR = Copy_u8Address<<1;

}
/****************************************************/
/***************************************************************/
/*-> NAME: 		@ TWI_ERRORSTATE TWI_SendStartCond(void)	   */
/*-> breif:		@ this function is used to send start condition*/
/*				  to the network to start reciveing sent data  */
/*				@ returns the error state					   */
/*-> Prameters: @ void										   */
/***************************************************************/
TWI_ERRORSTATE TWI_SendStartCond(void){
	TWI_ERRORSTATE Local_u8ErorrState=No_error;
TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
while (!(TWCR & (1<<TWINT)));
if ((TWSR & 0xF8) != START){
	Local_u8ErorrState=StartConditionError;
}
	return Local_u8ErorrState;
}
/*****************************************************/
/***********************************************************************/
/*-> NAME: 		@ TWI_ERRORSTATE TWI_SendRepeatedStartCond(void)	   */
/*-> breif:		@ this function is used to send repeted start condition*/
/*				  to the network to start reciveing sent data  		   */
/*				@ returns the error state					   		   */
/*-> Prameters: @ void										   		   */
/***********************************************************************/
TWI_ERRORSTATE TWI_SendRepeatedStartCond(void){
	TWI_ERRORSTATE Local_u8ErorrState=No_error;
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while (!(TWCR & (1<<TWINT)));
	if ((TWSR & 0xF8) != REPATERD_START){
		Local_u8ErorrState=RpeatedStartConditionError;
	}
		return Local_u8ErorrState;
}
/****************************************************/
/*****************************************************************************/
/*-> NAME: 		@ TWI_ERRORSTATE TWI_SendSlaveAddressRead(u8 Copy_u8Address) */
/*-> breif:		@ this function is used to set the address of slave MCU	     */
/*				  to select a slave to READ the data from				   	 */
/*				@ returns the error state					   		  		 */
/*-> Prameters: @ u8 Copy_u8Address-> the address of the slave MCU           */
/*****************************************************************************/
TWI_ERRORSTATE TWI_SendSlaveAddressRead(u8 Copy_u8Address){
	TWI_ERRORSTATE Local_u8ErorrState=No_error;

	u8 Local_u8Addres=Copy_u8Address<<1;
	SET_BIT(Copy_u8Address,0);
	TWDR =Local_u8Addres;
	TWCR = (1<<TWINT) | (1<<TWEN);
	while (!(TWCR & (1<<TWINT)));
	if ((TWSR & 0xF8) != MR_SLA_ACK){
		Local_u8ErorrState=SlaveAddressReadError;
	}

		return Local_u8ErorrState;
}

/*****************************************************************************/
/*-> NAME: 		@ TWI_ERRORSTATE TWI_SendSlaveAddressWrite(u8 Copy_u8Address)*/
/*-> breif:		@ this function is used to set the address of slave MCU	     */
/*				  to select a slave to send the data to					   	 */
/*				@ returns the error state					   		  		 */
/*-> Prameters: @ u8 Copy_u8Address-> the address of the slave MCU           */
/*****************************************************************************/
TWI_ERRORSTATE TWI_SendSlaveAddressWrite(u8 Copy_u8Address){
	TWI_ERRORSTATE Local_u8ErorrState=No_error;
	u8 Local_u8Addres=Copy_u8Address<<1;
	CLR_BIT(Copy_u8Address,0);
	TWDR =Local_u8Addres;
	TWCR = (1<<TWINT) | (1<<TWEN);
	while (!(TWCR & (1<<TWINT)));
	if ((TWSR & 0xF8) != MT_SLA_ACK){
		Local_u8ErorrState=SlaveAddressWriteError;
	}
		return Local_u8ErorrState;
}
/****************************************************/
/*****************************************************************************/
/*-> NAME: 		@ TWI_ERRORSTATE TWI_MasterSendData_ACK(u8 Copy_u8Data)	     */
/*-> breif:		@ this function is used to send data from master MCU         */
/*				  with acknowldgment bit 									 */
/*				@ returns the error state					   		  		 */
/*-> Prameters: @ u8 Copy_u8Data-> the data to be sent 				 	 	 */
/*****************************************************************************/
TWI_ERRORSTATE TWI_MasterSendData_ACK(u8 Copy_u8Data){
	TWI_ERRORSTATE Local_u8ErorrState=No_error;
	TWDR=Copy_u8Data;
	TWCR = (1<<TWINT) | (1<<TWEN)|(1<<TWEA);
	while (!(TWCR & (1<<TWINT)));
	if ((TWSR & 0xF8) != MT_DATA_ACK){
		Local_u8ErorrState=MasterSendDataACKError;
	}
		return Local_u8ErorrState;
}
/****************************************************/
/*****************************************************************************/
/*-> NAME: 		@ TWI_ERRORSTATE TWI_MasterSendData_NACK(u8 Copy_u8Data)     */
/*-> breif:		@ this function is used to send data from master MCU         */
/*				  without acknowldgment bit 								 */
/*				@ returns the error state					   		  		 */
/*-> Prameters: @ u8 Copy_u8Data-> the data to be sent 				 	 	 */
/*****************************************************************************/
TWI_ERRORSTATE TWI_MasterSendData_NACK(u8 Copy_u8Data){
	TWI_ERRORSTATE Local_u8ErorrState=No_error;

	TWDR=Copy_u8Data;
		TWCR = (1<<TWINT) | (1<<TWEN)|(1<<TWEA);
		while (!(TWCR & (1<<TWINT)));
		if ((TWSR & 0xF8) != MT_DATA_NACK){
			Local_u8ErorrState=MasterSendDataNACKError;
		}

		return Local_u8ErorrState;
}
/****************************************************/
/*****************************************************************************/
/*-> NAME: 		@ TWI_ERRORSTATE TWI_MasterReciveData_ACK(u8 *Copy_u8Data)   */
/*-> breif:		@ this function is used to recive data in MASTER MCU         */
/*				  with acknowldgment bit 									 */
/*				@ returns the error state					   		  		 */
/*-> Prameters: @ u8 *Copy_u8Data-> pointer to recive the data  	  	  	 */
/*****************************************************************************/
TWI_ERRORSTATE TWI_MasterReciveData_ACK(u8 *Copy_u8Data){
	TWI_ERRORSTATE Local_u8ErorrState=No_error;

		TWCR = (1<<TWINT) | (1<<TWEN)|(1<<TWEA);
		while (!(TWCR & (1<<TWINT)));
		if ((TWSR & 0xF8) != MR_DATA_ACK){
			Local_u8ErorrState=MasterReciveDataACKError	;
		}
		*Copy_u8Data=TWDR;

		return Local_u8ErorrState;
}
/****************************************************/
/*****************************************************************************/
/*-> NAME: 		@ TWI_ERRORSTATE TWI_MasterReciveData_NACK(u8 *Copy_u8Data)   */
/*-> breif:		@ this function is used to recive data in MASTER MCU         */
/*				  without acknowldgment bit 								 */
/*				@ returns the error state					   		  		 */
/*-> Prameters: @ u8 *Copy_u8Data-> pointer to recive the data  	  	  	 */
/*****************************************************************************/
TWI_ERRORSTATE TWI_MasterReciveData_NACK(u8 *Copy_u8Data){
	TWI_ERRORSTATE Local_u8ErorrState=No_error;

	TWCR = (1<<TWINT) | (1<<TWEN);
			while (!(TWCR & (1<<TWINT)));
			if ((TWSR & 0xF8) != MR_DATA_NACK){
				Local_u8ErorrState=MasterReciveDataNACKError	;
			}
			*Copy_u8Data=TWDR;

		return Local_u8ErorrState;
}
/****************************************************/
/***************************************************************/
/*-> NAME: 		@ void TWI_SendStopCond(void)	   			   */
/*-> breif:		@ this function is used to send start condition*/
/*				  to the network to END the communication      */
/*-> Prameters: @ void										   */
/***************************************************************/
void TWI_SendStopCond(void){
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
}

/***********************************************************/
/*-> NAME: 		@ void TWI_voidInterruptDisable(void) 	   */
/*-> breif:		@ this function is used to enable  	   	   */
/*				  interrupt using the TWI(I2C)		       */
/*-> Prameters: @ void							       	   */
/***********************************************************/

void TWI_voidInterruptEnable(void){

	/* Enable TWI interrupt */
	SET_BIT(TWCR, TWIE);

}
/***********************************************************/
/*-> NAME: 		@ void TWI_voidInterruptDisable(void) 	   */
/*-> breif:		@ this function is used to Disable  	   */
/*				  interrupt using the TWI(I2C)		       */
/*-> Prameters: @ void							       	   */
/***********************************************************/
void TWI_voidInterruptDisable(void){

	/* Disable TWI interrupt */
	CLR_BIT(TWCR, TWIE);

}
/**********************************************************************************/
/*-> NAME: 		@ void TWI_voidSetCallBack(void(*Copy_pvoidCallBackTWI)(void))	  */
/*-> breif:		@ this function is used to SET the ISR function while using the   */
/*			      interrupt in TWI(I2C)											  */
/*-> Prameters: @ void(*Copy_pvoidCallBackTWI)(void)-> pointer to the ISR FUNCTION*/
/**********************************************************************************/
void TWI_voidSetCallBack(void(*Copy_pvoidCallBackTWI)(void)){

	TWI_CallBack = Copy_pvoidCallBackTWI;

}

/******************************************************************************************************************************************************************************************************************/
/*********************************************
the vector function for interrupt isr
*********************************************/
void __vector_19(void) __attribute__((signal));
void __vector_19(void){
	if(TWI_CallBack != NULL){
		TWI_CallBack();
	}
}