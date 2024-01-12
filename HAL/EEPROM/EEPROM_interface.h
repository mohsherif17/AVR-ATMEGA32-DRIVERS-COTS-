/***************************************************************************/
/************* AUTHOR: @ Muhammed Sherif Attia *****************************/
/************* FILE  : @ EEPROM_program.c     ******************************/
/************* breif : @ driver for controlling 		********************/
/*************           EEPROM with ATMEG32 		   *********************/
/************* DATE  : @ 31/12/2023 ****************************************/
/***************************************************************************/


/****************includes*********************/
/********************************************/

/****************defines*********************/

/***********************************************************************************/
/***************************Functions implementation********************************/

/******************************************************************************************/
/*-> NAME: 		@ void EEPROM_void_WriteByte(u8 A_u8Data,u16 A_u16Address) 			     */
/*-> breif:		@ this function is used to write data on the EEPROM	with TWI(I2C) PROTCOL*/
/*-> Prameters: @ A_u8Data-> data to be written on the external EEPROM					 */
/*				@ A_u16Address-> the address of the EEPROM int I2C CONNECTION		   	 */
/*****************************************************************************************/

void EEPROM_void_WriteByte(u8 A_u8Data,u16 A_u16Address);
/******************************************************************************************/
/*-> NAME: 		@ void EEPROM_void_WriteByte(u8 A_u8Data,u16 A_u16Address) 			     */
/*-> breif:		@ this function is used to write data on the EEPROM	with TWI(I2C) PROTCOL*/
/*-> Prameters: @ Copy_Pu8DATA-> ptr to recive the read data from EEPROM				 */
/*				@ A_u16Address-> the address of the EEPROM int I2C CONNECTION		   	 */
/*****************************************************************************************/
void EEPROM_voidReadByte(u8* Copy_Pu8DATA,u16 A_u16Address);
