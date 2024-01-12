/***************************************************************************/
/************* AUTHOR: @ Muhammed Sherif Attia *****************************/
/************* FILE  : @ TWI_private.h         *****************************/
/************* breif : @ The private.h file for 		********************/
/*************           the TWI(I2C) Communication protocol in atmega32 ***/
/************* DATE  : @ 31/12/2023 ****************************************/
/***************************************************************************/

#ifndef TWI_PRIVATE_H_
#define TWI_PRIVATE_H_

#define   START   					0x08
#define   REPATERD_START   			0x10
#define   MT_SLA_ACK				0x18
#define   MR_SLA_ACK				0x40
#define   MT_DATA_ACK				0x28
#define  MT_DATA_NACK				0x30
#define   MR_DATA_ACK				0x50
#define  MR_DATA_NACK				0x58
#endif /* TWI_PRIVATE_H_ */
