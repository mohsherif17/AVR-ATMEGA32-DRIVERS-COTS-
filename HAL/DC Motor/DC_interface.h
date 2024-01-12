/***************************************************************************/
/************* AUTHOR: @ Muhammed Sherif Attia *****************************/
/************* FILE  : @ DC_interface.h     *****************************/
/************* breif : @ driver for controlling 		********************/
/*************            DC MOTOR with ATMEG32    ********************/
/************* DATE  : @ 31/12/2023 ****************************************/
/***************************************************************************/

#ifndef DC_INTERFACE_H_
#define DC_INTERFACE_H_


/**********************************************************************************/
/*-> NAME: 		@ void DC_voidRotateClockWise(void)	     				       	  */
/*-> breif:		@ this function is used to rotate a dc motor clock wise direction */
/*-> Prameters: @ void															  */
/**********************************************************************************/
void DC_voidRotateClockWise(void);

/******************************************************************************************/
/*-> NAME: 		@ void DC_voidRotateCounterClockWise(void)	     				       	  */
/*-> breif:		@ this function is used to rotate a dc motor counter clock wise direction */
/*-> Prameters: @ void																	  */
/******************************************************************************************/
void DC_voidRotateCounterClockWise(void);

/**********************************************************************/
/*-> NAME: 		@ void DC_voidStop(void)	     			     	  */
/*-> breif:		@ this function is used to STOP THE DC motor   		  */
/*-> Prameters: @ void												  */
/**********************************************************************/
void DC_voidStop(void);

#endif /* DC_INTERFACE_H_ */
