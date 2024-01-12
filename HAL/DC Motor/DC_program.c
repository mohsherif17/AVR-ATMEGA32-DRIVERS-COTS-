/***************************************************************************/
/************* AUTHOR: @ Muhammed Sherif Attia *****************************/
/************* FILE  : @ DC_program.c     *****************************/
/************* breif : @ driver for controlling 		********************/
/*************            DC MOTOR with ATMEG32    ********************/
/************* DATE  : @ 31/12/2023 ****************************************/
/***************************************************************************/

/****************includes*********************/
/*Standered libs*/
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include<util/delay.h>
/*MCAL LAYER*/
#include"DIO_interface.h"
/*DC MOTOR FILES*/
#include"DC_config.h"
#include"DC_interface.h"
#include"DC_private.h"



/***********************************************************************************/
/***************************Functions implementation********************************/

/**********************************************************************************/
/*-> NAME: 		@ void DC_voidRotateClockWise(void)	     				       	  */
/*-> breif:		@ this function is used to rotate a dc motor clock wise direction */
/*-> Prameters: @ void															  */
/**********************************************************************************/
void DC_voidRotateClockWise(void){
	DIO_u8SetPinValue(DC_u8PORT,DC_u8PIN2,DIO_u8LOW);      	/*set MOTOR PIN1 = 1 to rotate the motor CW  */
	DIO_u8SetPinValue(DC_u8PORT,DC_u8PIN1,DIO_u8HIGH);        /*set MOTOR PIN2 = 1  to DISABLE CCW rotation*/
}
/******************************************************************************************/
/*-> NAME: 		@ void DC_voidRotateCounterClockWise(void)	     				       	  */
/*-> breif:		@ this function is used to rotate a dc motor counter clock wise direction */
/*-> Prameters: @ void																	  */
/******************************************************************************************/
void DC_voidRotateCounterClockWise(void){
	DIO_u8SetPinValue(DC_u8PORT,DC_u8PIN1,DIO_u8LOW);		/*set MOTOR PIN1 = 0 to disable CW rotation */
	DIO_u8SetPinValue(DC_u8PORT,DC_u8PIN2,DIO_u8HIGH);     /*set MOTOR PIN2 = 1  to rotate the motor CCW*/
}

/**********************************************************************/
/*-> NAME: 		@ void DC_voidStop(void)	     			     	  */
/*-> breif:		@ this function is used to STOP THE DC motor   		  */
/*-> Prameters: @ void												  */
/**********************************************************************/
void DC_voidStop(void){
	DIO_u8SetPinValue(DC_u8PORT,DC_u8PIN1,DIO_u8LOW);		/*set MOTOR PIN1 = 0 to stop the rotation*/
	DIO_u8SetPinValue(DC_u8PORT,DC_u8PIN2,DIO_u8LOW);		/*set MOTOR PIN2 = 0 to stop the rotation*/
}
