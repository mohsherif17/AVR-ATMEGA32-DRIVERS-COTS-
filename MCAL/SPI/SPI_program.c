/***************************************************************************/
/************* AUTHOR: @ Muhammed Sherif Attia *****************************/
/************* FILE  : @ SPI_program.c         *****************************/
/************* breif : @ The program.c file for 		********************/
/*************           the SPI Communication protocol in atmega32   ******/
/************* DATE  : @ 31/12/2023 ****************************************/
/***************************************************************************/


/*********************************** includes *****************************************/
/***** standard libs *****/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/***** SPI files *****/
#include "SPI_config.h"
#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_register.h"

/*********************************** GLOBAL VARIABLES *****************************************/

static void (*SPI_CallBack)(void) = NULL;

/***********************************************************************************/
/***************************Functions implementation********************************/

/************************************************************************************************************/
/* -> NAME:           @ void SPI_voidINITIALIZE(void)														*/
/* -> DESCRIBTION:    @ this function is used to initialize the SPI COUMMUNICATION PROTOCOL				    */
/* -> Parameters: 	   @ void																				*/
/************************************************************************************************************/
void SPI_voidINITIALIZE(void){
/*SET the data transmition order*/
#if DATA_ORDER==SPI_LSB
	SET_BIT(SPCR,SPI_DORD);
#elif DATA_ORDER==SPI_MSB
	CLR_BIT(SPCR,SPI_DORD);
#endif
/*SEt the master/slave MCU mode*/
#if	SPI_MASTER_MODE==SPI_MASTER
	SET_BIT(SPCR,SPI_MSTR);
#elif SPI_MASTER_MODE==SPI_SLAVE
	CLR_BIT(SPCR,SPI_MSTR);
#endif
/*SET CLOCK POLARITY*/
#if SPI_CLOCK_POLARITY == SPI_ClockPolarity_LEADING_EDGE_RISING
	CLR_BIT(SPCR,SPI_CPOL);
#elif SPI_CLOCK_POLARITY == SPI_ClockPolarity_LEADING_EDGE_FALLING
	SET_BIT(SPCR,SPI_CPOL);
#endif
/*select SPI clock rate*/
#if SPI_CLOCK_RATE==SPI_FOSC_4
	CLR_BIT(SPCR,SPI_SPR0);
	CLR_BIT(SPCR,SPI_SPR1);
	CLR_BIT(SPSR,SPI_SPI2X);
#elif SPI_CLOCK_RATE==SPI_FOSC_16
	SET_BIT(SPCR,SPI_SPR0);
	CLR_BIT(SPCR,SPI_SPR1);
	CLR_BIT(SPSR,SPI_SPI2X);
#elif SPI_CLOCK_RATE==	SPI_FOSC_64
	CLR_BIT(SPCR,SPI_SPR0);
	SET_BIT(SPCR,SPI_SPR1);
	CLR_BIT(SPSR,SPI_SPI2X);
#elif SPI_CLOCK_RATE==	SPI_FOSC_128
	SET_BIT(SPCR,SPI_SPR0);
	SET_BIT(SPCR,SPI_SPR1);
	CLR_BIT(SPSR,SPI_SPI2X);
#elif SPI_CLOCK_RATE==	SPI_FOSC_2
	CLR_BIT(SPCR,SPI_SPR0);
	CLR_BIT(SPCR,SPI_SPR1);
	SET_BIT(SPSR,SPI_SPI2X);
#elif SPI_CLOCK_RATE==	SPI_FOSC_8
	SET_BIT(SPCR,SPI_SPR0);
	CLR_BIT(SPCR,SPI_SPR1);
	SET_BIT(SPSR,SPI_SPI2X);
#elif SPI_CLOCK_RATE==	SPI_FOSC_32
	CLR_BIT(SPCR,SPI_SPR0);
	SET_BIT(SPCR,SPI_SPR1);
	SET_BIT(SPSR,SPI_SPI2X);
#endif
/*ENABLE SPI*/
SET_BIT(SPCR,SPI_SPE);
}
/******************************************************************************************************************************************************************************************************************/

/************************************************************************************************************/
/* -> NAME:           @ u8 SPI_u8SendRecive(u8 Copy_u8data)													*/
/* -> DESCRIBTION:    @ this function is used to send data from the Master of SPI connection			    */
/* -> Parameters: 	   @ u8 Copy_u8data: the data to be sent to the slave									*/
/************************************************************************************************************/

u8 SPI_u8SendRecive(u8 Copy_u8data){
	SPDR= Copy_u8data;
	while(GET_BIT(SPSR,SPI_SPIF)==0);
	return SPDR;
}
/******************************************************************************************************************************************************************************************************************/

/************************************************************************************************************/
/* -> NAME:           @ void SPI_voidEnableInterrupt(void);													*/
/* -> DESCRIBTION:    @ this function is used to Enable interrupt of SPI connection			    			*/
/* -> Parameters: 	   @ void 																				*/
/************************************************************************************************************/

void SPI_voidEnableInterrupt(void){

	SET_BIT(SPCR, SPI_SPIE);

}
/******************************************************************************************************************************************************************************************************************/

/************************************************************************************************************/
/* -> NAME:           @ void SPI_voidDisableInterrupt(void);												*/
/* -> DESCRIBTION:    @ this function is used to Disable interrupt of SPI connection		    			*/
/* -> Parameters: 	   @ void 																				*/
/************************************************************************************************************/
void SPI_voidDisableInterrupt(void){

	CLR_BIT(SPCR, SPI_SPIE);

}
/******************************************************************************************************************************************************************************************************************/

/************************************************************************************************************/
/* -> NAME:           @ void SPI_voidSetCallBack(void(*Copy_pvoidCallBack)(void));							*/
/* -> DESCRIBTION:    @ this function is used to set ISR function for the SPI interrupt		    			*/
/* -> Parameters: 	   @ void(*Copy_pvoidCallBack)(void) -> pointer to the call back function for the ISR	*/
/************************************************************************************************************/
void SPI_voidSetCallBack(void(*Copy_pvoidCallBack)(void)){

	SPI_CallBack = Copy_pvoidCallBack;

}

/******************************************************************************************************************************************************************************************************************/
/*********************************************
the vector function for SPI interrupt isr
*********************************************/
void __vector_12(void) __attribute__((signal));
void __vector_12(void){
	if(SPI_CallBack != NULL){
		SPI_CallBack();
	}
}

/******************************************************************************************************************************************************************************************************************/
/******************************************************************************************************************************************************************************************************************/
/******************************************************************************************************************************************************************************************************************/
