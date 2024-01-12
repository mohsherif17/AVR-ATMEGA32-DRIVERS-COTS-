/***************************************************************************/
/************* AUTHOR: @ Muhammed Sherif Attia *****************************/
/************* FILE  : @ STEPPER_program.c     *****************************/
/************* breif : @ driver for controlling 		********************/
/*************            stepper motor with ATMEG32    ********************/
/************* DATE  : @ 31/12/2023 ****************************************/
/***************************************************************************/


/****************includes*********************/
/*Standered libs*/
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include <util/delay.h>
/*MCAL LAYER*/
#include "DIO_interface.h"
/***** stepper motor files *****/
#include "STEPPER_config.h"
#include "STEPPER_interface.h"
#include "STEPPER_private.h"
/***********************************************************************************/
/***************************Functions implementation********************************/

/*********************************************************************/
/*-> NAME: 		@ void STEPPER_voidRotateCW(u16 Copy_u16Angle)	     */
/*-> breif:		@ this function is used to control the rotation	   	 */
/*				  angle of clock wise direction of the stepper motor */
/*-> Prameters: @ Copy_u16Angle-> the angle oif rotation        	 */
/*********************************************************************/

void STEPPER_voidRotateCW(u16 Copy_u16Angle){
	u16 Local_u16AngleIttr=Copy_u16Angle/0.7031; /*calculate the number of Cycle to reach the required angel*/
	/*preforming a for loop to loop until the completion of the cycles*/
	/*each cycle consists of 4 steps*/
	for(u16 Localittr=0;Localittr<Local_u16AngleIttr;Localittr++){
		DIO_u8SetPinValue(STEPPER_PORT,STEPPER_BluePin,	 DIO_u8HIGH);  		  /*SET PIN output val = 1 to move the motor*/
		DIO_u8SetPinValue(STEPPER_PORT,STEPPER_PinkPin,	 DIO_u8LOW);   		  /*SET PIN output val = 0 to stop the motor*/
		DIO_u8SetPinValue(STEPPER_PORT,STEPPER_YellowPin,DIO_u8LOW);   		  /*SET PIN output val = 0 to stop the motor*/
		DIO_u8SetPinValue(STEPPER_PORT,STEPPER_OrangePin,DIO_u8LOW);   		  /*SET PIN output val = 0 to stop the motor*/
		_delay_us(4150); /*wait to the end of the STEP*/
		DIO_u8SetPinValue(STEPPER_PORT,STEPPER_BluePin,	 DIO_u8LOW);  		 /*SET PIN output val = 0 to stop the motor*/
		DIO_u8SetPinValue(STEPPER_PORT,STEPPER_PinkPin,	 DIO_u8HIGH); 		 /*SET PIN output val = 1 to move the motor*/
		DIO_u8SetPinValue(STEPPER_PORT,STEPPER_YellowPin,DIO_u8LOW);  		 /*SET PIN output val = 0 to stop the motor*/
		DIO_u8SetPinValue(STEPPER_PORT,STEPPER_OrangePin,DIO_u8LOW);  		 /*SET PIN output val = 0 to stop the motor*/
		_delay_us(4150); /*wait to the end of the STEP*/
		DIO_u8SetPinValue(STEPPER_PORT,STEPPER_BluePin,	 DIO_u8LOW);    	 /*SET PIN output val = 0 to stop the motor*/
		DIO_u8SetPinValue(STEPPER_PORT,STEPPER_PinkPin,	 DIO_u8LOW);    	 /*SET PIN output val = 0 to stop the motor*/
		DIO_u8SetPinValue(STEPPER_PORT,STEPPER_YellowPin,DIO_u8HIGH);   	 /*SET PIN output val = 1 to move the motor*/
		DIO_u8SetPinValue(STEPPER_PORT,STEPPER_OrangePin,DIO_u8LOW);    	 /*SET PIN output val = 0 to stop the motor*/
		_delay_us(4150); /*wait to the end of the STEP*/
		DIO_u8SetPinValue(STEPPER_PORT,STEPPER_BluePin,	 DIO_u8LOW);		/*SET PIN output val = 0 to stop the motor*/
		DIO_u8SetPinValue(STEPPER_PORT,STEPPER_PinkPin,	 DIO_u8LOW);        /*SET PIN output val = 0 to stop the motor*/
		DIO_u8SetPinValue(STEPPER_PORT,STEPPER_YellowPin,DIO_u8LOW);        /*SET PIN output val = 0 to stop the motor*/
		DIO_u8SetPinValue(STEPPER_PORT,STEPPER_OrangePin,DIO_u8HIGH);       /*SET PIN output val = 1 to move the motor*/
		_delay_us(4150); /*wait to the end of the STEP*/
	}
}

/*****************************************************************************/
/*-> NAME: 		@ void STEPPER_voidRotateCCW(u16 Copy_u16Angle)	     		 */
/*-> breif:		@ this function is used to control the rotation	   			 */
/*				  angle of counter clock wise direction of the stepper motor */
/*-> Prameters: @ Copy_u16Angle-> the angle oif rotation  			      	 */
/*****************************************************************************/
void STEPPER_voidRotateCCW(u16 Copy_u16Angle){
	u16 Local_u16AngleIttr=Copy_u16Angle/0.7031;      /*calculate the number of Cycle to reach the required angel*/
		/*preforming a for loop to loop until the completion of the cycles*/
			/*each cycle consists of 4 steps*/
		for(u16 Localittr=0;Localittr<Local_u16AngleIttr;Localittr++){
			DIO_u8SetPinValue(STEPPER_PORT,STEPPER_BluePin,	 DIO_u8LOW); 			 /*SET PIN output val = 0 to stop the motor*/
			DIO_u8SetPinValue(STEPPER_PORT,STEPPER_PinkPin,	 DIO_u8LOW); 			 /*SET PIN output val = 0 to stop the motor*/
			DIO_u8SetPinValue(STEPPER_PORT,STEPPER_YellowPin,DIO_u8LOW); 			 /*SET PIN output val = 0 to stop the motor*/
			DIO_u8SetPinValue(STEPPER_PORT,STEPPER_OrangePin,DIO_u8HIGH);			 /*SET PIN output val = 1 to move the motor*/
			_delay_us(4150); /*wait to the end of the STEP*/
			DIO_u8SetPinValue(STEPPER_PORT,STEPPER_BluePin,	 DIO_u8LOW);            /*SET PIN output val = 0 to stop the motor*/
			DIO_u8SetPinValue(STEPPER_PORT,STEPPER_PinkPin,	 DIO_u8LOW);            /*SET PIN output val = 0 to stop the motor*/
			DIO_u8SetPinValue(STEPPER_PORT,STEPPER_YellowPin,DIO_u8HIGH);           /*SET PIN output val = 1 to move the motor*/
			DIO_u8SetPinValue(STEPPER_PORT,STEPPER_OrangePin,DIO_u8LOW);            /*SET PIN output val = 0 to stop the motor*/
			_delay_us(4150); /*wait to the end of the STEP*/
			DIO_u8SetPinValue(STEPPER_PORT,STEPPER_BluePin,	 DIO_u8LOW);           /*SET PIN output val = 0 to stop the motor*/
			DIO_u8SetPinValue(STEPPER_PORT,STEPPER_PinkPin,	 DIO_u8HIGH);          /*SET PIN output val = 1 to move the motor*/
			DIO_u8SetPinValue(STEPPER_PORT,STEPPER_YellowPin,DIO_u8LOW);           /*SET PIN output val = 0 to stop the motor*/
			DIO_u8SetPinValue(STEPPER_PORT,STEPPER_OrangePin,DIO_u8LOW);           /*SET PIN output val = 0 to stop the motor*/
			_delay_us(4150); /*wait to the end of the STEP*/
			DIO_u8SetPinValue(STEPPER_PORT,STEPPER_BluePin,	 DIO_u8HIGH);         /*SET PIN output val = 1 to move the motor*/
			DIO_u8SetPinValue(STEPPER_PORT,STEPPER_PinkPin,	 DIO_u8LOW);          /*SET PIN output val = 0 to stop the motor*/
			DIO_u8SetPinValue(STEPPER_PORT,STEPPER_YellowPin,DIO_u8LOW);          /*SET PIN output val = 0 to stop the motor*/
			DIO_u8SetPinValue(STEPPER_PORT,STEPPER_OrangePin,DIO_u8LOW);          /*SET PIN output val = 0 to stop the motor*/
			_delay_us(4150); /*wait to the end of the STEP*/
		/*compelete cycle*/
		}
}

/*********************************************************************/
/*-> NAME: 		@ void STEPPER_voidStop(void)					     */
/*-> breif:		@ this function is used to STOP STEPPER MOTOR	   	 */
/*-> Prameters: @ void									        	 */
/*********************************************************************/
void STEPPER_voidStop(void){
			    DIO_u8SetPinValue(STEPPER_PORT,STEPPER_BluePin,	 DIO_u8LOW);         /*SET PIN output val = 0 to stop the motor*/
				DIO_u8SetPinValue(STEPPER_PORT,STEPPER_PinkPin,	 DIO_u8LOW);         /*SET PIN output val = 0 to stop the motor*/
				DIO_u8SetPinValue(STEPPER_PORT,STEPPER_YellowPin,DIO_u8LOW);         /*SET PIN output val = 0 to stop the motor*/
				DIO_u8SetPinValue(STEPPER_PORT,STEPPER_OrangePin,DIO_u8LOW);         /*SET PIN output val = 0 to stop the motor*/
}
