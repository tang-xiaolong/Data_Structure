#include<stdio.h>
#define maxSize 8
void Sort(int *a,int l,int r);
void Print(int * arr,char info[]);
int main(void)
{
	int num[maxSize] = {49,38,65,97,76,13,27,49};
	Print(num,"原数组为：");
	Sort(num,0,maxSize-1);
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


void Sort(int *a,int l,int r)
{
	int temp = a[l];
	int i,j;
	i = l,j = r;
	if(l >= r)
		return;
	while(i < j)
	{//非递减排序
		while(i < j && a[j] >= temp)
			--j;
		if(i < j)
		{
			a[i] = a[j];
			++i;
		}
		while(i < j && a[i] <= temp)
			++i;
		if(i < j)
		{
			a[j] = a[i];
			--j;
		}
	}
	a[i] = temp;
	Sort(a,l,i-1);
	Sort(a,i+1,r);
}