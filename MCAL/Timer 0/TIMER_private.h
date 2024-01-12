/****************************************************************************/
/*************           file   : TIMER_private.h               *************/
/*************           author : Muhammed Sherif               *************/
/*************           date   :  21/12/2023          		    *************/
/****************************************************************************/
#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_
/*Timer/COUNTER  PREPHERAL CONFIG*/
#define TIMER  			1
#define COUNTER 		2

/*Timer mode PREPHERAL CONFIG { 1-over flow Timer mode
 * 								   2-CTC Timer mode
 * 								   3-FAST PWM Mode
 * 								   4-Phase Correct PWM Mode
 * 								  				}*/
#define NORMAL				1
#define CTC					2
#define FAST_PWM			3
#define PHASE_CORRECT		4

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


/*Modes of the CTC Counter*/
#define 		CTC_Disable			0b00000000
#define 		CTC_TOGGLE			0b00010000
#define 		CTC_CLEAR			0b00100000
#define 		CTC_SET 			0b00110000

/*Modes of the PWM*/
#define     SET_COMPARE_CLR_TOP     0b00110000
#define     CLR_COMPARE_SET_TOP     0b00100000
#define 		PWM_Disable			0b00000000



#define 	TICK_TIME_T0_ms			CLOCK_FREQUANCY/(PRESCALER_VALUE_T0*1000)


#endif /* TIMER_PRIVATE_H_ */
