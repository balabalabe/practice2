#include<stdio.h>
unsigned int reverse_bit (int value)
{
	unsigned int data = 0;
	int num = sizeof(int)* 8;//�����͵ı���λ��������Ϊ32
	int i = 0;
	while (i < num)
	{		//�ȼ������ÿһλ�������Ƿ���1����
		if ((value >> i) & 1)
		{
			data = data | (1 << (31 - i));
			//������1ʱ�������1�ƶ���Ŀ��λ��
		}
		i++;
	}
	return data;
}

unsigned int reverse_bit1(int x){
	int i = 0;
	unsigned int ret = 0;
	int num = sizeof(int)* 8;
	for (i = 0; i < num; i++)
	{
		//ÿ�ΰ�ret����һλ���ƶ�31�κ������ֵ���ܵ��˵�һλ
		ret <<= 1;
		//ÿ�ΰѴ�������x�����һλ���浽ret�����һλ
		ret |= (x >> i) & 1;
	}
	return ret;
}

unsigned int reverse_bit2(int y){
	unsigned int sum = 0;
	int i = 0;
	int num = sizeof(int)* 8;
	for (i = 0; i < num; i++){
		sum += ((y >> i) & 1)*pow(2, 31 - i);
		//�ó���n�η�����ʽʵ����λ
	}
	return sum;
}

int main(void){
	unsigned int value = 25;
	printf("%u\n", reverse_bit(value));
	printf("%u\n", reverse_bit(value));
	printf("%u\n", reverse_bit(value));
	return 0;
}


