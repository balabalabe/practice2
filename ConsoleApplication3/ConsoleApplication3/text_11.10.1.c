//#include<stdio.h>
//
//int main(void){
//	int a = 55;
//	int b = 88;
//	//加法可以理解为三个步骤,首先不进位相加得33
//	//再加上进位的数110,结果就为143
//	//对于二进制来说,这三个步骤也是通用的
//
//	int uncarry_bit = a^b;
//	//不进位相加的结果(相同位要么进位了,要么就为0了,所以不同位为1用异或)
//	int carry_bit = (a & b) << 1;
//	//进位的结果(与运算得到同为1的位,然后再左移一位得到的就是进位)
//	//比如 0110 和 0100,首先与运算得0100,再左移得到1000就是两数的进位
//
//	while (carry_bit){
//	    int tem = carry_bit;
//		//用一个临时变量保存上一次的进位结果
//		carry_bit = (carry_bit & uncarry_bit) << 1;
//		//用进位结果与不进位结果进行运算,是否再次产生进位,如果有进位则循环继续
//		uncarry_bit = uncarry_bit^tem;
//		//将上一次进位后的数加到没进位的数中
//	}
//	printf("%d\n", uncarry_bit);
//	return 0;
//}