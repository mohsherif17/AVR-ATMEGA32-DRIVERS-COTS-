/***************************************************************************/
/************* AUTHOR: @ Muhammed Sherif Attia *****************************/
/************* FILE  : @ DIO_program.c         *****************************/
/************* breif : @ The program.c file for 		********************/
/*************           the Digital i/o prephilral of atmega32 ************/
/************* DATE  : @ 31/12/2023 ****************************************/
/***************************************************************************/

/***********************************includes*****************************************/
/***** standard libs *****/
#include"STD_TYPES.h"
#include"BIT_MATH.h"
/***** DIO files *****/
#include"DIO_register.h"
#include"DIO_private.h"
#include"DIO_interface.h"
#include"DIO_config.h"

/***********************************************************************************/
/***************************Functions implementation********************************/

/*********************************************************/
/*-> NAME: 		@ void DIO_u8initialize(void)		     */
/*-> breif:		@ this function is used when using 	   	 */
/*				  the pre build config module of the DIO */
/*-> Prameters: @ void							       	 */
/*													   	 */
/*********************************************************/
void DIO_u8initialize(void){
/*intialize the values of the DDRx register selected in the pre build config filer (DIO_config.h)*/
DDRA=	PORTA_DIRECTION;
DDRB=	PORTB_DIRECTION;
DDRC=   PORTC_DIRECTION;
DDRD=	PORTD_DIRECTION;
/*intialize the values of the PORTx register selected in the pre build config filer (DIO_config.h)*/
PORTA=	PORTA_INITIAL_VALUE;
PORTB=	PORTB_INITIAL_VALUE;
PORTC=	PORTC_INITIAL_VALUE;
PORTD=	PORTD_INITIAL_VALUE;
}
/******************************************************************************************************************************************************************************************************************/

/*********************************************************************************************************/
/*-> NAME: 		@ u8 DIO_u8SetPinDirection(u8 Copy_u8PORT,u8 Copy_u8Pin,u8 Copy_u8Direction);	         */
/*-> breif:		@ this function is used to set the direction of a certin PIN from a certin   	         */
/*				  PORT whether to be INPUT OR OUTPUT										 			 */
/*				  The functio returns u8 var Holding the error state of the function call OK/NOK		 */
/*-> Prameters: @ u8 Copy_u8PORT -> the name of the required Port	         (DIO_u8PORTA:DIO_u8PORTD)	 */
/*				@ u8 Copy_u8Pin	 -> The number of the selected pin to be set (DIO_u8PIN0:DIO_u8PIN7) 	 */
/*				@ u8 Copy_u8Direction -> the SELECTED Direction of the Pin 	 (DIO_u8INPUT/DIO_u8OUPUT) 	 */
/*********************************************************************************************************/
u8 DIO_u8SetPinDirection(u8 Copy_u8PORT,u8 Copy_u8Pin,u8 Copy_u8Direction){
	u8 Local_u8ErrorState= OK;											/*local var to read the error state*/
	/*check for the in range pin number if correct */
	if(8>Copy_u8Pin){
		/*check the Direction of pin if input*/
		if(DIO_u8INPUT==Copy_u8Direction){
			/*check on the port name to select which port*/
			switch (Copy_u8PORT){
				case DIO_u8PORTA:CLR_BIT(DDRA,Copy_u8Pin);break; 		/*CLEARING the bit corresponding to the pin in DDRA reg to set as input*/
				case DIO_u8PORTB:CLR_BIT(DDRB,Copy_u8Pin);break; 		/*CLEARING the bit corresponding to the pin in DDRB reg to set as input*/
				case DIO_u8PORTC:CLR_BIT(DDRC,Copy_u8Pin);break; 		/*CLEARING the bit corresponding to the pin in DDRC reg to set as input*/
				case DIO_u8PORTD:CLR_BIT(DDRD,Copy_u8Pin);break; 		/*CLEARING the bit corresponding to the pin in DDRD reg to set as input*/
				default: Local_u8ErrorState=NOK; break;					/*ERROR state */
			}
		}
		/*check the Direction of pin if output*/
		else if(DIO_u8OUTPUT==Copy_u8Direction){
			/*check on the port name to select which port*/
			switch (Copy_u8PORT){
				case DIO_u8PORTA:SET_BIT(DDRA,Copy_u8Pin);break; 		/*SETTING the bit corresponding to the pin in DDRA reg to set as output*/
				case DIO_u8PORTB:SET_BIT(DDRB,Copy_u8Pin);break; 		/*SETTING the bit corresponding to the pin in DDRB reg to set as output*/
				case DIO_u8PORTC:SET_BIT(DDRC,Copy_u8Pin);break; 		/*SETTING the bit corresponding to the pin in DDRC reg to set as output*/
				case DIO_u8PORTD:SET_BIT(DDRD,Copy_u8Pin);break; 		/*SETTING the bit corresponding to the pin in DDRD reg to set as output*/
				default: Local_u8ErrorState=NOK; break;         		/*ERROR state */
			}
		}
		else{
			Local_u8ErrorState=NOK;										/*ERROR state */
		}
	}
	else{
		Local_u8ErrorState= NOK;										/*ERROR state */
	}

 return Local_u8ErrorState;												/*Returning ERROR state after the end of the function*/
}
/******************************************************************************************************************************************************************************************************************/

/*********************************************************************************************************/
/*-> NAME: 		@ u8 DIO_u8SetPinValue(u8 Copy_u8PORT,u8 Copy_u8Pin,u8 Copy_u8Value);	  		         */
/*-> breif:		@ this function is used to set the Value of a certin PIN from a certin   	      	     */
/*				  PORT whether to be High/LOW after it`s directio is set					 			 */
/*				  The functio returns u8 var Holding the error state of the function call OK/NOK		 */
/*-> Prameters: @ u8 Copy_u8PORT  -> the name of the required Port	         (DIO_u8PORTA:DIO_u8PORTD)	 */
/*				@ u8 Copy_u8Pin	  -> The number of the selected pin to be set (DIO_u8PIN0:DIO_u8PIN7) 	 */
/*				@ u8 Copy_u8Value -> the SELECTED value for the Pin 	     (DIO_u8LOW/DIO_u8HIGH) 	 */
/*********************************************************************************************************/
u8 DIO_u8SetPinValue(u8 Copy_u8PORT,u8 Copy_u8Pin,u8 Copy_u8Value){
	u8 Local_u8ErrorState=  OK;											/*local var to read the error state*/
	
	if(8>Copy_u8Pin){  													/*check for the in range pin number if correct */
		/*check the Direction of pin if low*/
		if(DIO_u8LOW==Copy_u8Value){
			/*check on the port name to select which port*/
			switch (Copy_u8PORT){
				case DIO_u8PORTA:CLR_BIT(PORTA,Copy_u8Pin);break;		/*CLEARING the bit corresponding to the pin in PORTA reg to set as low*/			
				case DIO_u8PORTB:CLR_BIT(PORTB,Copy_u8Pin);break;		/*CLEARING the bit corresponding to the pin in PORTB reg to set as low*/	
				case DIO_u8PORTC:CLR_BIT(PORTC,Copy_u8Pin);break;		/*CLEARING the bit corresponding to the pin in PORTC reg to set as low*/	
				case DIO_u8PORTD:CLR_BIT(PORTD,Copy_u8Pin);break;		/*CLEARING the bit corresponding to the pin in PORTD reg to set as low*/	
				default: Local_u8ErrorState=NOK; break;			        /*ERROR state */
			}			                                                
		}			                        		
		else if(DIO_u8HIGH==Copy_u8Value){								/*check the Direction of pin if high*/		                    
			/*check on the port name to select which port*/
			switch (Copy_u8PORT){			                            
				case DIO_u8PORTA:SET_BIT(PORTA,Copy_u8Pin);break;		/*SETTING the bit corresponding to the pin in PORTA reg to set as high*/	
				case DIO_u8PORTB:SET_BIT(PORTB,Copy_u8Pin);break;		/*SETTING the bit corresponding to the pin in PORTB reg to set as high*/	
				case DIO_u8PORTC:SET_BIT(PORTC,Copy_u8Pin);break;		/*SETTING the bit corresponding to the pin in PORTC reg to set as high*/	
				case DIO_u8PORTD:SET_BIT(PORTD,Copy_u8Pin);break;		/*SETTING the bit corresponding to the pin in PORTD reg to set as high*/	
				default: Local_u8ErrorState=NOK; break;			        /*ERROR state */
			}			                                                
		}			                                                    
		else{			                                                
			Local_u8ErrorState=NOK;			                            /*ERROR state */
		}			                                                    
	}			                                                        
	else{			                                                    
		Local_u8ErrorState=NOK;			                                /*ERROR state */
	}			                                                        
			                                                            
 return Local_u8ErrorState;			                                    /*Returning ERROR state after the end of the function*/
}
/******************************************************************************************************************************************************************************************************************/

/*********************************************************************************************************/
/*-> NAME: 		@ u8 DIO_u8GetPinValue(u8 Copy_u8PORT,u8 Copy_u8Pin,u8* Copy_pu8Value);	  		         */
/*-> breif:		@ this function is used to Get the Value of a certin PIN from a certin   	      	     */
/*				  PORT whether to be High/LOW after it`s directio is set					 			 */
/*				  The functio returns u8 var Holding the error state of the function call OK/NOK		 */
/*-> Prameters: @ u8 Copy_u8PORT  -> the name of the required Port	         (DIO_u8PORTA:DIO_u8PORTD)	 */
/*				@ u8 Copy_u8Pin	  -> The number of the selected pin to be set (DIO_u8PIN0:DIO_u8PIN7) 	 */
/*				@ u8 Copy_pu8Value -> Pointer to recive the value for the Pin (DIO_u8LOW/DIO_u8HIGH) 	 */
/*********************************************************************************************************/
u8 DIO_u8GetPinValue(u8 Copy_u8PORT,u8 Copy_u8Pin,u8* Copy_pu8Value){
	u8 Local_u8ErrorState = OK;															/*local var to read the error state*/
	if(8>Copy_u8Pin){																	/**/
		if(Copy_pu8Value != NULL){														/*check for null pointer*/
				/*check on the port name to select which port*/			
				switch (Copy_u8PORT){
					case DIO_u8PORTA: *Copy_pu8Value=GET_BIT(PINA,Copy_u8Pin);break;	/*Getting the value of the nit corresponding to the pin from PINA register*/
					case DIO_u8PORTB: *Copy_pu8Value=GET_BIT(PINB,Copy_u8Pin);break;	/*Getting the value of the nit corresponding to the pin from PINB register*/
					case DIO_u8PORTC: *Copy_pu8Value=GET_BIT(PINC,Copy_u8Pin);break;	/*Getting the value of the nit corresponding to the pin from PINC register*/
					case DIO_u8PORTD: *Copy_pu8Value=GET_BIT(PIND,Copy_u8Pin);break;	/*Getting the value of the nit corresponding to the pin from PIND register*/
					default			: Local_u8ErrorState = NOK; break;					 /*ERROR state */
				}
			}
		else{
			Local_u8ErrorState = NOK;													 /*ERROR state */
		}
	}
	else{
		Local_u8ErrorState = NOK;														 /*ERROR state */
	}
		return Local_u8ErrorState;														 /*Returning ERROR state after the end of the function*/
}
/******************************************************************************************************************************************************************************************************************/

/*********************************************************************************************************/
/*-> NAME: 		@ u8 DIO_u8SetPortDirection(u8 Copy_u8PORT,u8 Copy_u8Direction);	         			 */
/*-> breif:		@ this function is used to set the direction of an entire PORT 		(INPUT/OUTPUT)       */
/*				  The functio returns u8 var Holding the error state of the function call (OK/NOK)		 */
/*-> Prameters: @ u8 Copy_u8PORT -> the name of the required Port	         (DIO_u8PORTA:DIO_u8PORTD)	 */
/*				@ u8 Copy_u8Direction -> the Direction of the PORT	   (DIO_u8ALL_INPUT/DIO_u8ALL_OUTPUT)*/
/*********************************************************************************************************/
u8 DIO_u8SetPortDirection(u8 Copy_u8PORT,u8 Copy_u8Direction){
	u8 Local_u8ErrorState=OK;	/*local var to read the error state*/
	/*check on the port name to select which port*/
	switch (Copy_u8PORT){
			case DIO_u8PORTA:DDRA=Copy_u8Direction;break;				/*setting the direction of PORTA in DDRA  register*/
			case DIO_u8PORTB:DDRB=Copy_u8Direction;break;               /*setting the direction of PORTB in DDRB register*/
			case DIO_u8PORTC:DDRC=Copy_u8Direction;break;               /*setting the direction of PORTC in DDRC  register*/
			case DIO_u8PORTD:DDRD=Copy_u8Direction;break;               /*setting the direction of PORTD in DDRD  register*/
			default: Local_u8ErrorState=NOK; break;						/*ERROR state */
		}
return Local_u8ErrorState;												/*Returning ERROR state after the end of the function*/
}
/******************************************************************************************************************************************************************************************************************/

/*********************************************************************************************************/
/*-> NAME: 		@ u8 DIO_u8SetPortValue(u8 Copy_u8PORT,u8 Copy_u8Value);				  		         */
/*-> breif:		@ this function is used to set the Value of an entire PORT whether to be High/LOW 		 */
/*				  The functio returns u8 var Holding the error state of the function call OK/NOK		 */
/*-> Prameters: @ u8 Copy_u8PORT  -> the name of the required Port	         (DIO_u8PORTA:DIO_u8PORTD)	 */
/*				@ u8 Copy_u8Value -> the SELECTED value for the Pin 	     (DIO_u8ALLLOW/DIO_u8ALLHIGH)*/
/*********************************************************************************************************/
u8 DIO_u8SetPortValue(u8 Copy_u8PORT,u8 Copy_u8Value){
	u8 Local_u8ErrorState=OK;											/*local var to read the error state*/
	/*check on the port name to select which port*/
	switch (Copy_u8PORT){                                               
				case DIO_u8PORTA:PORTA=Copy_u8Value;break;              /*setting the value of PORTA in PORTA  register*/
				case DIO_u8PORTB:PORTB=Copy_u8Value;break;              /*setting the value of PORTB in PORTB register*/
				case DIO_u8PORTC:PORTC=Copy_u8Value;break;              /*setting the value of PORTC in PORTC  register*/
				case DIO_u8PORTD:PORTD=Copy_u8Value;break;              /*setting the value of PORTD in PORTD  register*/
				default: Local_u8ErrorState=NOK; break;                 /*ERROR state */
}                                                                       
	return Local_u8ErrorState;                                          /*Returning ERROR state after the end of the function*/
}
/******************************************************************************************************************************************************************************************************************/

/*********************************************************************************************************/
/*-> NAME: 		@ u8 DIO_u8GetPortValue(u8 Copy_u8PORT,u8* Copy_pu8Value);			 	  		         */
/*-> breif:		@ this function is used to Get the Value of PORT whether to be High/LOW 				 */
/*				  The functio returns u8 var Holding the error state of the function call OK/NOK		 */
/*-> Prameters: @ u8 Copy_u8PORT  -> the name of the required Port	         (DIO_u8PORTA:DIO_u8PORTD)	 */
/*				@ u8 Copy_pu8Value -> Pointer to recive the value of the PORT (DIO_u8LOW/DIO_u8HIGH) 	 */
/*********************************************************************************************************/
u8 DIO_u8GetPortValue(u8 Copy_u8PORT,u8* Copy_pu8Value){
	u8 Local_u8ErrorState=OK;									/*local var to read the error state*/
	if(Copy_pu8Value != NULL){									/*check for null pointer*/
		/*check on the port name to select which port*/
		switch (Copy_u8PORT){
			case DIO_u8PORTA: *Copy_pu8Value=PINA;break;
			case DIO_u8PORTB: *Copy_pu8Value=PINB;break;
			case DIO_u8PORTC: *Copy_pu8Value=PINC;break;
			case DIO_u8PORTD: *Copy_pu8Value=PIND;break;
			default: Local_u8ErrorState=NOK; break;				/*ERROR state */
			}
	}
	else{
			Local_u8ErrorState = NOK;							/*ERROR state */
		}
		return Local_u8ErrorState;								/*Returning ERROR state after the end of the function*/
}
/******************************************************************************************************************************************************************************************************************/
/******************************************************************************************************************************************************************************************************************/
/******************************************************************************************************************************************************************************************************************/

