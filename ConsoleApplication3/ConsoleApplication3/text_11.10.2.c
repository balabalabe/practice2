#include<stdio.h>
int main(void){
	int count = 0;
	//����100��1300�м���1,���ȶ�ÿһλ�����ж�,�������1��count+1
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