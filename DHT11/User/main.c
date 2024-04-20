#include "gd32f4xx.h"
#include "systick.h"
#include <stdio.h>
#include "main.h"
#include "bsp_led.h"
#include "Delay.h"
#include "OLED.h"
#include "dht11.h"
#include <string.h>
#include <stdio.h>

// DHT11����
char str[20];
uint8_t DHT_Buffer[5];
int main(void)
{

    systick_config();
	OLED_Init();

    while(1)
    {        
        delay_1ms(1000);
		

		if(DHT_Get_Temp_Humi_Data(DHT_Buffer))
		{
			sprintf(str,"Temp:%d.%d",DHT_Buffer[2], DHT_Buffer[3]);
			OLED_ShowString(1, 1, "Hello!");
			OLED_ShowString(2, 1, (char *)str);
			sprintf(str,"Humi:%d.%d",DHT_Buffer[0], DHT_Buffer[1]);
			OLED_ShowString(3, 1, (char *)str);
		}
		Delay_ms(2000);
    }
}


