/********************************************************************************
  * �� �� ��: bsp_key.c
  * �� �� ��: ����
  * �޸�����: LC
  * �޸�����: 2022��04��15��
  * ���ܽ���:          
  ******************************************************************************
  * ע������:
*********************************************************************************/

#include "bsp_key.h"
#include "sys.h"
#include "bsp_led.h"
#include "stdio.h"

/************************************************
�������� �� key_gpio_config
��    �� �� keygpio��������
��    �� �� ��
�� �� ֵ �� ��
��    �� �� LC
*************************************************/
void key_gpio_config(void)
{
	/* ����ʱ�� */
	rcu_periph_clock_enable(BSP_KEY_RCU);
	/* ����GPIO��ģʽ */
	gpio_mode_set(BSP_KEY_PORT,GPIO_MODE_INPUT,GPIO_PUPD_PULLDOWN,BSP_KEY_PIN);
}

/************************************************
�������� �� key_scan
��    �� �� ����ɨ�躯��
��    �� �� ��
�� �� ֵ �� ��
��    �� �� LC
*************************************************/
void key_scan(void)
{
	/* �ȶ�ȡ�������ŵĵ�ƽ ����ߵ�ƽ���������� */
	if(gpio_input_bit_get(BSP_KEY_PORT,BSP_KEY_PIN) == SET)         // ��������
	{
		delay_1ms(20);  // �ӳ����� 
		if(gpio_input_bit_get(BSP_KEY_PORT,BSP_KEY_PIN) == SET)       // �ٴμ�ⰴ���Ƿ��� 
		{
			/* ִ�ж�Ӧ�Ĺ��� */
			gpio_bit_toggle(PORT_LED2,PIN_LED2);    // led��ƽ״̬��ת
			printf("key press!\r\n");								// ���ڴ�ӡkey press!
			while(gpio_input_bit_get(BSP_KEY_PORT,BSP_KEY_PIN) == SET);  // ��ⰴ���ɿ�
			printf("key release!\r\n");             // ���ڴ�ӡkey release!
		}
	}
}