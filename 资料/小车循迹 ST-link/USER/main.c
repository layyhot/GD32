#include "stm32f10x.h"
#include "xunji.h"
#include "delay.h"


/*
			˫������ 

Motor��       PB0��PB1     PB10��PB11
PWM(TIM4)��   PB6(CH1)     PB8(CH3)
IR��          PB3          PB5
 
*/




//��ʼ��С��״̬
 void Init()
{
	TIM_SetCompare1(TIM4,25);
	TIM_SetCompare3(TIM4,25);
	IN1=1;
	IN2=0;
	IN3=1;
	IN4=0;
}
 
 int main(void)
 {	

		motor_gpio();   //���ų�ʼ��
		xunji_gpio();
		pwm();           //PWM��ʼ��   
		delay_init();
	  Init();         //��ʼ��С��״̬
			while(1)
			{
 
					if(LEFT_ONE==0&&LEFT_TWO==0)        //��û�ȵ�����
					{
							 run();
					}
					
					else if(LEFT_ONE==0&&LEFT_TWO==1)   //�ұ�̽ͷ�ȵ�����
					{
					
							right();
					}
					
					else if(LEFT_ONE==1&&LEFT_TWO==0)  //���̽ͷ�ȵ�����
					{
					
							left();
					}
					
		      else if(LEFT_ONE==1&&LEFT_TWO==1)   //���ȵ�����
					{
					
							run();
					}
					
					else
						stop();
				
			 }
	
}

