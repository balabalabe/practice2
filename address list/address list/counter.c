//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//int add(int a, int b){
//	return a + b;
//}
//int sub(int a, int b){
//	return a - b;
//}
//int mul(int a, int b){
//	return a * b;
//}
//int div(int a, int b){
//	return a / b;
//}
//int main(){
//	int x, y;
//	int choose=1;
//	int ret = 0;
//	int(*p[5])(int x, int y) = { 0, add, sub, mul, div };
//	while (choose){
//		printf("请选择您需要的操作,1:add    2:sub    3:mul    4:div    0:退出\n");
//	    scanf("%d", &choose);
//		if ((choose <= 4 && choose >= 1)){
//			printf("请输入两个整数\n");
//			scanf("%d %d", &x, &y);
//			ret = (*p[choose])(x, y);
//		}
//		if (choose == 0){
//			printf("欢迎下次使用\n");
//		}
//		else{
//			printf("输入有误\n");
//		}	
//		printf("ret=%d\n", ret);
//	}
//	return 0;
//}