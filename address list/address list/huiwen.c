//#include<stdio.h>
//#include<math.h>
//int check(int test,int count,int limit){
//	//int a = pow(10, 7);
//	if ((test / (int)pow(10, count)) == test % 10){
//		test = test % (int)pow(10, count);
//		test = test / 10;
//		//������ͷȥβ�Ĺ����н���,����Ȱ����һλȥ��,��ôtest�ͻ���һλ,
//		//����count��������ô��λ,�ͻ�����������ȳ�����С�����(���test=0)
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
//	//����1:ֱ�ӷ�תȻ���ԭ���������бȽ����������ǻ�����(����������Ŀ���)
//	//  int test1=test;
//	//  long long sum = 0;
//	//	while (test != 0){
//	//		sum = sum * 10 + test % 10;
//	//		test = test / 10;
//	//		if (sum >= INT_MAX || sum <= INT_MIN){
//	//			printf("����int���ܱ�ʾ�ķ�Χ��\n");
//	//		    return 0;
//	//		}
//	//	}
//	//  if(sum == test1){
//	//    printf("�ǻ�����");
//    //  }
//
//	//����2:�õݹ�ķ�������ж����λ�����λ�Ƿ����
//	int i = 1;
//	int count = 0;
//	while ((test/i)>0){
//		i *= 10;
//		count++;
//	}
//	int limit = count / 2;
//	result = check(test, count - 1, limit);
//	if (result == 1){
//		printf("�ǻ�����\n");
//	}
//	if (result == 0){
//		printf("���ǻ�����\n");
//	}
//	return 0;
//}