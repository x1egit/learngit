#include "stm32f10x.h"
#include "key.h"
#include "bsp_SysTick.h"

//������ʼ������
void KEY_Init(void) //IO��ʼ��
{
 	GPIO_InitTypeDef GPIO_InitStructure;
	//��ʼ��KEY0-->GPIOA.13,KEY1-->GPIOA.15  ��������
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);//ʹ��PORTEʱ��

	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_3|GPIO_Pin_4;//PE3~4
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //���ó���������
 	//GPIO_Init(GPIOE, &GPIO_InitStructure);//��ʼ��GPIOE4


}
//����������
//���ذ���ֵ
//mode:0,��֧��������;1,֧��������;
//0��û���κΰ�������
//1��KEY0����
//2��KEY1����
//ע��˺�������Ӧ���ȼ�,KEY0>KEY1
u8 KEY_Scan(u8 mode)
{
	static u8 key_up=1;//�������ɿ���־
	if(mode)key_up=1;  //֧������
	if(key_up&&(KEY0==0||KEY1==0))
	{
		Delay_ms(10);//ȥ����
		key_up=0;
		if(KEY0==0)return KEY_RIGHT;          //#define KEY_RIGHT	1
		else if(KEY1==0)return KEY_DOWN;      //#define KEY_DOWN	2
	}else if(KEY0==1&&KEY1==1)key_up=1;
 	return 0;// �ް�������
}









