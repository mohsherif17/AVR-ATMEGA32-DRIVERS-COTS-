/***************************************************************************/
/************* AUTHOR: @ Muhammed Sherif Attia *****************************/
/************* FILE  : @ DIO_register.h        *****************************/
/************* breif : @ The register.h file for	    ********************/
/*************           the Digital i/o prephilral of atmega32 ************/
/************* DATE  : @ 31/12/2023 ****************************************/
/***************************************************************************/

#ifndef DIO_REGISTER_H_
#define DIO_REGISTER_H_

/***********************************************/
/*->defination of the  MCU registers of port A */
/***********************************************/
#define PORTA       *((volatile u8*)(0x3B))
#define DDRA        *((volatile u8*)(0x3A))
#define PINA        *((volatile u8*)(0x39))

/***********************************************/
/*->defination of the  MCU registers of port B */
/***********************************************/
#define PORTB       *((volatile u8*)(0x38))
#define DDRB        *((volatile u8*)(0x37))
#define PINB        *((volatile u8*)(0x36))

/***********************************************/
/*->defination of the  MCU registers of port C */
/***********************************************/
#define PORTC       *((volatile u8*)(0x35))
#define DDRC        *((volatile u8*)(0x34))
#define PINC        *((volatile u8*)(0x33))


/***********************************************/
/*->defination of the  MCU registers of port D */
/***********************************************/
#define PORTD       *((volatile u8*)(0x32))
#define DDRD        *((volatile u8*)(0x31))
#define PIND        *((volatile u8*)(0x30))


#endif /* DIO_REGISTER_H_ */
