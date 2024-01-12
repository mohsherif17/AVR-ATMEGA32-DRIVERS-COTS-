/***************************************************************************/
/************* AUTHOR: @ Muhammed Sherif Attia *****************************/
/************* FILE  : @ ADC_register.h        *****************************/
/************* breif : @ The register.h file for 		********************/
/*************           the Analog to digital of atmega32 *****************/
/************* DATE  : @ 31/12/2023 ****************************************/
/***************************************************************************/
 

#ifndef ADC_REGISTER_H_
#define ADC_REGISTER_H_

#define      ADMUX 	 	 	 		*((volatile u8*)(0x27))

#define		ADC_REFS1								7
#define		ADC_REFS0								6
#define		ADC_ADLAR								5

#define      ADCSRA 	 	 	 	*((volatile u8*)(0x26))

#define		ADC_ADEN							7
#define		ADC_ADSC							6
#define		ADC_ADIF							4



#define      ADC	 	 	 	 	*((volatile u16*)(0x24))
#define      SFIOR 	 	 	 		*((volatile u8*)(0x50))


#endif /* ADC_REGISTER_H_ */
