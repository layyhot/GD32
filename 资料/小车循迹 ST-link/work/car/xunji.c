#include "xunji.h"  
#include "stm32f10x.h"

void motor_gpio()
{

  GPIO_InitTypeDef  GPIO_InitStructure;
	 
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	  
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_10|GPIO_Pin_11; 		
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 	  //������� 
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	 
  GPIO_Init(GPIOB, &GPIO_InitStructure);			     

}

void xunji_gpio()
{

  GPIO_InitTypeDef  GPIO_InitStructure;
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	  
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3|GPIO_Pin_5;		
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;  //��������
  GPIO_Init(GPIOB, &GPIO_InitStructure);		

}
void pwm()
{

	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_8; 		
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; //������� 
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	 
  GPIO_Init(GPIOB, &GPIO_InitStructure);

	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);	  //ʹ�ܶ�ʱ��4ʱ�� 
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);   //ʹ��GPIOBʱ��
	  

	
	TIM_TimeBaseStructure.TIM_Period =99;    //��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ
	TIM_TimeBaseStructure.TIM_Prescaler =71;     //����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;   //����ʱ�ӷָ�:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;   //TIM���ϼ���ģʽ 
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);    
	
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;  //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ1
 	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;   //�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;    //�������:TIM����Ƚϼ��Ը�
  TIM_OCInitStructure.TIM_Pulse=0;
	
	TIM_OC1Init(TIM4, &TIM_OCInitStructure);  
	TIM_OC3Init(TIM4, &TIM_OCInitStructure);  
	

	TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Enable);   //ʹ��TIM4��CCR1�ϵ�Ԥװ�ؼĴ���
	TIM_OC3PreloadConfig(TIM4, TIM_OCPreload_Enable);   //ʹ��TIM4��CCR3�ϵ�Ԥװ�ؼĴ���

	
	TIM_Cmd(TIM4, ENABLE);   //ʹ��TIM4
}
void run()
{

		TIM_SetCompare1(TIM4,30);  
   	TIM_SetCompare3(TIM4,30);
		IN1 = 1;
		IN2 = 0;
		
		IN3 = 1;
		IN4 = 0;
}
void back()
{
		TIM_SetCompare1(TIM4,70);
		TIM_SetCompare3(TIM4,70);
	
		IN1 = 0;
		IN2 = 1;
		
 
		IN3 = 0;
		IN4 = 1;
}
void right()
{
		TIM_SetCompare1(TIM4,0);
		TIM_SetCompare3(TIM4,30);
	
		IN1 = 1;
		IN2 = 0;
	  
		IN3 = 0;
		IN4 = 0;
}
void left()
{
		TIM_SetCompare1(TIM4,30);
		TIM_SetCompare3(TIM4,0);
		
		IN1 = 0;
		IN2 = 0;
		
		IN3 = 1;
		IN4 = 0;
}

void stop()
{

		 IN1 = 0;
		 IN2 = 0;
		
		 IN3 = 0;
		 IN4 = 0;
	}
