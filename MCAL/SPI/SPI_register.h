/***************************************************************************/
/************* AUTHOR: @ Muhammed Sherif Attia *****************************/
/************* FILE  : @ SPI_register.h        *****************************/
/************* breif : @ The register.h file for 		********************/
/*************           the SPI Communication protocol in atmega32   ******/
/************* DATE  : @ 31/12/2023 ****************************************/
/***************************************************************************/

#ifndef SPI_REGISTER_H_
#define SPI_REGISTER_H_

#define 		SPDR		*((volatile u8*)(0x2F))

/**************************************************/
#define 		SPSR		*((volatile u8*)(0x2E))

#define   		SPI_SPIF					7
#define   		SPI_WCOL					6
#define			SPI_SPI2X					0

/*************************************************/
#define 		SPCR		*((volatile u8*)(0x2D))

#define			SPI_SPIE					7
#define			SPI_SPE						6
#define			SPI_DORD					5
#define			SPI_MSTR					4
#define			SPI_CPOL					3
#define			SPI_CPHA					2
#define			SPI_SPR1					1
#define			SPI_SPR0					0

#endif /* SPI_REGISTER_H_ */
