#include<stdio.h>
void swap_num(int* arr, int len)
//����1
//�����ȱ���һ��,�������������,Ȼ���ٰ�����ż������ķ���ʵ��
{
	int i = 0;
	for (; i < len; i++)
	{
		if (0 != arr[i] % 2){
			printf("%d ", arr[i]);
		}
	}
	for (i = 0; i < len; i++)
	{
		if (0 == arr[i] % 2){
			printf("%d ", arr[i]);
		}
	}
	printf("\n");
}

void swap_num2(int* arr, int len)
//����2
//ֱ���������ڲ�������ż����,Ȼ����forѭ�����
{
	int *left = arr;//ȡ��ߵ�ֵ
	int *right = arr + len - 1;//ȡ�ұߵ�ֵ
	int tmp = 0;
	while (left < right)//������������Խ�磬ʼ�������С���ұ�
	{
		while ((left < right) && (*left) % 2 != 0)//��֤��Խ�絫����������
		{
			left++;
		}
		while ((left < right) && (*right) % 2 == 0)//��֤��Խ�絫�����ҵ�ż��
		{
			right--;
		}
		if (left < right)//���ҵ���������ż������
		{
			tmp = *left;
			*left = *right;
			*right = tmp;
		}
	}
}



int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int len = sizeof(arr) / sizeof(arr[0]);
	swap_num(arr, len);
	swap_num2(arr, len);
	int i = 0;
	for (i = 0; i < len; i++){
	    printf("%d ", arr[i]);
	}
	return 0;
}