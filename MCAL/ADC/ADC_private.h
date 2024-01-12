/***************************************************************************/
/************* AUTHOR: @ Muhammed Sherif Attia *****************************/
/************* FILE  : @ ADC_private.h         *****************************/
/************* breif : @ The private.h file for 		********************/
/*************           the Analog to digital of atmega32 *****************/
/************* DATE  : @ 31/12/2023 ****************************************/
/***************************************************************************/

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

/**** options for refrance voltage ****/
#define		 AREF                1
#define		 AVCC	   		 	 2
#define		 VInternal           3

/**** options for Select Adjustment ****/
#define      NORMAL_ADJUSTMENT   1
#define      LEFT_ADJUSTMENT     2

/**** options for PreScaler ****/
#define		 DIVIDE_BY_2 		 0
#define		 DIVIDE_BY2 		 1
#define		 DIVIDE_BY_4 		 2
#define		 DIVIDE_BY_8 		 3
#define		 DIVIDE_BY_16 		 4
#define		 DIVIDE_BY_32 		 5
#define		 DIVIDE_BY_64 		 6
#define		 DIVIDE_BY_128 		 7
#endif /* ADC_PRIVATE_H_ */
