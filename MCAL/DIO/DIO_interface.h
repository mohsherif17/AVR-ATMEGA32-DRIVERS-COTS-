/***************************************************************************/
/************* AUTHOR: @ Muhammed Sherif Attia *****************************/
/************* FILE  : @ DIO_interface.h       *****************************/
/************* breif : @ The interface.h file for 		********************/
/*************           the Digital i/o prephilral of atmega32 ************/
/************* DATE  : @ 31/12/2023 ****************************************/
/***************************************************************************/


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_
/****************includes*********************/
/*********************************************/

/****************defines*********************/

/*******************************************/
/* -> DIO PIN MODE OPTIONS                */
/******************************************/
#define     DIO_u8INPUT          	   0
#define     DIO_u8OUTPUT           	   1

/*******************************************/
/* -> DIO PORT MODE OPTIONS               */
/******************************************/
#define     DIO_u8ALL_INPUT            0
#define     DIO_u8ALL_OUTPUT           0xFF

/*******************************************/
/* -> DIO PIN VALUE OPTIONS               */
/******************************************/
#define     DIO_u8LOW         	       0
#define     DIO_u8HIGH            	   1

/*******************************************/
/* -> DIO PORT VALUE OPTIONS               */
/******************************************/
#define     DIO_u8ALL_LOW              0
#define     DIO_u8AAL_HIGH             0xFF

/*******************************************/
/* -> DIO PORT NAME OPTIONS                */
/******************************************/
#define		DIO_u8PORTA			   	   1
#define		DIO_u8PORTB			  	   2
#define		DIO_u8PORTC			   	   3
#define		DIO_u8PORTD			   	   4

/*******************************************/
/* -> DIO PIN NAME OPTIONS                */
/******************************************/
#define     DIO_u8PIN0                 0
#define     DIO_u8PIN1                 1
#define     DIO_u8PIN2                 2
#define     DIO_u8PIN3                 3
#define     DIO_u8PIN4                 4
#define     DIO_u8PIN5                 5
#define     DIO_u8PIN6                 6
#define     DIO_u8PIN7                 7

/*********************************************/

/**********USER DEFINEID DATA TYPES**********/
/*********************************************/

/*******FUNCTIONS PROTOTYPES********/

/*********************************************************/
/*-> NAME: 		@ void DIO_u8initialize(void)		     */
/*-> breif:		@ this function is used when using 	   	 */
/*				  the pre build config module of the DIO */
/*-> Prameters: @ void							       	 */
/*													   	 */
/*********************************************************/
void DIO_u8initialize(void);

/*********************************************************************************************************/
/*-> NAME: 		@ u8 DIO_u8SetPinDirection(u8 Copy_u8PORT,u8 Copy_u8Pin,u8 Copy_u8Direction);	         */
/*-> breif:		@ this function is used to set the direction of a certin PIN from a certin   	         */
/*				  PORT whether to be INPUT OR OUTPUT										 			 */
/*				  The functio returns u8 var Holding the error state of the function call OK/NOK		 */
/*-> Prameters: @ u8 Copy_u8PORT -> the name of the required Port	         (DIO_u8PORTA:DIO_u8PORTD)	 */
/*				@ u8 Copy_u8Pin	 -> The number of the selected pin to be set (DIO_u8PIN0:DIO_u8PIN7) 	 */
/*				@ u8 Copy_u8Direction -> the SELECTED Direction of the Pin 	 (DIO_u8INPUT/DIO_u8OUPUT) 	 */
/*********************************************************************************************************/
u8 DIO_u8SetPinDirection(u8 Copy_u8PORT,u8 Copy_u8Pin,u8 Copy_u8Direction);

/*********************************************************************************************************/
/*-> NAME: 		@ u8 DIO_u8SetPinValue(u8 Copy_u8PORT,u8 Copy_u8Pin,u8 Copy_u8Value);	  		         */
/*-> breif:		@ this function is used to set the Value of a certin PIN from a certin   	      	     */
/*				  PORT whether to be High/LOW after it`s directio is set					 			 */
/*				  The functio returns u8 var Holding the error state of the function call OK/NOK		 */
/*-> Prameters: @ u8 Copy_u8PORT  -> the name of the required Port	         (DIO_u8PORTA:DIO_u8PORTD)	 */
/*				@ u8 Copy_u8Pin	  -> The number of the selected pin to be set (DIO_u8PIN0:DIO_u8PIN7) 	 */
/*				@ u8 Copy_u8Value -> the SELECTED value for the Pin 	     (DIO_u8LOW/DIO_u8HIGH) 	 */
/*********************************************************************************************************/
u8 DIO_u8SetPinValue(u8 Copy_u8PORT,u8 Copy_u8Pin,u8 Copy_u8Value);

/*********************************************************************************************************/
/*-> NAME: 		@ u8 DIO_u8GetPinValue(u8 Copy_u8PORT,u8 Copy_u8Pin,u8* Copy_pu8Value);	  		         */
/*-> breif:		@ this function is used to Get the Value of a certin PIN from a certin   	      	     */
/*				  PORT whether to be High/LOW after it`s directio is set					 			 */
/*				  The functio returns u8 var Holding the error state of the function call OK/NOK		 */
/*-> Prameters: @ u8 Copy_u8PORT  -> the name of the required Port	         (DIO_u8PORTA:DIO_u8PORTD)	 */
/*				@ u8 Copy_u8Pin	  -> The number of the selected pin to be set (DIO_u8PIN0:DIO_u8PIN7) 	 */
/*				@ u8 Copy_pu8Value -> Pointer to recive the value for the Pin (DIO_u8LOW/DIO_u8HIGH) 	 */
/*********************************************************************************************************/
u8 DIO_u8GetPinValue(u8 Copy_u8PORT,u8 Copy_u8Pin,u8* Copy_pu8Value);



/*********************************************************************************************************/
/*-> NAME: 		@ u8 DIO_u8SetPortDirection(u8 Copy_u8PORT,u8 Copy_u8Direction);	         			 */
/*-> breif:		@ this function is used to set the direction of an entire PORT 		(INPUT/OUTPUT)       */
/*				  The functio returns u8 var Holding the error state of the function call (OK/NOK)		 */
/*-> Prameters: @ u8 Copy_u8PORT -> the name of the required Port	         (DIO_u8PORTA:DIO_u8PORTD)	 */
/*				@ u8 Copy_u8Direction -> the Direction of the PORT	   (DIO_u8ALL_INPUT/DIO_u8ALL_OUTPUT)*/
/*********************************************************************************************************/
u8 DIO_u8SetPortDirection(u8 Copy_u8PORT,u8 Copy_u8Direction);

/*********************************************************************************************************/
/*-> NAME: 		@ u8 DIO_u8SetPortValue(u8 Copy_u8PORT,u8 Copy_u8Value);				  		         */
/*-> breif:		@ this function is used to set the Value of an entire PORT whether to be High/LOW 		 */
/*				  The functio returns u8 var Holding the error state of the function call OK/NOK		 */
/*-> Prameters: @ u8 Copy_u8PORT  -> the name of the required Port	         (DIO_u8PORTA:DIO_u8PORTD)	 */
/*				@ u8 Copy_u8Value -> the SELECTED value for the Pin 	     (DIO_u8ALLLOW/DIO_u8ALLHIGH)*/
/*********************************************************************************************************/
u8 DIO_u8SetPortValue(u8 Copy_u8PORT,u8 Copy_u8Value);

/*********************************************************************************************************/
/*-> NAME: 		@ u8 DIO_u8GetPortValue(u8 Copy_u8PORT,u8* Copy_pu8Value);			 	  		         */
/*-> breif:		@ this function is used to Get the Value of PORT whether to be High/LOW 				 */
/*				  The functio returns u8 var Holding the error state of the function call OK/NOK		 */
/*-> Prameters: @ u8 Copy_u8PORT  -> the name of the required Port	         (DIO_u8PORTA:DIO_u8PORTD)	 */
/*				@ u8 Copy_pu8Value -> Pointer to recive the value of the PORT (DIO_u8LOW/DIO_u8HIGH) 	 */
/*********************************************************************************************************/
u8 DIO_u8GetPortValue(u8 Copy_u8PORT,u8* Copy_pu8Value);

/*********************************************************************************************************/
#endif /* DIO_INTERFACE_H_ */
