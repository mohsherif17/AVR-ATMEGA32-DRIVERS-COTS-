/***************************************************************************/
/************* AUTHOR: @ Muhammed Sherif Attia *****************************/
/************* FILE  : @ TIMER1_register.h      *****************************/
/************* breif : @ The TIMER1_register.h file for ********************/
/*************           Timer 1 prepheral of atmega32 *********************/
/************* DATE  : @ 31/12/2023 ****************************************/
/***************************************************************************/

#ifndef TIMER1_REGISTER_H_
#define TIMER1_REGISTER_H_

/***********************************************/
#define 		TMISK		  *((volatile u8*)(0x59))

/**TIMER/COUNTER 1 TMISK REGISTER BITS**/
#define 		TMISK_TICE1					5
#define 		TMISK_OCIE1A 				4
#define 		TMISK_OCIE1B				3
#define 		TMISK_TOIE1					2

/***********************************************/
/***********************************************/
#define 		TIFR		  *((volatile u8*)(0x58))

/**TIMER/COUNTER 1 TIFR REGISTER BITS**/
#define 		TIFR_ICF1			5
#define 		TIFR_OCF1A			4
#define 		TIFR_OCF1B			3
#define 		TIFR_TOV1			2

/*********************************************************************************/
/*********************************************************************************/
/********************************** TIMER/COUNTER 1 ******************************/
#define  		TCCR1A		  		*((volatile u8*)(0x4F))
#define  		TCCR1B		  		*((volatile u8*)(0x4E))

#define 		TCCR1A_WGM10			0
#define 		TCCR1A_WGM11			1
#define 		TCCR1A_FOC1B			2
#define 		TCCR1A_FOC1A			3
#define 		TCCR1A_COM1B0			4
#define 		TCCR1A_COM1B1			5
#define 		TCCR1A_COM1A0			6
#define 		TCCR1A_COM1A1			7

#define 		TCCR1B_CS10				0
#define 		TCCR1B_CS11				1
#define 		TCCR1B_CS12				2
#define 		TCCR1B_WGM12			3
#define 		TCCR1B_WGM13			4

#define 		TCCR1B_ICES1			6
#define 		TCCR1B_ICNC1			7
/******************************************/
#define  		TCNT1		  *((volatile u16*)(0x4C))
#d
/******************************************/
#d
#define  		OCR1A		  *((volatile u16*)(0x4A))


#define  		OCR1B		  *((volatile u16*)(0x48))
/******************************************/

#define  		ICR1		  *((volatile u16*)(0x46))

/*********************************************************************************/
/*********************************************************************************/

#endif /* TIMER_REGISTER_H_ */
