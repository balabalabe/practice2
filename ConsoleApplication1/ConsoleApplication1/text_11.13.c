#include<stdio.h>
int seach(int* p,int num){
	int i = 0;
	for (i = 0; i < num - 1; i++){
		//�õ�һλ��������ȫ�������������
		//����������ͬ�����������Ϊ0������
		//���տ��԰ѵ������Ǹ�����������
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
