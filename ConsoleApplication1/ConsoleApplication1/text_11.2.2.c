#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int FIND(int i,int ch[5][5],int find){
	int j;
	if (i < 0){
		printf("�Ҳ�����");
		return 0;
	}
	for (j = i; j < 5; j++){
		if (ch[i][j] == find){
			printf("�ҵ���,�±�Ϊ%d %d", i, j);
			return 0;
		}
	}
	for (j = i; j < 5; j++){
		if (ch[j][i] == find){
			printf("�ҵ���,�±�Ϊ%d %d", j, i);
			return 0;
		}
	}
	return FIND(i - 1, ch, find);
}

int main(void){
//���Ͼ������ж�����
	int ch[5][5] = { 
		 1,  2,  3,  5,  6 ,
		 2,  4,  6,  8,  9 ,
		 4,  5,  10, 12, 17 ,
		 7,  9,  12, 16, 19 ,
		 10, 18, 20, 24, 26 
	};
	int find = 0;
	int i = 0;
	printf("��������Ѱ�ҵ�����\n");
	scanf("%d", &find);
	while (i < 5){
		if (ch[i][i] == find){
			printf("�ҵ���,�±��� %d  %d\n", i, i);
			break;
		}

		if (ch[i][i] > find){
			FIND(i-1,ch,find);
			break;
		}
		i++;
	}		
	return 0;
}