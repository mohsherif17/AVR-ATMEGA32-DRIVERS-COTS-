/***************************************************************************/
/************* AUTHOR: @ Muhammed Sherif Attia *****************************/
/************* FILE  : @ STEPPER_interface.h    *****************************/
/************* breif : @ driver for controlling 		********************/
/*************            seven segment with ATMEG32    ********************/
/************* DATE  : @ 31/12/2023 ****************************************/
/***************************************************************************/

#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_

/****************includes*********************/
/*********************************************/

/****************defines*********************/
#define COMCATH   0
#define COMANNO 1

/*********************************************/

/**********USER DEFINEID DATA TYPES***********/
/*configrations of the 7 segment*/
typedef struct{
	u8 SSD_TYPE;				/*type of the ssd COMMON CATHOD/ANNODE*/
	u8 SSD_ENABLE_PORT;			/*port of enable pin connection*/
	u8 SSD_ENABLE_PIN;			/*number for the enable pin*/
	u8 SSD_PORT;				/*the port of the ssd data pins*/
	u8 SSD_NUM;					/*number to be displayed*/
}SSD_T;
/*********************************************/

/************FUNCTIONS PROTOTYPES*************/

/***************************************************************************************/
/*-> NAME: 		@ u8 SSD_u8SendData(SSD_T* SSD_Configrations)	     				   */
/*-> breif:		@ this function is used to display numbers on 7SeGMENT DDISPLAY	   	   */
/*-> Prameters: @ SSD_T* SSD_Configrations-> pointer to struct of the SSD CONFIGRAYIONS*/
/***************************************************************************************/
u8 SSD_u8SendData(SSD_T* SSD_Configrations);
/*********************************************/

#endif /* SSD_INTERFACE_H_ */
