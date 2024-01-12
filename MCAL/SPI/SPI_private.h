
/***************************************************************************/
/************* AUTHOR: @ Muhammed Sherif Attia *****************************/
/************* FILE  : @ SPI_private.h         *****************************/
/************* breif : @ The private.h file for 		********************/
/*************           the SPI Communication protocol in atmega32   ******/
/************* DATE  : @ 31/12/2023 ****************************************/
/***************************************************************************/

#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_
/*SPI READ DATA DIRECTION*/

#define  SPI_LSB 	1
#define  SPI_MSB	2

/*MCU SPI MODE*/
#define  SPI_MASTER		1
#define  SPI_SLAVE		2
/*clock polarity*/
#define  SPI_ClockPolarity_LEADING_EDGE_RISING	1
#define  SPI_ClockPolarity_LEADING_EDGE_FALLING	2
/*clock phase*/
#define  SPI_ClockPhase_LEADING_EDGE_RISING		1
#define  SPI_ClockPhase_LEADING_EDGE_FALLING	2
/**/
#define 		SPI_FOSC_4				0b00000000
#define 		SPI_FOSC_16				0b00000001
#define 		SPI_FOSC_64				0b00000010
#define 		SPI_FOSC_128			0b00000011
#define 		SPI_FOSC_2				0b00000100
#define 		SPI_FOSC_8				0b00000101
#define 		SPI_FOSC_32				0b00000110


#endif /* SPI_PRIVATE_H_ */
