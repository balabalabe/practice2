#include<stdio.h>
#include<stdlib.h>
//int HanNuo(int x){
//	if (x <= 1){
//		return 1;
//	}
//	else
//		return 2 * HanNuo(x - 1) + 1;
//}
//int main(void){
//	int i = 3;
//	printf("%d", HanNuo(i));
//	system("pause");
//	return 0;
//}

//int main(void){//ÒþÊ½×ª»»
//	char a = -1;
//	signed char b = -1;
//	unsigned char c = -1;
//	printf("a=%d  b=%d  c=%d", a, b, c);
//	system("pause");
//	return 0;
//}

//int main(void){
//	char a = -128;
//	printf("%u", a);
//	system("pause");
//	return 0;
//}

//int main(void){
//	int a[5] = { 1, 2, 3, 4, 5 };
//	int *ptr = (int *)(&a + 1);
//	printf("%d,%d", *(a + 1), *(ptr - 1));
//	system("pause");
//	return 0;
//}

//int main(void){
//	char* a[] = { "work", "at", "alibaba" };
//	char** pa = a;
//	pa++;
//	printf("%s\n", *pa);
//	system("pause");
//	return 0;
//}

//int main(void){
//	int a[5][5];
//	int(*p)[4];
//	p = a;
//	printf("a_ptr=%#p,p_ptr=%#p\n", &a[4][2], &p[4][2]);
//	printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);
//	system("pause");
//	return 0;
//}

int main(void){
	int aa[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int* ptr1 = (int*)(&aa + 1);
	int* ptr2 = (int*)(*(aa + 1));
	printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));
	system("pause");
	return 0;
}