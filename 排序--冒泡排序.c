#include<stdio.h>
#define maxSize 8
void Sort(int *);
void Print(int * arr,char info[]);
int main(void)
{
	int num[maxSize] = {49,38,65,97,76,13,27,49};
	Print(num,"原数组为：");
	Sort(num);
	Print(num,"排序后为：");
	return 0;
}

void Print(int *arr,char info[])
{
	int i;
	printf("%s",info);
	for(i = 0;i < maxSize;++i)
		printf("%3d",arr[i]);
	putchar('\n');
}

void Sort(int *a)
{//两两相邻比较
	int i,j,temp,flag = 0;
	for(i = 0;i < maxSize-1;++i)
	{
		flag = 0;
		for(j = maxSize-1;j > i;--j)
		{
			//非递减  则把大的放后面去   故每次选取一个最大的放最后面    如果每次选取最小的放前面，可能会导致一个本来较小的数放到很后面
			if(a[j] < a[j-1])
			{
				temp = a[j-1];
				a[j-1] = a[j];
				a[j] = temp;
				flag = 1;
			}
		}
		if(flag == 0)
			break;
	}
}