/***************************************************************************/
/************* AUTHOR: @ Muhammed Sherif Attia *****************************/
/************* FILE  : @ TIMER1_config.h      *****************************/
/************* breif : @ The TIMER1_config.h file for 	********************/
/*************           Timer 1 prepheral of atmega32 *********************/
/************* DATE  : @ 31/12/2023 ****************************************/
/***************************************************************************/
#ifndef TIMER1_CONFIG_H_
#define TIMER1_CONFIG_H_


/*set SYSTEM VARIABLES FOR TIMER/Counter 1 */
/*SET THE CLOCK FREQUANCY IN HZ */
/*SELECT a preScaler FROM {0,8,16,64,256,1024}*/
/*THE SIZE OF THE TIMER REGISTER {256,65536}*/
#define CLOCK_FREQUANCY		8000000
#define PRESCALER_VALUE_T1		8
#define OVF_COUNTS_T1			256
/*set timer mode Counter / time
 * Options:
 * 			1- TIMER
 * 			2- COUNTER
 *
 * */
#define  TIMER_COUNTER1_MODE       TIMER

/*SET TIMER 1 CTC/NORMAL/PWM
 * Options:
 * 			1-  TIMER1_NORMAL		
 * 			2-  TIMER1_PWM_PC8BIT	
 * 			3-  TIMER1_PWM_PC9BIT	
 * 			4-  TIMER1_PWM_PC10BIT	
 * 			5-  TIMER1_CTC_OCR1A	
 * 			6-  TIMER1_FASTPWM_8BIT	
 * 			7-  TIMER1_FASTPWM_9BIT	
 * 			8-  TIMER1_FASTPWM_10BIT
 * 			9-  TIMER1_PWM_PFC_ICR1	
 * 			10- TIMER1_PWM_PFC_OCR1A
 * 			11- TIMER1_PWM_PC_ICR1	
 * 			12- TIMER1_PWM_PC_OCR1A	
 * 			13- TIMER1_CTC_ICR1		
 * 			14- TIMER1_FPWM_ICR1	
 * 			15- TIMER1_FPWM_OCR1A	
 * */
#define TIMER1_MODE                TIMER1_NORMAL

/*Set PreScaler for Timer 1 8BIT
 * options:
 * 			1-  NO_PRESCALER
 * 			2-	PRESCALER_1
 * 			3-  PRESCALER_8
 * 			4-  PRESCALER_64
 * 			5-  PRESCALER_256
 * 			6- PRESCALER_1024
 * */
#define TIMER1_PRESCALER			 PRESCALER_8


/*COUNTER mode rising Edge/falling edge
 * options:
 * 			1-  RISING_EDGE
 * 			2-  FALLING_EDGE
 * 			3-	DISABLE
 * */
#define  COUNTER1_SENSE 			 DISABLE




















#endif /* TIMER_CONFIG_H_ */
