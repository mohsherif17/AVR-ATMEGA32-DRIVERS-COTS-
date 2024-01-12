/***************************************************************************/
/************* AUTHOR: @ Muhammed Sherif Attia *****************************/
/************* FILE  : @ CLCD_program.c        *****************************/
/************* breif : @ driver for controlling 		********************/
/*************            CHARACTER LCD with ATMEG32    ********************/
/************* DATE  : @ 31/12/2023 ****************************************/
/***************************************************************************/

/****************includes*********************/
/*Standered libs*/
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include<util/delay.h>
/*MCAL LAYER*/
#include"DIO_interface.h"
/*CLCD FILES*/
#include"CLCD_config.h"
#include"CLCD_private.h"
#include"CLCD_interface.h"

/**********************************************/

/****************defines**********************/
/*********************************************/

/**********USER DEFINEID DATA TYPES***********/
/*********************************************/

/***********FUNCTIONS Implementation***************/
/***************************************************************************************/
/*-> NAME: 		@ void CLCD_voidSendCommand(u8 Copy_u8Command)	     				   */
/*-> breif:		@ this function is used to send a command to the processor of the CLCD */
/*-> Prameters: @ Copy_u8Command-> the command to be sent to the clcd				   */
/***************************************************************************************/

void CLCD_voidSendCommand(u8 Copy_u8Command)
{
	/*SEND SIGNAL to the CLCD To SEND A COMMAND on the DATA PINS */
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8LOW);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8LOW);
	/*SENDING THE COMMAND*/
	DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Command);
	/*ENABLE PIN VALUE = 1*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8HIGH);
	_delay_ms(2); /*WAIT FOR 2 mS*/
	/*Clear enable Pin*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8LOW);
}
/***************************************************************************************/
/*-> NAME: 		@ void CLCD_voidSendCharacter(u8 Copy_u8Data)	     				   */
/*-> breif:		@ this function is used to send a CHARACTER to be displayed on the CLCD*/
/*-> Prameters: @ Copy_u8Data-> the data to be displayed on the clcd				   */
/***************************************************************************************/
void CLCD_voidSendCharacter(u8 Copy_u8Data)
{
	/*SEND SIGNAL to the CLCD To SEND A DATA on the DATA PINS */
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8HIGH);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8LOW);
	/*SENDING THE DATA*/
	DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Data);
	/*ENABLE PIN VALUE = 1*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8HIGH);
	_delay_ms(2);/*WAIT FOR 2 mS*/
	/*Clear enable Pin*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8LOW);
}
/***************************************************************************************/
/*-> NAME: 		@ void CLCD_voidInit(void)						     				   */
/*-> breif:		@ this function is used to initialize and set the configrations of CLCD*/
/*-> Prameters: @ void																   */
/***************************************************************************************/
void CLCD_voidInit(void)
{
_delay_ms(40);
CLCD_voidSendCommand(0b00111000);	/*Function set*/
CLCD_voidSendCommand(0b00001100);	/*lcd on*/
CLCD_voidSendCommand(0b00000001); /*CLEAR DISPLAY*/
}
/***************************************************************************************/
/*-> NAME: 		@ void CLCD_voidSendString(const char* Copy_string)    				   */
/*-> breif:		@ this function is used to send a STRING to be displayed on the CLCD   */
/*-> Prameters: @ Copy_string-> pointer to the string to be displayed on the CLCD	   */
/***************************************************************************************/
void CLCD_voidSendString(const char* Copy_string)
{
	u8 localcounter=0;			/*variable to count the number ofchars in the string*/
	while(Copy_string[localcounter]!='\0')/*loop for the end of the string*/
	{
		CLCD_voidSendCharacter(Copy_string[localcounter]);	/*SEnd string char by char*/
		localcounter++; /*increment the char in the string var*/
	}
}
/***************************************************************************************/
/*-> NAME: 		@ void CLCD_voidClearDisplay(void)						     		   */
/*-> breif:		@ this function is used to CLEAR the display of CLCD				   */
/*-> Prameters: @ void																   */
/***************************************************************************************/
void CLCD_voidClearDisplay(void){
	CLCD_voidSendCommand(0b00000001);	/*clear display*/
}
/*********************************************************************************************/
/*-> NAME: 		@ void CLCD_voidMoveCurseor(u8 Copy_u8Line,u8 Copy_u8Grid)     		   		 */
/*-> breif:		@ this function is used to move the curseor of CLCD to a new display position*/
/*-> Prameters: @ Copy_u8Line-> the line of the new position								 */
/*				@ Copy_u8Grid-> the column in the line (the bit of the lcd)					 */
/*********************************************************************************************/
void CLCD_voidMoveCurseor(u8 Copy_u8Line,u8 Copy_u8Grid){
	u8 Local_u8Address;	/*required address of the curseor  */
	Local_u8Address=Copy_u8Grid+(Copy_u8Line*0x40);	/*converting the given address to a clcd memory address*/
	CLCD_voidSendCommand(SET_BIT(Local_u8Address,7));	/*send curseor move command*/

}
/***************************************************************************************/
/*-> NAME: 		@ void CLCD_voidSendNumber(u64 Copy_u64Number)	     				   */
/*-> breif:		@ this function is used to send a NUMBER to be displayed on the CLCD   */
/*-> Prameters: @ Copy_u64Number-> the NUMBER to be displayed on the clcd			   */
/***************************************************************************************/

void CLCD_voidSendNumber(u64 Copy_u64Number){
	u64 LocalReversedNumber=1;			/*local helper var to reverse the given number*/
	while(Copy_u64Number!=0){
		/*loop until the end of revirsing the number*/
		LocalReversedNumber=(LocalReversedNumber*10)+(Copy_u64Number%10);
		Copy_u64Number/=10;
	}
	while(LocalReversedNumber!=1){
		/*Send the number to display on CLCD*/
		CLCD_voidSendCharacter((LocalReversedNumber%10)+'0');
			LocalReversedNumber/=10;
		}
}

/***************************************************************************************/
/*-> NAME: 		@ void CLCD_voidSendNumber(u64 Copy_u64Number)	     				   */
/*-> breif:		@ this function is used to send a  SPECIAL CHARACTERto be displayed on */
/*					the CLCD(CHARCTER not in the ASCI TABLE of the CLCD) 			   */
/*-> Prameters: @ Copy_u64Number-> the NUMBER to be displayed on the clcd			   */
/***************************************************************************************/
void CLCD_voidSendSpecialCharacter(u8* Copy_pu8Pattern,u8 Copy_u8CGRAM_Adrress,u8 Copy_u8Line,u8 Copy_u8Grid){
u8 Local_u8ADDRESS=0;	/*the addres of the SPECIAL CHAR in the CLCD CGRAM*/
u8 Local_u8Counter=0;	/*counter for FOR LOOP*/

Local_u8ADDRESS=Copy_u8CGRAM_Adrress*8;					/*switch the ADDRESS to a MEMORY ADDRESS*/
CLCD_voidSendCommand(Local_u8ADDRESS+64);				/*SEND a COMMCNAD to CLCD to store the CHAr in CGRAM*/
for(Local_u8Counter=0;Local_u8Counter<8;Local_u8Counter++){
	/*STORE the PATTERN OF the SPECIAL CHAR IN CGRAM*/
	CLCD_voidSendCharacter(Copy_pu8Pattern[Local_u8Counter]);
}
CLCD_voidMoveCurseor(Copy_u8Line,Copy_u8Grid);	/*move curseor to the position wanted to display the CHAR*/
CLCD_voidSendCharacter(Copy_u8CGRAM_Adrress);	/*display the char on the CLCD*/
}
