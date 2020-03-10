/*
2020年3月10日 23:09:11
给出一个序列，只交换相邻两数，使得序列变得有序，求出最少交换次数。
实际上是求逆序数，因为只要有序即可，所以统计逆序数的时候反向统计一遍反逆序的数，最后选较小的一个
*/
#include<stdio.h>
int numArray[101];//存放数字
int main(void)
{
	int n, i = 0, j = 0;
	int largeSum = 0, smallSum = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &numArray[i]);
	}
	//统计逆序数和反逆序数，选较小的一个
	for (i = 0; i < n - 1; ++i)
	{//依次判断numArray[i] 与 numArray[j] 的大小，并统计逆序次数和反逆序次数
		for (j = i + 1; j < n; ++j)
		{
			if (numArray[j] > numArray[i])
				++largeSum;
			else if (numArray[j] < numArray[i])
				++smallSum;
		}
	}
	printf("%d", largeSum < smallSum ? largeSum : smallSum);
	getchar();
	getchar();
	return 0;
}
