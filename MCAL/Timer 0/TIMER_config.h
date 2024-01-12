/****************************************************************************/
/*************           file   : TIMER_config.h                *************/
/*************           author : Muhammed Sherif               *************/
/*************           date   :  21/12/2023          		    *************/
/****************************************************************************/

#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_

/*set SYSTEM VARIABLES FOR TIMER/Counter 0 */
/*SET THE CLOCK FREQUANCY IN HZ */
/*SELECT a preScaler FROM {0,8,16,64,256,1024}*/
/*THE SIZE OF THE TIMER REGISTER {256,65536}*/
#define CLOCK_FREQUANCY		8000000
#define PRESCALER_VALUE_T0		8
#define OVF_COUNTS_T0			256

/*set timer mode Counter / time
 * Options:
 * 			1- TIMER
 * 			2- COUNTER
 *
 * */
#define  TIMER_COUNTER0_MODE       TIMER

/*SET TIMER CTC/NORMAL
 * Options:
 * 			1- NORMAL
 * 			2- CTC
 * 			3- FAST_PWM
 * 			4- PHASE_CORRECT
 * */
#define TIMER0_MODE                FAST_PWM

/*Set PreScaler for Timer 0 8BIT
 * options:
 * 			1-  NO_PRESCALER
 * 			2-	PRESCALER_1
 * 			3-  PRESCALER_8
 * 			4-  PRESCALER_64
 * 			5-  PRESCALER_256
 * 			6- PRESCALER_1024
 * */
#define TIMER0_PRESCALER			 PRESCALER_8

/*CTC PIN
 * options
 * 			1-  CTC_Disable
 * 			2-  CTC_TOGGLE
 * 			3-  CTC_CLEAR
 * 			4-  CTC_SET
 *
  */

#define CTC_PIN			  	 	 CTC_Disable

/*PWM mode
 * options:
 * 			1-  SET_COMPARE_CLR_TOP
 * 			2-  CLR_COMPARE_SET_TOP
 *          3-  	PWM_Disable
 * */

#define   PWM0_MODE				SET_COMPARE_CLR_TOP


/*COUNTER mode rising Edge/falling edge
 * options:
 * 			1-  RISING_EDGE
 * 			2-  FALLING_EDGE
 * */
#define  COUNTER0_SENSE 			 DISABLE


#endif /* TIMER_CONFIG_H_ */
