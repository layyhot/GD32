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
#include "bsp_basic_timer.h"
#include "bsp_pwm.h"
#include "stdlib.h"
#include "string.h"
#include "bsp_dma.h"



/************************************************
�������� �� main
��    �� �� ������
��    �� �� ��
�� �� ֵ �� ��
��    �� �� LC
*************************************************/
int main(void)
{

	  nvic_priority_group_set(NVIC_PRIGROUP_PRE2_SUB2);  // ���ȼ�����
	
    systick_config();          					// �δ�ʱ����ʼ��
	  led_gpio_config();   								// led��ʼ��
    key_gpio_config(); 				 					// key��ʼ��
	  usart_gpio_config(9600U);  					// ����0��ʼ��
	  dma_config();												// DMA����

    while(1) {
			
			/* �ȴ����ݴ������ */
			if(g_recv_complete_flag)  										// ���ݽ������
			{ 
				g_recv_complete_flag = 0;                   // �ȴ��´ν���
				printf("g_recv_length:%d ",g_recv_length);  // ��ӡ���յ����ݳ���
				printf("g_recv_buff:%s\r\n",g_recv_buff);		// ��ӡ���յ�����
				memset(g_recv_buff,0,g_recv_length);				// �������
				g_recv_length = 0;													// ��ճ���
			}
		
    }
}
