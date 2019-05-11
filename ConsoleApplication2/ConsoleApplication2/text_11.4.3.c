//#include<stdio.h>
//int seach(int* p, int num){
//	int i = 0;
//	for (i = 0; i < num - 1; i++){
//		//用第一位与后面的数全部进行异或运算
//		//活用两个相同的数异或运算为0的特性
//		//最终可以把单独的那个数保留下来
//		*p = *p ^ *(p + i + 1);
//	}
//	return *p;
//}
//int main(void){
//	int ch[] = { 1, 2, 4, 5, 3, 1, 2, 3, 5, 9 };
//	int arr[10] = { 0 };
//	int num = 0;
//	int record = 0;
//	num = sizeof(ch) / sizeof(ch[0]);
//	int text = 0;
//	//用一个循环寻找异或后的第一个为1的二进制位(第一个不相同的位)
//
//	text = seach(ch, num);//两个单独数异或结果
//
//	for (int i = 0; i < 32; i++){
//		if ((text >> i) == 1){
//			record = i;//记录该位在二进制的位置
//			break;
//		}
//	}
//
//	for (int j = 0; j < num; j++){
//		if ((ch[j] >> record) == 1){
//			arr[j] = ch[j];
//		}
//	}
//	int put = seach(arr, num);
//	//这里要一个临时变量put来储存seach的结果
//	//因为第一次调用的时候已经将原来的ch数组破坏了,所以不能反复调用seach数组
//	printf("%d\n",put);	
//	printf("%d\n", put ^ text);
//	return 0;
//}
