/***************************************************************************/
/************* AUTHOR: @ Muhammed Sherif Attia *****************************/
/************* FILE  : @ EEPROM_program.c     ******************************/
/************* breif : @ driver for controlling 		********************/
/*************           EEPROM with ATMEG32 		   *********************/
/************* DATE  : @ 31/12/2023 ****************************************/
/***************************************************************************/


/****************includes*********************/
/*Standered libs*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*MCAL LAYER*/
#include "TWI_interface.h"
/*EEPROM FILES*/
#include"EEPROM_interface.h"
/********************************************/

/****************defines*********************/
#define A2		1


/***********************************************************************************/
/***************************Functions implementation********************************/

/******************************************************************************************/
/*-> NAME: 		@ void EEPROM_void_WriteByte(u8 A_u8Data,u16 A_u16Address) 			     */
/*-> breif:		@ this function is used to write data on the EEPROM	with TWI(I2C) PROTCOL*/
/*-> Prameters: @ A_u8Data-> data to be written on the external EEPROM					 */
/*				@ A_u16Address-> the address of the EEPROM int I2C CONNECTION		   	 */
/*****************************************************************************************/

void EEPROM_void_WriteByte(u8 A_u8Data,u16 A_u16Address){
	TWI_SendStartCond();  										 /*START I2C COMMUNICTION*/

	TWI_SendSlaveAddressWrite(0b1010|A2<<2|A_u16Address>>8);		/*SEND the address of the EEPROM TO the NETWOTK TO DETECT it*/
	TWI_MasterSendData_ACK((u8) A_u16Address);						/*send ACK of the EEPROM TO start the data sending*/
	TWI_MasterSendData_ACK(A_u8Data);								/*SEND THE DATA TO THE EEPROM*/
	TWI_SendStopCond();												/*end of the communication frame*/
	 _delay_ms(10);
}
/******************************************************************************************/
/*-> NAME: 		@ void EEPROM_void_WriteByte(u8 A_u8Data,u16 A_u16Address) 			     */
/*-> breif:		@ this function is used to write data on the EEPROM	with TWI(I2C) PROTCOL*/
/*-> Prameters: @ Copy_Pu8DATA-> ptr to recive the read data from EEPROM				 */
/*				@ A_u16Address-> the address of the EEPROM int I2C CONNECTION		   	 */
/*****************************************************************************************/
void EEPROM_voidReadByte(u8* Copy_Pu8DATA,u16 A_u16Address){
	TWI_SendStartCond();  										/*START I2C COMMUNICTION*/

		TWI_SendSlaveAddressWrite(0b1010|A2<<2|A_u16Address>>8);   /*SEND the address of the EEPROM TO the NETWOTK TO DETECT it*/
		TWI_MasterSendData_ACK((u8) A_u16Address);					/*SEND ACK to the MASTER to START reciving data*/
		TWI_SendRepeatedStartCond();								/*START of THE DATA Frame*/
		TWI_SendSlaveAddressWrite(0b1010|A2<<2|A_u16Address>>8);	/*SELECT THE EEPROM TO REAd the DATA FROM IT*/
		TWI_MasterReciveData_ACK(Copy_Pu8DATA);						/*reciving the data*/
}
