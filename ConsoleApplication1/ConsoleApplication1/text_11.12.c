#include<stdio.h>
unsigned int reverse_bit (int value)
{
	unsigned int data = 0;
	int num = sizeof(int)* 8;//求整型的比特位，在这里为32
	int i = 0;
	while (i < num)
	{		//先检查程序的每一位二进制是否有1出现
		if ((value >> i) & 1)
		{
			data = data | (1 << (31 - i));
			//当出现1时，将这个1移动到目标位置
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
		//每次把ret左移一位，移动31次后最初的值就跑到了第一位
		ret <<= 1;
		//每次把传下来的x的最后一位保存到ret的最后一位
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
		//用乘以n次方的形式实现移位
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


