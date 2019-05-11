#include<stdio.h>

int strlen(char* str){
	int count = 0;
	while (*str){
		count++;
		str++;
	}
	return count;//�õ��ַ�������
}

void reverse_str(char* left, char* right){
	while (left < right){
		char temp = *left;
		*left = *right;
		*right = temp;		//��ͷβ���ݽ��н���
		left++;
		right--;
	}
}

void reverse(char* str){
	char* left = str;
	char* right = str + strlen(str) - 1;
	char* cur = str;
	//�����巭ת
	reverse_str(left, right);

	while (*cur){
		char* start = cur;
		while (((*cur) != ' ') && ((*cur) != '\0')){
			cur++;
		}
		//�����ʷ�ת
		reverse_str(start, cur - 1);
		if (*cur == ' '){
			cur++;
		}
	}
}

int main(void){
	char str[] = "student a am i";
	reverse(str);
	printf("%s\n", str);
	return 0;
}