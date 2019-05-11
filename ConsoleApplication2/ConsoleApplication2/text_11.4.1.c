//#include<stdio.h>
//
//void flip(char* str, int k, int num){
//	for (int i = 0; i < k; i++){
//		char first = *str;
//		for (int j = 0; j < num - 1; j++){
//			*(str + j) = *(str + j + 1);
//			//交换两字符还可以用异或的方法
//		    //*left = *left^*right;
//		    //*right = *left^*right;
//		    //*left = *left^*right;
//		}
//		*(str + num - 1) = first;
//	}
//}
//
//int main(void){
//	char str[] = "ABCD";
//	int k = 2;
//	int num = 0;
//	num=sizeof(str) / sizeof(str[0]);
//	flip(str,k,num-1);//c风格字符串有一个\0结尾,故num-1
//	int i = 0;
//	for (i = 0; i < 4; i++){
//		printf("%c", str[i]);
//	}
//	return 0;
//}