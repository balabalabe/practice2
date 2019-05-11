//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <string.h>//函数指针
//void check(char *a, char *b, int(*cmp)(const char *, const char *))
//{
//	if ((*cmp)(a, b) == 0)
//		//cmp指向库函数strcmp(),调用cmp就是调用strcmp(),并且a和b作为参数
//		printf("相同\n");
//	else
//		printf("不相同\n");
//}
//int main(void)
//{
//	char arr1[1024], arr2[1024];
//	int(*p)(const char *, const char *);//定义一个函数指针p
//	//将库函数strcmp的地址赋值给函数指针p
//	//并且用限定符const保持调用后指针指向内容不变
//	p = strcmp;
//
//	printf("请输入两个字符串,然后进行对比\n");
//	scanf("%s", &arr1);
//	scanf("%s", &arr2);
//	check(arr1, arr2, p);
//	return 0;
//}
