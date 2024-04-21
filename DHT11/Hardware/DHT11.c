#include "dht11.h"

/**
  * @brief  DHT11_GPIO��ʼ������
  * @param  Mode��ָ����������ģʽ
  * @return None
  */
void DHT_GPIO_Init(uint32_t gpio_periph, uint32_t pin, uint32_t mode)
{
    gpio_deinit(gpio_periph); // ���� GPIO �˿�

    gpio_mode_set(gpio_periph, mode, GPIO_PUPD_PULLUP, pin); // ���� GPIO ģʽΪָ��ģʽ
}

/**
  * @brief  DHT11ģ����ʼ�źź���
  * @param  None
  * @return 1��0����־���źųɹ����
  */
uint8_t DHT_Start(void)
{
    DHT_GPIO_Init(DHT_GPIO_PORT, DHT_GPIO_PIN, GPIO_MODE_OUTPUT); // ���ģʽ

    gpio_bit_reset(DHT_GPIO_PORT, DHT_GPIO_PIN); // ���20ms�͵�ƽ������
    Delay_ms(20);
    gpio_bit_set(DHT_GPIO_PORT, DHT_GPIO_PIN);

    DHT_GPIO_Init(DHT_GPIO_PORT, DHT_GPIO_PIN, GPIO_MODE_INPUT); // ����ģʽ
    Delay_us(20);

    if (!gpio_input_bit_get(DHT_GPIO_PORT, DHT_GPIO_PIN))
    {
        while (!gpio_input_bit_get(DHT_GPIO_PORT, DHT_GPIO_PIN))
            ;
        while (gpio_input_bit_get(DHT_GPIO_PORT, DHT_GPIO_PIN))
            ;
        return 1;
    }
    return 0;
}

/**
  * @brief  ����DHT11������8λ������
  * @param  None
  * @return ���ؽ��յ���8λ����
  */
uint8_t DHT_Get_Byte_Data(void)
{
	int i;
    uint8_t temp = 0;
    for (i = 0; i < 8; i++)
    {
        temp <<= 1;
        while (!gpio_input_bit_get(DHT_GPIO_PORT, DHT_GPIO_PIN))
            ;
        Delay_us(28);
        if (gpio_input_bit_get(DHT_GPIO_PORT, DHT_GPIO_PIN))
        {
            temp |= 0x01;
        }
        while (gpio_input_bit_get(DHT_GPIO_PORT, DHT_GPIO_PIN))
            ;
    }
    return temp;
}

/**
  * @brief  ��ȡDHT11���¶�ʪ������
  * @param  buffer[]����Ҫ����һ���洢���ݵ�����
  * @return ��������У���Ƿ���ȷ 1����ȷ 0��ʧ��
  */
uint8_t DHT_Get_Temp_Humi_Data(uint8_t buffer[])
{
    if (DHT_Start())
    {
        buffer[0] = DHT_Get_Byte_Data();
        buffer[1] = DHT_Get_Byte_Data();
        buffer[2] = DHT_Get_Byte_Data();
        buffer[3] = DHT_Get_Byte_Data();
        buffer[4] = DHT_Get_Byte_Data();
    }
    return (buffer[0] + buffer[1] + buffer[2] + buffer[3] == buffer[4]) ? 1 : 0;
}
