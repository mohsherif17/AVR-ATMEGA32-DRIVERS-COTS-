/***************************************************************************/
/************* AUTHOR: @ Muhammed Sherif Attia *****************************/
/************* FILE  : @ TWI_register.h        *****************************/
/************* breif : @ The register.h file for 		********************/
/*************           the TWI(I2C) Communication protocol in atmega32 ***/
/************* DATE  : @ 31/12/2023 ****************************************/
/***************************************************************************/

#ifndef TWI_REGISTER_H_
#define TWI_REGISTER_H_

#define  	TWBR			*((volatile u8*)(20))


#define  	TWCR			*((volatile u8*)(56))

#define     TWINT						7
#define 	TWEA						6
#define     TWSTA						5
#define 	TWSTO						4
#define     TWEN						2
#define     TWIE						0



#define  	TWSR			*((volatile u8*)(21))


#define  	TWDR			*((volatile u8*)(23))


#define  	TWAR			*((volatile u8*)(22))


#endif /* TWI_REGISTER_H_ */
