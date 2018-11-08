#include<stdio.h>
#define maxSize 8
void Insert(int *);
void Print(int * arr,char info[]);
int main(void)
{
	int num[maxSize] = {49,38,65,97,76,13,27,49};
	Print(num,"原数组为：");
	Insert(num);
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

void Insert(int *arr)
{
	int i,j,temp;
	for(i = 1;i < maxSize;++i)
	{
		temp = arr[i];
		for(j = i-1;j >= 0 && arr[j] > temp;--j)
		{
			arr[j+1] = arr[j];
		}
		arr[j+1] = temp;
	}
}
