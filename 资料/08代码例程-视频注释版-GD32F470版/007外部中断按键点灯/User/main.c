/********************************************************************************
  * �� �� ��: main.c
  * �� �� ��: ����
  * �޸�����: LC
  * �޸�����: 2022��04��12��
  * ���ܽ���:          
  ******************************************************************************
  * ע������:
*********************************************************************************/

#include "gd32f4xx.h"
#include "systick.h"
#include <stdio.h>
#include "main.h"
#include "bsp_led.h"
#include "sys.h"
#include "bsp_usart.h"
#include "bsp_key.h"



/************************************************
�������� �� main
��    �� �� ������
��    �� �� ��
�� �� ֵ �� ��
��    �� �� LC
*************************************************/
int main(void)
{

	  uint16_t uicount = 0;
	  float fcount = 0.0;
	
	  nvic_priority_group_set(NVIC_PRIGROUP_PRE2_SUB2);  // ���ȼ�����
	
    systick_config();          // �δ�ʱ����ʼ��
	  led_gpio_config();   			 // led��ʼ��
    key_gpio_config(); 				 // key��ʼ��
	  usart_gpio_config(9600U);  // ����0��ʼ��
	
    while(1) {
		
    }
}
