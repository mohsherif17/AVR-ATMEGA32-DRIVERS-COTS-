/***************************************************************************/
/************* AUTHOR: @ Muhammed Sherif Attia *****************************/
/************* FILE  : @ ADC_program.c         *****************************/
/************* breif : @ The program.c file for 		********************/
/*************           the Analog to digital of atmega32 *****************/
/************* DATE  : @ 31/12/2023 ****************************************/
/***************************************************************************/

/***********************************includes*****************************************/
/***** standard libs *****/
#include"STD_TYPES.h"
#include"BIT_MATH.h"
/***** ADC files *****/
#include"ADC_confige.h"
#include"ADC_interface.h"
#include"ADC_private.h"
#include"ADC_register.h"


/***********************************************************************************/
/***************************Functions implementation********************************/

/**********************************************************/
/*-> NAME: 		@ void ADC_voidINIT(void);			      */
/*-> breif:		@ this function is used to intialize  	  */
/*				  the ADC Prepheral and set its PreScaler,*/
/*				  select adjustment and vref   		   	  */
/*-> Prameters: @ void							       	  */
/*													   	  */
/**********************************************************/
void ADC_voidINIT(void){
	/*select referance voltage*/
#if(VREF == AREF)
	{
		CLR_BIT(ADMUX,ADC_REFS1);
		CLR_BIT(ADMUX,ADC_REFS0)
	}
#elif(VREF == AVCC)
	{
		CLR_BIT(ADMUX,ADC_REFS1);
		SET_BIT(ADMUX,ADC_REFS0);
	}
#elif(VREF == VInternal)
	{
		SET_BIT(ADMUX,ADC_REFS1);
		SET_BIT(ADMUX,ADC_REFS0);
	}
#endif

/* select adjustment */

#if(SELECT_ADJUSTMENT == NORMAL_ADJUSTMENT)
	{
	CLR_BIT(ADMUX,ADC_ADLAR);
	}
#elif(SELECT_ADJUSTMENT == LEFT_ADJUSTMENT)
	{
		SET_BIT(ADMUX,ADC_ADLAR);
	}
#endif

	/*select Prescaler*/
ADCSRA &=0b11111000;
ADCSRA |=PRESCALER;


	/* ADC ENABLE */
	SET_BIT(ADCSRA,ADC_ADEN);

}
/******************************************************************************************************************************************************************************************************************/

/****************************************************************/
/*-> NAME: 		@ u16 ADC_u16ReadChannel(u8 Copy_u8Channel);    */
/*-> breif:		@ this function is used to Read the value  	    */
/*				  From a pin in the ADC Prepheral 			    */
/*				@ this function return a u16 value represents   */
/*				   the ADC pin Value					        */
/*-> Prameters: @ u8 Copy_u8Channel	-> the number of the ADC PIN*/
/****************************************************************/
u16 ADC_u16ReadChannel(u8 Copy_u8Channel){
/* SELECT CHANNEL*/
ADMUX &=0b11100000;
ADMUX |=Copy_u8Channel;

/*start conversion*/
SET_BIT(ADCSRA,ADC_ADSC);

/*polling*/
while((GET_BIT(ADCSRA,ADC_ADIF)) !=1)
{
	asm("NOP");
}

/*Clear Flag*/
SET_BIT(ADCSRA,ADC_ADIF);

/*READ VALUE*/
return ADC;
}

/******************************************************************************************************************************************************************************************************************/
/******************************************************************************************************************************************************************************************************************/
/******************************************************************************************************************************************************************************************************************/
