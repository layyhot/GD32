#ifndef _BSP_PWM_H
#define _BSP_PWM_H


#include "gd32f4xx.h"
#include "systick.h"

#define BSP_PWM_RCU     RCU_GPIOA               // PWM�˿�ʱ��
#define BSP_PWM_PORT    GPIOA 					// PWM�˿�
#define BSP_PWM_PIN     GPIO_PIN_5              // PWM����
#define BSP_PWM_AF      GPIO_AF_1				// PWM���Ÿ���


#define BSP_PWM1_TIMER_RCU  			RCU_TIMER1		// ��ʱ��ʱ��
#define BSP_PWM1_TIMER      			TIMER1        // ��ʱ��
#define BSP_PWM1_CHANNEL0  				TIMER_CH_0    // ��ʱ��ͨ��
#define BSP_PWM1_CHANNEL1 				TIMER_CH_1    // ��ʱ��ͨ��
#define BSP_PWM1_CHANNEL2				TIMER_CH_2    // ��ʱ��ͨ��
#define BSP_PWM1_CHANNEL3 				TIMER_CH_3    // ��ʱ��ͨ��

#define BSP_PWM2_TIMER_RCU  			RCU_TIMER2		// ��ʱ��ʱ��
#define BSP_PWM2_TIMER      			TIMER2        // ��ʱ��
#define BSP_PWM2_CHANNEL0  				TIMER_CH_0    // ��ʱ��ͨ��
#define BSP_PWM2_CHANNEL1 				TIMER_CH_1    // ��ʱ��ͨ��
#define BSP_PWM2_CHANNEL2				TIMER_CH_2    // ��ʱ��ͨ��
#define BSP_PWM2_CHANNEL3 				TIMER_CH_3    // ��ʱ��ͨ��

void pwm1_config(uint16_t pre,uint16_t per);			// PWM1���� 
void pwm2_config(uint16_t pre,uint16_t per);			// PWM2����

//void pwm_breathing_lamp(void);                  // �����ƺ���

#endif  /* BSP_PWM_H */
