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
	
    systick_config();          // �δ�ʱ����ʼ��
	  led_gpio_config();   			 // led��ʼ��
		usart_gpio_config(9600U);  // ����0��ʼ��

   // gpio_bit_set(GPIOD,GPIO_PIN_7);     // PD7����ߵ�ƽ
	 // gpio_bit_reset(GPIOD,GPIO_PIN_7);   // PD7����͵�ƽ
	
    while(1) {
				//gpio_bit_write(PORT_LED2,PIN_LED2,SET);     // LED2����ߵ�ƽ
		  	PDout(7) = 1;                                 // PD7����ߵ�ƽ
			  delay_1ms(1000);                           		// ��ʱ1s
			  //gpio_bit_write(PORT_LED2,PIN_LED2,RESET);   // LED2����͵�ƽ
			  PDout(7) = 0;                                 // PD7����͵�ƽ
			  delay_1ms(1000);                              // ��ʱ1s
			
			  uicount ++;     // ���α���+1
		  	fcount += 0.11; // �������+1
			  printf("uicount = %d,fcount = %.2f\r\n",uicount,fcount);  // ��ӡ�����Ϣ
    }
}
