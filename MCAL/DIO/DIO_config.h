/***************************************************************************/
/************* AUTHOR: @ Muhammed Sherif Attia *****************************/
/************* FILE  : @ DIO_config.h          *****************************/
/************* breif : @ The config.h file for 		    ********************/
/*************           the Digital i/o prephilral of atmega32 ************/
/************* DATE  : @ 31/12/2023 ****************************************/
/***************************************************************************/

#ifndef DIO_CONFIG_H_
#define DIO_CONFIG_H_
/********************************************************/
/* set THE DIRECTION OF THE PINS FOR EACH PORT
 * OPTIONS:-
 * 			1-	DIO_u8INPUT
 * 			2-  DIO_u8OUTPUT
 */
/*******************************************************/
#define     PORTA_PIN0_DIRECTION            DIO_u8OUTPUT
#define     PORTA_PIN1_DIRECTION            DIO_u8INPUT
#define     PORTA_PIN2_DIRECTION            DIO_u8INPUT
#define     PORTA_PIN3_DIRECTION            DIO_u8INPUT
#define     PORTA_PIN4_DIRECTION            DIO_u8INPUT
#define     PORTA_PIN5_DIRECTION            DIO_u8INPUT
#define     PORTA_PIN6_DIRECTION            DIO_u8INPUT
#define     PORTA_PIN7_DIRECTION            DIO_u8INPUT



#define     PORTB_PIN0_DIRECTION            DIO_u8INPUT
#define     PORTB_PIN1_DIRECTION            DIO_u8INPUT
#define     PORTB_PIN2_DIRECTION            DIO_u8INPUT
#define     PORTB_PIN3_DIRECTION            DIO_u8INPUT
#define     PORTB_PIN4_DIRECTION            DIO_u8INPUT
#define     PORTB_PIN5_DIRECTION            DIO_u8INPUT
#define     PORTB_PIN6_DIRECTION            DIO_u8INPUT
#define     PORTB_PIN7_DIRECTION            DIO_u8INPUT

#define     PORTC_PIN0_DIRECTION            DIO_u8INPUT
#define     PORTC_PIN1_DIRECTION            DIO_u8INPUT
#define     PORTC_PIN2_DIRECTION            DIO_u8INPUT
#define     PORTC_PIN3_DIRECTION            DIO_u8INPUT
#define     PORTC_PIN4_DIRECTION            DIO_u8INPUT
#define     PORTC_PIN5_DIRECTION            DIO_u8INPUT
#define     PORTC_PIN6_DIRECTION            DIO_u8INPUT
#define     PORTC_PIN7_DIRECTION            DIO_u8INPUT

#define     PORTD_PIN0_DIRECTION            DIO_u8INPUT
#define     PORTD_PIN1_DIRECTION            DIO_u8INPUT
#define     PORTD_PIN2_DIRECTION            DIO_u8INPUT
#define     PORTD_PIN3_DIRECTION            DIO_u8INPUT
#define     PORTD_PIN4_DIRECTION            DIO_u8INPUT
#define     PORTD_PIN5_DIRECTION            DIO_u8INPUT
#define     PORTD_PIN6_DIRECTION            DIO_u8INPUT
#define     PORTD_PIN7_DIRECTION            DIO_u8INPUT
/********************************************************/
/* set THE INITIAL VALUE OF THE PINS FOR EACH PORT
 * OPTIONS:-
 * 			1-	DIO_u8LOW
 * 			2-  DIO_u8HIGH
 */
/*******************************************************/
#define     PORTA_PIN0_INITIAL_VALUE            DIO_u8LOW
#define     PORTA_PIN1_INITIAL_VALUE            DIO_u8LOW
#define     PORTA_PIN2_INITIAL_VALUE            DIO_u8LOW
#define     PORTA_PIN3_INITIAL_VALUE            DIO_u8LOW
#define     PORTA_PIN4_INITIAL_VALUE            DIO_u8LOW
#define     PORTA_PIN5_INITIAL_VALUE            DIO_u8LOW
#define     PORTA_PIN6_INITIAL_VALUE            DIO_u8LOW
#define     PORTA_PIN7_INITIAL_VALUE            DIO_u8LOW



#define     PORTB_PIN0_INITIAL_VALUE            DIO_u8LOW
#define     PORTB_PIN1_INITIAL_VALUE            DIO_u8LOW
#define     PORTB_PIN2_INITIAL_VALUE            DIO_u8LOW
#define     PORTB_PIN3_INITIAL_VALUE            DIO_u8LOW
#define     PORTB_PIN4_INITIAL_VALUE            DIO_u8LOW
#define     PORTB_PIN5_INITIAL_VALUE            DIO_u8LOW
#define     PORTB_PIN6_INITIAL_VALUE            DIO_u8LOW
#define     PORTB_PIN7_INITIAL_VALUE            DIO_u8LOW

#define     PORTC_PIN0_INITIAL_VALUE            DIO_u8LOW
#define     PORTC_PIN1_INITIAL_VALUE            DIO_u8LOW
#define     PORTC_PIN2_INITIAL_VALUE            DIO_u8LOW
#define     PORTC_PIN3_INITIAL_VALUE            DIO_u8LOW
#define     PORTC_PIN4_INITIAL_VALUE            DIO_u8LOW
#define     PORTC_PIN5_INITIAL_VALUE            DIO_u8LOW
#define     PORTC_PIN6_INITIAL_VALUE            DIO_u8LOW
#define     PORTC_PIN7_INITIAL_VALUE            DIO_u8LOW

#define     PORTD_PIN0_INITIAL_VALUE            DIO_u8LOW
#define     PORTD_PIN1_INITIAL_VALUE            DIO_u8LOW
#define     PORTD_PIN2_INITIAL_VALUE            DIO_u8LOW
#define     PORTD_PIN3_INITIAL_VALUE            DIO_u8LOW
#define     PORTD_PIN4_INITIAL_VALUE            DIO_u8LOW
#define     PORTD_PIN5_INITIAL_VALUE            DIO_u8LOW
#define     PORTD_PIN6_INITIAL_VALUE            DIO_u8LOW
#define     PORTD_PIN7_INITIAL_VALUE            DIO_u8LOW
#endif /* DIO_CONFIG_H_ */
