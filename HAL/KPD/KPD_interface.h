/****************************************************************************/
/************* AUTHOR: @ Muhammed Sherif Attia ******************************/
/************* FILE  : @ KPD_interface.h    	*****************************/
/************* breif : @ driver for controlling 		*********************/
/*************            KEYPAD with ATMEG32  		  ***********************/
/************* DATE  : @ 31/12/2023 *****************************************/
/****************************************************************************/

#ifndef KPD_INTERFACE_H_
#define KPD_INTERFACE_H_

/** defines **/
#define KPD_NotPRESSED          255	

		
/******************************** functions prototypes ************************************************/
/**********************************************************************/
/*-> NAME: 		@ void KPD_voidInit(void)						      */
/*-> breif:		@ this function is used to intialize KPD CONFIGRATIONS*/
/*-> Prameters: @ void									           	  */
/**********************************************************************/
void KPD_voidInit(void);

/*********************************************************************/
/*-> NAME: 		@ u8 KPD_u8GetPressedKey(void)					     */
/*-> breif:		@ this function is used to read the pressed key value*/
/*				@ returns a u8 Data of the value of pressed key      */
/*-> Prameters: @ void									           	 */
/*********************************************************************/
u8 KPD_u8GetPressedKey(void);




#endif /* KPD_INTERFACE_H_ */
