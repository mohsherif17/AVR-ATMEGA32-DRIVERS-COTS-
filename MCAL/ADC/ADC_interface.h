/***************************************************************************/
/************* AUTHOR: @ Muhammed Sherif Attia *****************************/
/************* FILE  : @ ADC_interface.h       *****************************/
/************* breif : @ The interface.h file for 		********************/
/*************           the Analog to digital of atmega32 *****************/
/************* DATE  : @ 31/12/2023 ****************************************/
/***************************************************************************/

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

/****************includes*********************/
/*********************************************/

/****************defines*********************/
#define   CHANNEL0 								0
#define   CHANNEL1 								1
#define   CHANNEL2 								2
#define   CHANNEL3 								3
#define   CHANNEL4 								4
#define   CHANNEL5 								5
#define   CHANNEL6 								6
#define   CHANNEL7 								7
/*********************************************/




/*********************************************/

/************FUNCTIONS PROTOTYPES*************/

/**********************************************************/
/*-> NAME: 		@ void ADC_voidINIT(void);			      */
/*-> breif:		@ this function is used to intialize  	  */
/*				  the ADC Prepheral and set its PreScaler,*/
/*				  select adjustment and vref   		   	  */
/*-> Prameters: @ void							       	  */
/*													   	  */
/**********************************************************/
void ADC_voidINIT(void);

/****************************************************************/
/*-> NAME: 		@ u16 ADC_u16ReadChannel(u8 Copy_u8Channel);    */
/*-> breif:		@ this function is used to Read the value  	    */
/*				  From a pin in the ADC Prepheral 			    */
/*				@ this function return a u16 value represents   */
/*				   the ADC pin Value					        */
/*-> Prameters: @ u8 Copy_u8Channel	-> the number of the ADC PIN*/
/****************************************************************/
u16 ADC_u16ReadChannel(u8 Copy_u8Channel);

#endif /* ADC_INTERFACE_H_ */
