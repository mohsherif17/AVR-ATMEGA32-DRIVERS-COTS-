/***************************************************************************/
/************* AUTHOR: @ Muhammed Sherif Attia *****************************/
/************* FILE  : @ SPI_config.h          *****************************/
/************* breif : @ The config.h file fo   		********************/
/*************           the SPI Communication protocol in atmega32   ******/
/************* DATE  : @ 31/12/2023 ****************************************/
/***************************************************************************/

#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_

/**
 * -> SET the DATA ORDER
 * 			@ options:
 * 						1-  SPI_LSB
 * 						2-	SPI_MSB
 */

#define 		DATA_ORDER		SPI_MSB


/**
 * -> SET the MCU SPI mode
 * 			@ options:
 * 						1-  SPI_MASTER
 * 						2-	SPI_SLAVE
 */

#define 		SPI_MASTER_MODE		SPI_MASTER

/**
 * -> SET the CLOCK Polarity
 * 			@ options:
 * 						1-  SPI_ClockPolarity_LEADING_EDGE_RISING
 * 						2-	SPI_ClockPolarity_LEADING_EDGE_FALLING
 */

#define 		SPI_CLOCK_POLARITY		SPI_ClockPolarity_LEADING_EDGE_RISING

/**
 * -> SET the CLOCK rate
 * 			@ options:
 * 						1-  SPI_FOSC_4
 * 						2-	SPI_FOSC_16
 * 						3-  SPI_FOSC_64
 * 						4-  SPI_FOSC_128
 * 						5-  SPI_FOSC_2
 * 						6-  SPI_FOSC_8
 * 						7-  SPI_FOSC_32
 */

#define 		SPI_CLOCK_RATE 		 SPI_FOSC_4
#endif /* SPI_CONFIG_H_ */
