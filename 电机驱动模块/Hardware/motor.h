#include "gd32f4xx.h"
#include "systick.h"
#include "sys.h"

// ����꣬����ָ��ʹ��ʱ�ӵĺ�
#define ENABLE_CLOCK(__GPIOx__)   rcu_periph_clock_enable(__GPIOx__)

// ����꣬��������GPIOģʽ�����ѡ��ĺ�
#define SET_GPIO_MODE(__GPIOx__, __PIN__, __MODE__, __SPEED__, __AF__) \
    gpio_mode_set(__GPIOx__, __MODE__, GPIO_PUPD_NONE, __PIN__); \
    gpio_output_options_set(__GPIOx__, GPIO_OTYPE_PP, __SPEED__, __PIN__); \
    gpio_af_set(__GPIOx__, __AF__, __PIN__);

// ����꣬��������GPIO����ߵ�ƽ�ĺ�
#define SET_GPIO_HIGH(__GPIOx__, __PIN__) gpio_bit_write(__GPIOx__, __PIN__, SET)


//��ǰ��
#define LQ_FI PBout(4)
#define LQ_BI PAout(7)
//�����
#define LH_FI PBout(0)
#define LH BI PBout(1)
//��ǰ��
#define RQ_FI PAout(3)
#define	RQ_BI PAout(2)
//�Һ���
#define RH_FI PAout(0)
#define RH_BI PAout(1)

void Motor_Init(void);

//��ǰ��ǰ�������ˣ�ֹͣ
void Motor_LQ_front(uint16_t speed);
//void Motor_LQ_back(uint16_t speed);
//void Motor_LQ_stop(uint8_t mode);
////�����ǰ�������ˣ�ֹͣ
//void Motor_LH_front(uint16_t speed);
//void Motor_LH_back(uint16_t speed);
//void Motor_LH_stop(uint8_t mode);
////��ǰ��ǰ�������ˣ�ֹͣ
//void Motor_RQ_front(uint16_t speed);
//void Motor_RQ_back(uint16_t speed);
//void Motor_RQ_stop(uint8_t mode);
////�Һ���ǰ������ۣ�ֹͣ
//void Motor_RH_front(uint16_t speed);
//void Motor_RH back(uint16_t speed);
//void Motor_RH_stop(uint8_t mode);
