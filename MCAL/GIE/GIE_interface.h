/***************************************************************************/
/************* AUTHOR: @ Muhammed Sherif Attia *****************************/
/************* FILE  : @ GIE_interface.h       *****************************/
/************* breif : @ The interface.h file for 		********************/
/*************           the General interrupt of atmega32 *****************/
/************* DATE  : @ 31/12/2023 ****************************************/
/***************************************************************************/

#ifndef GIE_INTERFACE_H_
#define GIE_INTERFACE_H_
/****************includes*********************/
/*********************************************/

/****************defines*********************/
/*******************************************/

/*******FUNCTIONS PROTOTYPES********/

/********************************************************************/
/*-> NAME: 		@ void GIE_voidEnable(void)		  		   			*/
/*-> breif:		@ this function is used to enable General Interrupt */
/*-> Prameters: @ void							       	 			*/
/********************************************************************/
void GIE_voidEnable(void);

/********************************************************************/
/*-> NAME: 		@ void GIE_voidDisable(void)	  		   			*/
/*-> breif:		@ this function is used to Disable General Interrupt*/
/*-> Prameters: @ void							       	 			*/
/********************************************************************/
void GIE_voidDisable(void);


#endif /* GIE_INTERFACE_H_ */
