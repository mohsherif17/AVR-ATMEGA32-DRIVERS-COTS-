/***************************************************************************/
/************* AUTHOR: @ Muhammed Sherif Attia *****************************/
/************* FILE  : @ CLCD_interface.h        *****************************/
/************* breif : @ driver for controlling 		********************/
/*************            CHARACTER LCD with ATMEG32    ********************/
/************* DATE  : @ 31/12/2023 ****************************************/
/***************************************************************************/


#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_
/****************includes**********************/
/**********************************************/

/****************defines**********************/

/*********************************************/

/**********USER DEFINEID DATA TYPES***********/
/*********************************************/

/***********FUNCTIONS PROTOTYPES***************/
/***************************************************************************************/
/*-> NAME: 		@ void CLCD_voidSendCommand(u8 Copy_u8Command)	     				   */
/*-> breif:		@ this function is used to send a command to the processor of the CLCD */
/*-> Prameters: @ Copy_u8Command-> the command to be sent to the clcd				   */
/***************************************************************************************/
void CLCD_voidSendCommand(u8 Copy_u8Command);
/***************************************************************************************/
/*-> NAME: 		@ void CLCD_voidSendCharacter(u8 Copy_u8Data)	     				   */
/*-> breif:		@ this function is used to send a CHARACTER to be displayed on the CLCD*/
/*-> Prameters: @ Copy_u8Data-> the data to be displayed on the clcd				   */
/***************************************************************************************/
void CLCD_voidSendCharacter(u8 Copy_u8Data);
/***************************************************************************************/
/*-> NAME: 		@ void CLCD_voidInit(void)						     				   */
/*-> breif:		@ this function is used to initialize and set the configrations of CLCD*/
/*-> Prameters: @ void																   */
/***************************************************************************************/
void CLCD_voidInit(void);
/***************************************************************************************/
/*-> NAME: 		@ void CLCD_voidSendString(const char* Copy_string)    				   */
/*-> breif:		@ this function is used to send a STRING to be displayed on the CLCD   */
/*-> Prameters: @ Copy_string-> pointer to the string to be displayed on the CLCD	   */
/***************************************************************************************/
void CLCD_voidSendString(const char* Copy_string);
/***************************************************************************************/
/*-> NAME: 		@ void CLCD_voidClearDisplay(void)						     		   */
/*-> breif:		@ this function is used to CLEAR the display of CLCD				   */
/*-> Prameters: @ void																   */
/***************************************************************************************/
void CLCD_voidClearDisplay(void);
/*********************************************************************************************/
/*-> NAME: 		@ void CLCD_voidMoveCurseor(u8 Copy_u8Line,u8 Copy_u8Grid)     		   		 */
/*-> breif:		@ this function is used to move the curseor of CLCD to a new display position*/
/*-> Prameters: @ Copy_u8Line-> the line of the new position								 */
/*				@ Copy_u8Grid-> the column in the line (the bit of the lcd)					 */
/*********************************************************************************************/
void CLCD_voidMoveCurseor(u8 Copy_u8Line,u8 Copy_u8Grid);
/***************************************************************************************/
/*-> NAME: 		@ void CLCD_voidSendNumber(u64 Copy_u64Number)	     				   */
/*-> breif:		@ this function is used to send a NUMBER to be displayed on the CLCD   */
/*-> Prameters: @ Copy_u64Number-> the NUMBER to be displayed on the clcd			   */
/***************************************************************************************/
void CLCD_voidSendNumber(u64 Copy_u64Number);
/***************************************************************************************/
/*-> NAME: 		@ void CLCD_voidSendNumber(u64 Copy_u64Number)	     				   */
/*-> breif:		@ this function is used to send a  SPECIAL CHARACTERto be displayed on */
/*					the CLCD(CHARCTER not in the ASCI TABLE of the CLCD) 			   */
/*-> Prameters: @ Copy_u64Number-> the NUMBER to be displayed on the clcd			   */
/***************************************************************************************/
void CLCD_voidSendSpecialCharacter(u8* Copy_pu8Pattern,u8 Copy_u8CGRAM_Adrress,u8 Copy_u8Line,u8 Copy_u8Grid);
/**********************************************/


#endif /* CLCD_INTERFACE_H_ */
