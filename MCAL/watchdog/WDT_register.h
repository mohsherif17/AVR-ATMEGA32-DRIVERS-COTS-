/***************************************************************************/
/************* AUTHOR: @ Muhammed Sherif Attia *****************************/
/************* FILE  : @ WDT_register.h        *****************************/
/************* breif : @ The register.h file for 		********************/
/*************           the Watch Dog Timer prephilral of atmega32 ********/
/************* DATE  : @ 31/12/2023 ****************************************/
/***************************************************************************/
#ifndef WDT_REGISTER_H_
#define WDT_REGISTER_H_

#define  WDTCR									*((volatile u8*)(0x41))

#define WDT_WDE       3
#endif /* WDT_REGISTER_H_ */
