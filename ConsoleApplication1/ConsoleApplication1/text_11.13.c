#include<stdio.h>
int seach(int* p,int num){
	int i = 0;
	for (i = 0; i < num - 1; i++){
		//用第一位与后面的数全部进行异或运算
		//活用两个相同的数异或运算为0的特性
		//最终可以把单独的那个数保留下来
		*p = *p ^ *(p + i + 1);
	}
	return *p;
}
int main(void){
	int ch[] = { 1, 2, 4, 5, 3, 1, 2, 3, 5 };
	int* p = &ch;
	int num = 0;
	num=sizeof(ch) / sizeof(ch[0]);
	printf("%d", seach(p,num));
	return 0;
}
