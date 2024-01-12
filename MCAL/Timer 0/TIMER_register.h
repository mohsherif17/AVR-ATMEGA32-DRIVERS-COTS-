/****************************************************************************/
/*************           file   : TIMER_register.h              *************/
/*************           author : Muhammed Sherif               *************/
/*************           date   :  21/12/2023          		    *************/
/****************************************************************************/


#ifndef TIMER_REGISTER_H_
#define TIMER_REGISTER_H_

/********************************** TIMER/COUNTER 0 **********************************/
#define  		TCCR0		  		*((volatile u8*)(0x53))

#define 		TCCRO_FOC0			7
#define 		TCCRO_WGM00			6
#define 		TCCRO_COM01			5
#define 		TCCRO_COM00			4
#define 		TCCRO_WGM01			3
#define 		TCCRO_CS02			2
#define 		TCCRO_CS01			1
#define 		TCCRO_CS00			0
/************************************************/
/***********************************************/
#define  		TCNT0		  *((volatile u8*)(0x52))
/***********************************************/
/***********************************************/
#define 		OCR0			  *((volatile u8*)(0x5C))
/***********************************************/
/***********************************************/
#define 		TMISK		  *((volatile u8*)(0x59))
/**TIMER/COUNTER 0 TMISK REGISTER BITS**/
#define 		TMISK_OCIE0 				1
#define 		TMISK_TOIE0					0

/**TIMER/COUNTER 2 TMISK REGISTER BITS**/
#define 		TMISK_OCIE2 				7
#define 		TMISK_TOIE2					6
/***********************************************/
/***********************************************/
#define 		TIFR		  *((volatile u8*)(0x58))
/**TIMER/COUNTER 0 TIFR REGISTER BITS**/
#define 		TIFR_OCF2			1
#define 		TIFR_TOV2			0

/**TIMER/COUNTER 2 TIFR REGISTER BITS**/
#define 		TIFR_OCF0			7
#define 		TIFR_TOV0			6
/*********************************************************************************/
/*********************************************************************************/

/********************************** TIMER/COUNTER 2 ******************************/
#define  		TCCR2		  	*((volatile u8*)(0x45))

#define 		TCCRO_FOC2			7
#define 		TCCRO_WGM20			6
#define 		TCCRO_COM21			5
#define 		TCCRO_COM20			4
#define 		TCCRO_WGM21			3
#define 		TCCRO_CS22			2
#define 		TCCRO_CS21			1
#define 		TCCRO_CS20			0
/************************************************/
/***********************************************/
#define  		TCNT2		  *((volatile u8*)(0x44))
/***********************************************/
/***********************************************/
#define 		OCR2		  *((volatile u8*)(0x43))
/***********************************************/
/***********************************************/
#endif /* TIMER_REGISTER_H_ */
