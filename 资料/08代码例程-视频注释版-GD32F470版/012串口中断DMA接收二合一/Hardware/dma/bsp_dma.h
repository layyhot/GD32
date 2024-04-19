#ifndef _BSP_DMA_H
#define _BSP_DMA_H

#include "gd32f4xx.h"
#include "systick.h"

 
/* USART0_RX DMA1_CH2 */
#define BSP_DMA_RCU   	       RCU_DMA1                  // DMAʱ��
#define BSP_DMA  				       DMA1 										 // DMA
#define BSP_DMA_CH  		       DMA_CH2									 // DMAͨ��
#define BSP_DMA_CH_IRQ  			 DMA1_Channel2_IRQn				 // DMA�ж�
#define BSP_DMA_CH_IRQ_HANDLER DMA1_Channel2_IRQHandler  // DMA�жϷ�������

void dma_config(void);   // ����DMA

#endif  /* BSP_DMA_H */