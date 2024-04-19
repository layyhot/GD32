/********************************************************************************
  * �� �� ��: bsp_dma.c
  * �� �� ��: ����
  * �޸�����: LC
  * �޸�����: 2022��04��21��
  * ���ܽ���:          
  ******************************************************************************
  * ע������:
*********************************************************************************/
#include "bsp_dma.h"
#include "bsp_usart.h"

/************************************************
�������� �� dma_config
��    �� �� DMA����
��    �� �� ��
�� �� ֵ �� ��
��    �� �� LC
*************************************************/
void dma_config(void)
{
	 dma_single_data_parameter_struct dma_init_struct;                // DMA�����ݽṹ��
   rcu_periph_clock_enable(BSP_DMA_RCU);														// ����DMAʱ��
  	
	 dma_deinit(BSP_DMA,BSP_DMA_CH);																	// ��ʼ��DMAͨ��
	
	 /* ����DMA��ʼ������ */
	 dma_init_struct.periph_addr 				 = (uint32_t)&USART_DATA(BSP_USART);   // �����ַ                       
   dma_init_struct.periph_inc					 = DMA_PERIPH_INCREASE_DISABLE;        // ��ʹ������ģʽ��Ϊ�̶�ģʽ  
   dma_init_struct.memory0_addr 			 = (uint32_t)g_recv_buff;              // �ڴ��ַ          
   dma_init_struct.memory_inc 				 = DMA_MEMORY_INCREASE_ENABLE;      	 // ����ģʽ                    
   dma_init_struct.periph_memory_width = DMA_PERIPH_WIDTH_8BIT;         		 // һ�δ��䳤��8bit         
   dma_init_struct.circular_mode 			 = DMA_CIRCULAR_MODE_DISABLE;      		 // �ر�ѭ��ģʽ               
   dma_init_struct.direction 					 = DMA_PERIPH_TO_MEMORY;          		 // ���赽�ڴ�                  
   dma_init_struct.number 						 = USART_RECEIVE_LENGTH;         			 // Ҫ�����������                     
   dma_init_struct.priority						 = DMA_PRIORITY_ULTRA_HIGH;  					 // �������ȼ�
	 /* ��ʼ��DMA�ṹ�� */
	 dma_single_data_mode_init(BSP_DMA,BSP_DMA_CH,&dma_init_struct);
	
	 /* ʹ��ͨ������ */
	 dma_channel_subperipheral_select(BSP_DMA,BSP_DMA_CH,DMA_SUBPERI4);
	 /* ʹ��DMAͨ�� */
	 dma_channel_enable(BSP_DMA,BSP_DMA_CH);
	
	 /* ʹ��DMAͨ���ж� */
	 dma_interrupt_enable(BSP_DMA,BSP_DMA_CH,DMA_CHXCTL_FTFIE);
	 /* �����ж����ȼ� */
	 nvic_irq_enable(BSP_DMA_CH_IRQ, 2, 1); 
	 /* ʹ�ܴ���DMA���� */
	 usart_dma_receive_config(BSP_USART,USART_DENR_ENABLE);
}

/************************************************
�������� �� BSP_DMA_CH_IRQHandler
��    �� �� DMA�жϷ����� 
��    �� �� ��
�� �� ֵ �� ��
��    �� �� LC
*************************************************/
void BSP_DMA_CH_IRQ_HANDLER(void)
{
	
	if(dma_interrupt_flag_get(BSP_DMA,BSP_DMA_CH,DMA_INT_FLAG_FTF) == SET)  // ��������ж� 
	{	
	  dma_interrupt_flag_clear(BSP_DMA,BSP_DMA_CH,DMA_INT_FLAG_FTF);				// ���жϱ�־λ
		//g_recv_complete_flag = 1;                                           // ���ݴ������ 
  }
}