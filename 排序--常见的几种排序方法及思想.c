//冒泡排序  一轮一轮来,每次比较相邻的两个，依次保证最后的是剩下的里面最大的
//插入排序  通过某种方法，依次将后面一个数据插到前面数据的某个位置，保证前面数据是有序的。
//选择排序  通过某种方法，从后面的数据中选择一个最大的数，和第一个数互换。再从后面的数据中，选择一个最大的数，与第二个数互换。
//快速排序
//归并排序  先两个两个排  再四个四个排  再八个八个排
#include<stdio.h>

//快速排序
void QuickSort(int* ,int ,int );
int FindPos(int* ,int ,int );

//冒泡排序
void MaoPaoSort(int *,int );

//插入排序
void InsertSort(int* ,int);

//选择排序
void SelectSort(int*,int);
int main(void)
{
	int a[6]  = {2,-6,0,7,3,4};
	int i = 0;
	//QuickSort(a,0,5);
	//MaoPaoSort(a,6);
	//InsertSort(a,6);
	SelectSort(a,6);

	for(i = 0;i < 6;i++)
		printf("%d ",a[i]);
	printf("\n");


	return 0;
}

void QuickSort(int* a,int low,int high)
{
	int pos;
	if(low < high)
	{
		//找到一个位置，左边的按同样的算法排，右边也按同样的算法排
		pos = FindPos(a,low,high);
		QuickSort(a,low,pos-1);
		QuickSort(a,pos+1,high);
	}
}
int FindPos(int* a,int low,int high)
{
	int val = a[low];
	while(low<high)
	{
		while(low < high && a[high] >= val)
			high--;
		a[low] = a[high];
		while(low < high && a[low] <= val)
			low++;
		a[high] = a[low];
	}
	//到这里，位置已经定了。
	a[low] = val;
	return low;
}


void MaoPaoSort(int* a,int len)
{
	int val;
	int i,j;
	for(i = len - 1;i > 0;--i)
	{
		for(j = 0;j < i;++j)
		{
			if(a[j] > a[j + 1])
			{
				val = a[j];
				a[j] = a[j + 1];
				a[j + 1] = val;
			}
		}
	}
}

void InsertSort(int* a,int len)
{
	int i,j,val;
	for(j = 1;j < len;j++)
	{
		for(i = 0;i < j;i++)
		{
			if(a[j] < a[i])
			{
				val = a[j];
				a[j] = a[i];
				a[i] = val;
			}
		}
	}
}

void SelectSort(int* a,int len)
{
	int i,j,index,val;
	for(i = 0;i < len-1;i++)
	{
		for(j = index = i;j < len-1;j++)
		{
			//找到剩下的里面最大(或最小)的数下标
			if(a[j+1] < a[index])
				index = j+1;
		}
		val = a[i];
		a[i] = a[index];
		a[index] = val;
	}
}
