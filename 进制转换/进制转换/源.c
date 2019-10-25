#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void){
	printf("请输入一个整数/n");
	int num = 0;
	scanf("%d", &num);

	int text = 1;
	int count = 0;
	while (num >= text){
		text = text * 2;
		count++;
	}
	count--;
	text = text / 2;
	if (num == text){
		printf("1");
		for (int j = count; j > 0; j--){
			printf("0");
		}
		return 0;
	}

	while (text > 0){	
		int add = 0;
		num = num - text;
		if (num < 0){
			num = num + text;
			add = 1;
			printf("0");
		}
		if (add == 0){
			printf("1");
		}
		text = text / 2;
	}
	printf("\n");
	return 0;
}