//输入1：23 45 31 26 29 27 32767
//输入2：23 45 31 26 25 27 32767
#include<stdio.h>
#define INF 32767
int low = -INF,mid = -INF,high = INF;
int IsFindList(int R[],int n);
int main(void)
{
	int num[50];
	int count = 0,i = 0,result = 0;
	while(scanf("%d",&num[i]) >= 1 && num[i] != 32767)
		++i,++count;
	result = IsFindList(num,count);
	if(result)
		printf("Yes!\n");
	else
		printf("No!\n");
	return 0;
}
int IsFindList(int R[],int n)
{
	int i = 0;
	int result = 1;//默认为1，表示True
	mid = R[0];
	for(i = 1;i < n;++i)
	{
		if(R[i] == mid || R[i] <= low || R[i] >= high)//如果等于上一次的划分点，或者落在了边界外，返回false
		{
			result = 0;
			break;
		}
		if(R[i] > mid)
		{
			//在右边
			low = mid;
			mid = R[i];
		}
		else
		{
			high = mid;
			mid = R[i];
		}
	}
	return result;
}
