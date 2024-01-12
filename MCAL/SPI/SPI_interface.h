/***************************************************************************/
/************* AUTHOR: @ Muhammed Sherif Attia *****************************/
/************* FILE  : @ SPI_interface.h       *****************************/
/************* breif : @ The interface.h file for 		********************/
/*************           the SPI Communication protocol in atmega32   ******/
/************* DATE  : @ 31/12/2023 ****************************************/
/***************************************************************************/

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_
/****************includes*********************/
/*********************************************/

/****************defines*********************/

/*******************************************/


/*******FUNCTIONS PROTOTYPES********/

/************************************************************************************************************/
/* -> NAME:           @ void SPI_voidINITIALIZE(void)														*/
/* -> DESCRIBTION:    @ this function is used to initialize the SPI COUMMUNICATION PROTOCOL				    */
/* -> Parameters: 	   @ void																				*/
/************************************************************************************************************/
void SPI_voidINITIALIZE(void);


/************************************************************************************************************/
/* -> NAME:           @ u8 SPI_u8MasterSend(u8 Copy_u8data)													*/
/* -> DESCRIBTION:    @ this function is used to send data from the Master of SPI connection			    */
/* -> Parameters: 	   @ u8 Copy_u8data: the data to be sent to the slave									*/
/************************************************************************************************************/
u8 SPI_u8MasterSend(u8 Copy_u8data);

/************************************************************************************************************/
/* -> NAME:           @ void SPI_voidEnableInterrupt(void);													*/
/* -> DESCRIBTION:    @ this function is used to Enable interrupt of SPI connection			    			*/
/* -> Parameters: 	   @ void 																				*/
/************************************************************************************************************/
void SPI_voidEnableInterrupt(void);

/************************************************************************************************************/
/* -> NAME:           @ void SPI_voidDisableInterrupt(void);												*/
/* -> DESCRIBTION:    @ this function is used to Disable interrupt of SPI connection		    			*/
/* -> Parameters: 	   @ void 																				*/
/************************************************************************************************************/
void SPI_voidDisableInterrupt(void);
/************************************************************************************************************/
/* -> NAME:           @ void SPI_voidSetCallBack(void(*Copy_pvoidCallBack)(void));							*/
/* -> DESCRIBTION:    @ this function is used to set ISR function for the SPI interrupt		    			*/
/* -> Parameters: 	   @ void(*Copy_pvoidCallBack)(void) -> pointer to the call back function for the ISR	*/
/************************************************************************************************************/
void SPI_voidSetCallBack(void(*Copy_pvoidCallBack)(void));




#endif /* SPI_INTERFACE_H_ */
