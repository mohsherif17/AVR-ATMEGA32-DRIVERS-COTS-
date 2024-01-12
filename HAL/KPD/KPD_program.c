/****************************************************************************/
/************* AUTHOR: @ Muhammed Sherif Attia ******************************/
/************* FILE  : @ KPD_program.c     		*****************************/
/************* breif : @ driver for controlling 		*********************/
/*************            KEYPAD with ATMEG32  		  ***********************/
/************* DATE  : @ 31/12/2023 *****************************************/
/****************************************************************************/


/****************includes*********************/
/*Standered libs*/
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include<util/delay.h>
/*MCAL LAYER*/
#include"DIO_interface.h"
/*KPD FILES*/
#include"KPD_confige.h"
#include"KPD_interface.h"
#include"KPD_private.h"
/***********************************************************************************/
/***************************Functions implementation********************************/



/**********************************************************************/
/*-> NAME: 		@ void KPD_voidInit(void)						      */
/*-> breif:		@ this function is used to intialize KPD CONFIGRATIONS*/
/*-> Prameters: @ void									           	  */
/**********************************************************************/
void KPD_voidInit(void){
	/*Activate pull up for rows and initialize the columns with high*/
	DIO_u8SetPortValue(KPD_PORT,DIO_u8ALL_HIGH);
}

/****************************************************************************/
/*********************************************************************/
/*-> NAME: 		@ u8 KPD_u8GetPressedKey(void)					     */
/*-> breif:		@ this function is used to read the pressed key value*/
/*				@ returns a u8 Data of the value of pressed key      */
/*-> Prameters: @ void									           	 */
/*********************************************************************/
u8 KPD_u8GetPressedKey(void){
	u8 Loclal_u8PressedKey=KPD_NotPRESSED;		/*varibale to store the pressed key value*/
	u8 Local_u8PinValue;						/*variable to avoid debouncing error*/
	u8 Local_u8KPDarr[4][4]={{1 ,2 ,3 ,4 },
							 {5 ,6 ,7 ,8 },
							 {9 ,10,11,12},
							 {13,14,15,16}};	/*array holds the value of keypad matrix*/

	/*looping on the coulumns of the matrix*/
	for(u8 KPD_COLOUMN=0 ; KPD_COLOUMN<4;KPD_COLOUMN++){
		DIO_u8SetPinValue(KPD_PORT,KPD_COLOUMN,DIO_u8LOW);						/*set coulmn pin with 0 to read value */
		/*looping on the rows of the matrix*/
		for(u8 KPD_ROW=0;KPD_ROW<4;KPD_ROW++){
			DIO_u8GetPinValue(KPD_PORT,KPD_ROW+4,&Local_u8PinValue);			/*read row pin value to detect the key position in the KPD*/
			if(Local_u8PinValue==0){
				Loclal_u8PressedKey=Local_u8KPDarr[KPD_ROW][KPD_COLOUMN];		/*get the value of the key from the array*/
				_delay_ms(3);
				while(Local_u8PinValue==0){
					/*wait to avoid debouncing error*/
					DIO_u8GetPinValue(KPD_PORT,KPD_ROW+4,&Local_u8PinValue);
				}
				/*_delay_ms(250);*/
			}
		}
		DIO_u8SetPinValue(KPD_PORT,KPD_COLOUMN,DIO_u8HIGH);						/*set coulmn pin with 1 to switch the coulmn */
	}
	return Loclal_u8PressedKey;								/*return pressed key value */
}
