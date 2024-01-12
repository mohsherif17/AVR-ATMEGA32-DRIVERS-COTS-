/***************************************************************************/
/************* AUTHOR: @ Muhammed Sherif Attia *****************************/
/************* FILE  : @ ADC_confige.h         *****************************/
/************* breif : @ The confige.h file for 		********************/
/*************           the Analog to digital of atmega32 *****************/
/************* DATE  : @ 31/12/2023 ****************************************/
/***************************************************************************/
#ifndef ADC_CONFIGE_H_
#define ADC_CONFIGE_H_


/*SET referance voltage for ADC
 *options : 1-AREF
 * 			2-AVCC
 * 			3-VInternal
 * 				 			*/
#define			 VREF		 				 AVCC

/* SET Select Adjustment for ADC
 * options : 	1-NORMAL_ADJUSTMENT
 * 	         	2-LEFT_ADJUSTMENT	*/
#define 		SELECT_ADJUSTMENT  			NORMAL_ADJUSTMENT

/*set prescaler for ADC
 * options   1-  DIVIDE_BY_2 
			 2-  DIVIDE_BY2 	
			 3-  DIVIDE_BY_4 
			 4-  DIVIDE_BY_8 
			 5-  DIVIDE_BY_16 
			 6-  DIVIDE_BY_32 
			 7-  DIVIDE_BY_64 
			 8-  DIVIDE_BY_128
 */

#define 		PRESCALER                   DIVIDE_BY_8
#endif /* ADC_CONFIGE_H_ */
