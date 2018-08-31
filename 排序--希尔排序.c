#include<stdio.h>
#define maxSize 8
void Sort(int *);
void Sort1(int *);
void Print(int * arr,char info[]);
int main(void)
{
	int num[maxSize] = {49,38,65,97,76,13,27,49};
	Print(num,"原数组为：");
	Sort1(num);
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
{
	int d;
	int i,j,temp;
	for(d = 5;d >= 1;d-=2)
	{
		for(i = d;i < maxSize;i+=d)
		{

			temp = a[i];
			for(j = i-d;j >= 0 && a[j] > temp;j-=d)
				a[j+d] = a[j];
			a[j+d] = temp;
		}
	}
}
void Sort1(int *a)
{
	int d;
	int i,j,temp;
	for(d = 5;d >= 1;d/=2)
	{
		for(i = d;i < maxSize;++i)
		{
			temp = a[i];
			for(j = i-d;j >= 0 && a[j] > temp;j-=d)
				a[j+d] = a[j];
			a[j+d] = temp;
		}
	}
}
