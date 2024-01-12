/***************************************************************************/
/************* AUTHOR: @ Muhammed Sherif Attia *****************************/
/************* FILE  : @ EXTI0_register.h      *****************************/
/************* breif : @ The register.h file for 		********************/
/*************           the External interrupt prephilral of atmega32 *****/
/************* DATE  : @ 31/12/2023 ****************************************/
/***************************************************************************/

#ifndef EXTI0_REGISTER_H_
#define EXTI0_REGISTER_H_
/************** the MCUR register address defination in the MCU **************/
#define     MCUCR                 *((volatile u8*)(0x55))

#define    EXTI_ISC11					3
#define    EXTI_ISC10					2
#define    EXTI_ISC01					1
#define    EXTI_ISC00					0

/************* the MCUCSR register address defination in the MCU *************/
#define     MCUCSR                *((volatile u8*)(0x54))

#define    EXTI_ISC2					6

/************** the GICR register address defination in the MCU **************/
#define     GICR                  *((volatile u8*)(0x5B))

#define    EXTI_INT1					7
#define    EXTI_INT0					6
#define    EXTI_INT2					5
/************** the GIFR register address defination in the MCU **************/
#define     GIFR                  *((volatile u8*)(0x5A))

#define    EXTI_INTF1					7
#define    EXTI_INTF0					6
#define    EXTI_INTF2					5
#endif /* EXTI0_REGISTER_H_ */
