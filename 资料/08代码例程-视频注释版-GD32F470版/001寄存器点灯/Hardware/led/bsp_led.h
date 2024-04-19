#ifndef _BSP_LED_H
#define _BSP_LED_H


#include "gd32f4xx.h"
#include "systick.h"

#define BSP_RCU_BASE 		(unsigned int)0x40023800U                   // RCU�Ĵ����Ļ���ַ
#define BSP_RCU_AHB1EN 	*(unsigned int*)(BSP_RCU_BASE + 0x30U)			// AHB1ʹ�ܼĴ�����ַ

#define BSP_GPIOD_BASE 	(unsigned int)0x40020C00U    								// GPIOD�Ļ���ַ
#define BSP_GPIOD_CTL 	*(unsigned int*)(BSP_GPIOD_BASE + 0x00U)    // GPIOD���ƼĴ����ĵ�ַ
#define BSP_GPIOD_PUD 	*(unsigned int*)(BSP_GPIOD_BASE + 0x0CU)    // GPIOD���������Ĵ����ĵ�ַ
#define BSP_GPIOD_OMODE *(unsigned int*)(BSP_GPIOD_BASE + 0x04U)    // GPIOD�����ģʽ�Ĵ����ĵ�ַ
#define BSP_GPIOD_OSPD 	*(unsigned int*)(BSP_GPIOD_BASE + 0x08U)    // GPIOD���ٶȼĴ����ĵ�ַ
#define BSP_GPIOD_OCTL 	*(unsigned int*)(BSP_GPIOD_BASE + 0x14U)    // GPIOD��������ƼĴ����ĵ�ַ
#define BSP_GPIOD_BOP 	*(unsigned int*)(BSP_GPIOD_BASE + 0x18U)    // GPIOD��λ�����Ĵ����ĵ�ַ
	
void led_gpio_config(void); // led gpio��������
 
#endif  /* BSP_LED_H */