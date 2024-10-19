//https://leetcode.cn/problems/kth-missing-positive-number/description/

#include<stdio.h>
#include<stdlib.h>
#include"singlyLinkedList.h"

int findKthPositive(int* arr, int arrSize, int k) 
{
	int arri = 0;
	int num = 1;
	int th = 0;
	int target= arr[arrSize - 1];
	while (arri < arrSize&&th!=k)
	{
		if (arr[arri] == num)
		{
			num++;
			arri++;
		}
		else
		{
			th++;
			target = num;
			num++;
		}
	}
	if (th < k)
	{
		return  target = arr[arrSize - 1] + (k - th);
	}

	return target ;
}
//int main()
//{
//	int* t = malloc(sizeof(int) * 5);
//	t[0] = 5;
//	t[1] = 6;
//	t[2] = 7;
//	t[3] = 8;
//	t[4] = 9;
//	printf("%d", findKthPositive(t, 5, 9));
//	free(t);
//}
//执行用时分布
//0
//ms
//击败
//100.00 %
//复杂度分析
//消耗内存分布
//8.19
//MB
//击败
//66.24 %
