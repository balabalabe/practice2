//#include<stdio.h>
//#include<math.h>
//int check(int test,int count,int limit){
//	//int a = pow(10, 7);
//	if ((test / (int)pow(10, count)) == test % 10){
//		test = test % (int)pow(10, count);
//		test = test / 10;
//		//这里掐头去尾的过程有讲究,如果先把最后一位去了,那么test就会少一位,
//		//但是count依旧是那么多位,就会产生被除数比除数还小的情况(结果test=0)
//		if (count < limit){
//			return 1;
//		}
//		return check(test, count-2,limit);
//	}
//	else{
//		return 0;
//	}
//}
//int main(){
//	int test = 159951;
//	int result = 0;
//	//方法1:直接翻转然后和原来的数进行比较如果相等则是回文数(但是有溢出的可能)
//	//  int test1=test;
//	//  long long sum = 0;
//	//	while (test != 0){
//	//		sum = sum * 10 + test % 10;
//	//		test = test / 10;
//	//		if (sum >= INT_MAX || sum <= INT_MIN){
//	//			printf("超出int所能表示的范围了\n");
//	//		    return 0;
//	//		}
//	//	}
//	//  if(sum == test1){
//	//    printf("是回文数");
//    //  }
//
//	//方法2:用递归的方法逐个判断最高位和最低位是否相等
//	int i = 1;
//	int count = 0;
//	while ((test/i)>0){
//		i *= 10;
//		count++;
//	}
//	int limit = count / 2;
//	result = check(test, count - 1, limit);
//	if (result == 1){
//		printf("是回文数\n");
//	}
//	if (result == 0){
//		printf("不是回文数\n");
//	}
//	return 0;
//}