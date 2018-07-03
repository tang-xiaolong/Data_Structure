//假定一个排序数组以某个未知元素为支点做了旋转，如：原数组0 1 2 4 5 6 7旋转后得到 4 5 6 7 0 1 2。
//请找出旋转后数组的最小值。 假定数组中没有重复数字
#include<stdio.h>
#define N 8

int Num[N] = {0,1,2,3,4,5,6,7};
void XuanZhuan(int a[]);//旋转方法
void Print(int *a,char *p);//打印方法
int FindMin(int *a);

int main(void)
{
	int num=0;
	srand((unsigned)time(NULL));
	Print(Num,"未旋转之前数组为：");
	XuanZhuan(Num);
	Print(Num,"旋转之后的数组为：");
	num = FindMin(Num);
	printf("最小值为：%d\n",num);
	return 0;
}
void Print(int *a,char *p)
{
	int i;
	printf("%s",p);
	for(i = 0;i < N;i++)
		printf("%3d ",a[i]);
	printf("\n");
}
void XuanZhuan(int a[])
{
	int index = rand()%N;
	int i,j=0,b[N];
	for(i = 0;i <= index;i++)
		b[j++] = a[i];
	j =  0;
	for(i = 0;i < N;i++)
		if(i < N-index-1)
			a[i] = a[i+index+1];
		else
			a[i] = b[j++];
}

int FindMin(int *a)
{
	int left = 0,right = N-1,middle;
	while(left < right)
	{
		middle = (left+right)/2;
		if(a[middle] > a[right])
		{
			left = middle+1;
		}
		else
		{
			right = middle;
		}
	}
	return a[left];
}
