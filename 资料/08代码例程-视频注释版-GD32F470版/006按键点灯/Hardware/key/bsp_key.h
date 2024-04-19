#ifndef _BSP_KEY_H
#define _BSP_KEY_H

#include "gd32f4xx.h"
#include "systick.h"

#define BSP_KEY_RCU   RCU_GPIOA   // �����˿�ʱ��
#define BSP_KEY_PORT  GPIOA       // �����˿�
#define BSP_KEY_PIN   GPIO_PIN_0  // ��������
 
void key_gpio_config(void);       // key gpio��������
void key_scan(void);              // ����ɨ��

#endif  /* BSP_KEY_H */