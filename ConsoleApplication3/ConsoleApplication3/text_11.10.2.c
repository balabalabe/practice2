#include<stdio.h>
int main(void){
	int count = 0;
	//计算100到1300有几个1,首先对每一位进行判断,如果出现1则count+1
	for (int i = 100; i <= 999; ++i){
		if (i % 10 == 1){
			count++;
		}
		if ((i / 10) % 10 == 1){
			count++;
		}
		if (i / 100 == 1){
			count++;
		}
	}
	for (int j = 1000; j <= 1300; ++j){
		if (j % 10 == 1){
			count++;
		}
		if ((j / 10) % 10 == 1){
			count++;
		}
		if ((j / 100) % 10 == 1){
			count++;
		}
		if ((j / 1000) == 1){
			count++;
		}
	}
	printf("%d", count);
	return 0;
}