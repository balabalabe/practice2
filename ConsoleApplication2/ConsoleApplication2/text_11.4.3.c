//#include<stdio.h>
//int seach(int* p, int num){
//	int i = 0;
//	for (i = 0; i < num - 1; i++){
//		//�õ�һλ��������ȫ�������������
//		//����������ͬ�����������Ϊ0������
//		//���տ��԰ѵ������Ǹ�����������
//		*p = *p ^ *(p + i + 1);
//	}
//	return *p;
//}
//int main(void){
//	int ch[] = { 1, 2, 4, 5, 3, 1, 2, 3, 5, 9 };
//	int arr[10] = { 0 };
//	int num = 0;
//	int record = 0;
//	num = sizeof(ch) / sizeof(ch[0]);
//	int text = 0;
//	//��һ��ѭ��Ѱ������ĵ�һ��Ϊ1�Ķ�����λ(��һ������ͬ��λ)
//
//	text = seach(ch, num);//���������������
//
//	for (int i = 0; i < 32; i++){
//		if ((text >> i) == 1){
//			record = i;//��¼��λ�ڶ����Ƶ�λ��
//			break;
//		}
//	}
//
//	for (int j = 0; j < num; j++){
//		if ((ch[j] >> record) == 1){
//			arr[j] = ch[j];
//		}
//	}
//	int put = seach(arr, num);
//	//����Ҫһ����ʱ����put������seach�Ľ��
//	//��Ϊ��һ�ε��õ�ʱ���Ѿ���ԭ����ch�����ƻ���,���Բ��ܷ�������seach����
//	printf("%d\n",put);	
//	printf("%d\n", put ^ text);
//	return 0;
//}
