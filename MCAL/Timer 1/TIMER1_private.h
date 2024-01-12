/***************************************************************************/
/************* AUTHOR: @ Muhammed Sherif Attia *****************************/
/************* FILE  : @ TIMER1_private.h      *****************************/
/************* breif : @ The TIMER1_private.h file for 	********************/
/*************           Timer 1 prepheral of atmega32 *********************/
/************* DATE  : @ 31/12/2023 ****************************************/
/***************************************************************************/
#ifndef TIMER1_PRIVATE_H_
#define TIMER1_PRIVATE_H_
/*Timer/COUNTER  PREPHERAL CONFIG*/
#define TIMER  			1
#define COUNTER 		2


/*MODES of THE COUNTER*/
#define RISING_EDGE			1
#define FALLING_EDGE		2


/*MODES of THE PRESCALER*/
#define NO_PRESCALER        0b0000000
#define PRESCALER_1         0b0000001
#define PRESCALER_8         0b0000010
#define PRESCALER_64        0b0000011
#define PRESCALER_256  	    0b0000100
#define PRESCALER_1024	    0b0000101

/*Modes of the CTC OC1A Counter*/
#define 		CTC_OC1A_Disable			0b00000000
#define 		CTC_OC1A_TOGGLE				0b01000000
#define 		CTC_OC1A_CLEAR				0b10000000
#define 		CTC_OC1A_SET 				0b11000000
/*Modes of the CTC OC1B Counter*/
#define 		CTC_OC1B_Disable			0b00000000
#define 		CTC_OC1B_TOGGLE				0b00010000
#define 		CTC_OC1B_CLEAR				0b00100000
#define 		CTC_OC1B_SET 				0b00110000

/* OC1A pin options in PWM mode */
#define  PWM_OC1A_DISABLE						0b00000000
#define  PWM_OC1A_TOOGLE						0b01000000
#define  PWM_OC1A_NON_INVERTED					0b10000000
#define  PWM_OC1A_INVERTED						0b11000000

/* OC1B pin options in PWM mode */
#define  PWM_OC1B_DISABLE						0b00000000
#define  PWM_OC1B_TOOGLE						0b00010000
#define  PWM_OC1B_NON_INVERTED					0b00100000
#define  PWM_OC1B_INVERTED						0b00110000

/*TIMER 1 MODES*/
#define			TIMER1_NORMAL			1
#define			TIMER1_PWM_PC8BIT		2
#define			TIMER1_PWM_PC9BIT		3
#define			TIMER1_PWM_PC10BIT		4
#define			TIMER1_CTC_OCR1A		5
#define			TIMER1_FASTPWM_8BIT		6
#define			TIMER1_FASTPWM_9BIT		7
#define			TIMER1_FASTPWM_10BIT	8
#define			TIMER1_PWM_PFC_ICR1		9
#define			TIMER1_PWM_PFC_OCR1A	10
#define			TIMER1_PWM_PC_ICR1		11
#define			TIMER1_PWM_PC_OCR1A		12
#define			TIMER1_CTC_ICR1			13
#define			TIMER1_FPWM_ICR1		14
#define			TIMER1_FPWM_OCR1A		15


#define 	TICK_TIME_T1_ms			CLOCK_FREQUANCY/(PRESCALER_VALUE_T1*1000)

#endif /* TIMER_PRIVATE_H_ */
