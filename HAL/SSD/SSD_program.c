/***************************************************************************/
/************* AUTHOR: @ Muhammed Sherif Attia *****************************/
/************* FILE  : @ STEPPER_program.c     *****************************/
/************* breif : @ driver for controlling 		********************/
/*************            seven segment with ATMEG32    ********************/
/************* DATE  : @ 31/12/2023 ****************************************/
/***************************************************************************/

/****************includes*********************/
/*Standered libs*/
#include"STD_TYPES.h"
#include"BIT_MATH.h"
/*MCAL LAYER*/
#include"DIO_interface.h"
/*SSD FILES*/
#include"SSD_private.h"
#include"SSD_interface.h"
#include"SSD_config.h"
/********************************************/

/****************GLOBAL VAR*********************/
u8 SSD_arr[10]=
	      {
	    		  0b00111111,        //0
				  0b00000110,        //1
				  0b01011011,        //2
				  0b01001111,        //3
				  0b01100110,        //4
				  0b01101101,        //5
				  0b01111101,        //6
				  0b00000111,        //7
				  0b01111111,        //8
				  0b01101111         //9
	      };
/********************************************/
/***********************************************************************************/
/***************************Functions implementation********************************/

/***************************************************************************************/
/*-> NAME: 		@ u8 SSD_u8SendData(SSD_T* SSD_Configrations)	     				   */
/*-> breif:		@ this function is used to display numbers on 7SeGMENT DDISPLAY	   	   */
/*-> Prameters: @ SSD_T* SSD_Configrations-> pointer to struct of the SSD CONFIGRAYIONS*/
/***************************************************************************************/
u8 SSD_u8SendData(SSD_T* SSD_Configrations){
	u8 Local_u8ErrorState= OK;
	/*Check error state if the ptr to struct is empty*/
	if(SSD_Configrations==NULL){
		Local_u8ErrorState=NOK;
	}
	else{
		/*detect the type of the SSD*/
	switch (SSD_Configrations->SSD_TYPE){
	case COMCATH:{
					DIO_u8SetPinDirection(SSD_Configrations->SSD_ENABLE_PORT,SSD_Configrations->SSD_ENABLE_PIN,DIO_u8OUTPUT);		/*Set the SSD Enable PIN as output */
					DIO_u8SetPinValue(SSD_Configrations->SSD_ENABLE_PORT,SSD_Configrations->SSD_ENABLE_PIN,DIO_u8LOW);				/*Set the SSD Enable PIN val = 0 to enable the COMCATH ssd */
					DIO_u8SetPortDirection(SSD_Configrations->SSD_PORT,DIO_u8ALL_OUTPUT);											/*Set SSD PORT as OUTPUT*/
					DIO_u8SetPortValue(SSD_Configrations->SSD_PORT,SSD_arr[SSD_Configrations->SSD_NUM]);							/*Send the data number*/
					break;
				}
	case COMANNO:{
						DIO_u8SetPinDirection(SSD_Configrations->SSD_ENABLE_PORT,SSD_Configrations->SSD_ENABLE_PIN,DIO_u8OUTPUT);  /*Set the SSD Enable PIN as output */
						DIO_u8SetPinValue(SSD_Configrations->SSD_ENABLE_PORT,SSD_Configrations->SSD_ENABLE_PIN,DIO_u8HIGH);        /*Set the SSD Enable PIN val = 1 to enable the COMANNO ssd */
						DIO_u8SetPortDirection(SSD_Configrations->SSD_PORT,DIO_u8ALL_OUTPUT);                                      /*Set SSD PORT as OUTPUT*/
						DIO_u8SetPortValue(SSD_Configrations->SSD_PORT,~SSD_arr[SSD_Configrations->SSD_NUM]);                      /*Send the data number*/
						break;
					}
	default: {Local_u8ErrorState= NOK; break;}  /*error state*/
	}
	}
return Local_u8ErrorState;			/*return error state if somethong goes wrong*/
}
