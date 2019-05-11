#include<stdio.h>
void swap_num(int* arr, int len)
//方法1
//采用先遍历一次,将所有奇数输出,然后再把所有偶数输出的方法实现
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
//方法2
//直接在数组内部进行奇偶调换,然后用for循环输出
{
	int *left = arr;//取左边的值
	int *right = arr + len - 1;//取右边的值
	int tmp = 0;
	while (left < right)//整体条件不能越界，始终是左边小于右边
	{
		while ((left < right) && (*left) % 2 != 0)//保证不越界但是先找奇数
		{
			left++;
		}
		while ((left < right) && (*right) % 2 == 0)//保证不越界但是先找到偶数
		{
			right--;
		}
		if (left < right)//将找到的奇数和偶数交换
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