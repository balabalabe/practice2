//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<string.h>
//int flip(char* arr, char* arr1, int k, int n,int count){
//	char* first;
//	int i;
//	while (count){
//		if (n == 1){
//		char first = *arr;
//		for (i = 0; i < k; i++){
//			arr[i] = arr[i + 1];
//		}
//		arr[k - 1] = first;
//	}
//	if (n == 2){
//		char* first = arr + k - 1;
//		for (i = 0; i < k; i++){
//			   arr[i + 1] = arr[i];
//		    }
//		   arr[0] = *first;
//	    }
//	    count--;
//	}
//	return strcmp(arr, arr1);
//}
//int main(void){
//	char arr[] = "ABCDEF";
//	char arr1[] = "CDEFAB";
//	int k = 0;
//	int text = 0;
//	int count = 2;
//	int xuan = 0;
//	k = sizeof(arr) / sizeof(arr[0]);
//	printf("��ѡ����Ҫ���еķ�ת��ʽ,����1������,����2������\n");
//	scanf("%d", &xuan);
//	printf("Ҫ��ת�����ַ�\n");
//	scanf("%d", &count);
//	text=flip(arr, arr1, k - 1, xuan, count);//c����ַ�����һ��\0
//	if (text == 0){
//		printf("�����ַ���һ��\n");
//	}
//	if (text > 0){
//		printf("��һ��\n");
//	}
//	if (text < 0){
//		printf("��һ��\n");
//	}
//	return 0;
//}