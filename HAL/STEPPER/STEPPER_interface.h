/***************************************************************************/
/************* AUTHOR: @ Muhammed Sherif Attia *****************************/
/************* FILE  : @ STEPPER_interface.h   *****************************/
/************* breif : @ driver for controlling 		********************/
/*************            stepper motor with ATMEG32    ********************/
/************* DATE  : @ 31/12/2023 ****************************************/
/***************************************************************************/

#ifndef STEPPER_INTERFACE_H_
#define STEPPER_INTERFACE_H_
/****************includes*********************/
/*********************************************/

/****************defines*********************/

/*******************************************/


/*********************************** FUNCTIONS PROTOTYPES *****************************/
/*********************************************************************/
/*-> NAME: 		@ void STEPPER_voidRotateCW(u16 Copy_u16Angle)	     */
/*-> breif:		@ this function is used to control the rotation	   	 */
/*				  angle of clock wise direction of the stepper motor */
/*-> Prameters: @ Copy_u16Angle-> the angle oif rotation        	 */
/*********************************************************************/
void STEPPER_voidRotateCW(u16 Copy_u16Angle);

/*****************************************************************************/
/*-> NAME: 		@ void STEPPER_voidRotateCCW(u16 Copy_u16Angle)	     		 */
/*-> breif:		@ this function is used to control the rotation	   			 */
/*				  angle of counter clock wise direction of the stepper motor */
/*-> Prameters: @ Copy_u16Angle-> the angle oif rotation  			      	 */
/*****************************************************************************/
void STEPPER_voidRotateCCW(u16 Copy_u16Angle);

/*********************************************************************/
/*-> NAME: 		@ void STEPPER_voidStop(void)					     */
/*-> breif:		@ this function is used to STOP STEPPER MOTOR	   	 */
/*-> Prameters: @ void									        	 */
/*********************************************************************/
void STEPPER_voidStop(void);

#endif /* STEPPER_INTERFACE_H_ */
