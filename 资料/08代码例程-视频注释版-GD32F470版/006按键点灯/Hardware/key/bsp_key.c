/********************************************************************************
  * 文 件 名: bsp_key.c
  * 版 本 号: 初版
  * 修改作者: LC
  * 修改日期: 2022年04月15日
  * 功能介绍:          
  ******************************************************************************
  * 注意事项:
*********************************************************************************/

#include "bsp_key.h"
#include "sys.h"
#include "bsp_led.h"
#include "stdio.h"

/************************************************
函数名称 ： key_gpio_config
功    能 ： keygpio引脚配置
参    数 ： 无
返 回 值 ： 无
作    者 ： LC
*************************************************/
void key_gpio_config(void)
{
	/* 开启时钟 */
	rcu_periph_clock_enable(BSP_KEY_RCU);
	/* 配置GPIO的模式 */
	gpio_mode_set(BSP_KEY_PORT,GPIO_MODE_INPUT,GPIO_PUPD_PULLDOWN,BSP_KEY_PIN);
}

/************************************************
函数名称 ： key_scan
功    能 ： 按键扫描函数
参    数 ： 无
返 回 值 ： 无
作    者 ： LC
*************************************************/
void key_scan(void)
{
	/* 先读取按键引脚的电平 如果高电平，按键按下 */
	if(gpio_input_bit_get(BSP_KEY_PORT,BSP_KEY_PIN) == SET)         // 按键按下
	{
		delay_1ms(20);  // 延迟消抖 
		if(gpio_input_bit_get(BSP_KEY_PORT,BSP_KEY_PIN) == SET)       // 再次检测按键是否按下 
		{
			/* 执行对应的功能 */
			gpio_bit_toggle(PORT_LED2,PIN_LED2);    // led电平状态翻转
			printf("key press!\r\n");								// 串口打印key press!
			while(gpio_input_bit_get(BSP_KEY_PORT,BSP_KEY_PIN) == SET);  // 检测按键松开
			printf("key release!\r\n");             // 串口打印key release!
		}
	}
}