//#include<stdio.h>
//int main(){
//	//方法1:用循环每次乘2直到比待测数大
//	int a = 8;
//	int count = 0;
//	//方法2:用二进制判断,2的幂有个特点就是它的二进制数只有一位是1,其余都是0
//	//比如2的三次幂就是.....0100,四次幂就是.....1000,只要遍历一遍看是否只有一个1就得了
//	for (int i = 0; i < 32; i++){
//		if ((a >> i) & 1 == 1){
//			count++;
//		}
//	}
//	if (count != 1){
//		printf("不是2的幂\n");
//	}
//	if (count == 1){
//		printf("是2的幂\n");
//	}
//	return 0;
//}