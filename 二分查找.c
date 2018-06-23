#include<stdio.h>
#define N 14

int ErFenFind(int *,int);

int main(void)
{
	int a[N];
	int val,i,pos;
	srand((unsigned)time(NULL));

	//随机生成第一个数据，后面的随机在前一个数的基础上加一点点。这样就可以任意修改数组的长度
	a[0] = rand()%(2*N);
	printf("数据为：%d ",a[0]);
	for( i = 1;i < N;i++)
	{
		a[i] = a[i-1]+rand()%(N)+1;
		printf("%d ",a[i]);
	}
	putchar('\n');
	printf("请输入你要查找的数：");
	scanf("%d",&val);
	pos = ErFenFind(a,val);
	if(-1 != pos)
	{
		printf("您要查找的%d位于原数组的第%d个位置上。\n",val,pos);
	}
	else
		printf("您要查找的数据不存在。\n");
}
int ErFenFind(int *a,int val)
{
	int left = 0,right = N-1,middle;
	while(left <= right)
	{
		middle = (left+right)/2;
		if(a[middle] < val)
		{
			left = middle + 1;
		}
		else if(a[middle] > val)
		{
			right = middle - 1;
		}
		else
			return middle+1;
	}
	return -1;
}
