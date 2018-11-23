//矩阵转置
/*
输入示例：
3
1 2 3
4 5 6
7 8 9
*/
#include<stdio.h>
#include<stdlib.h>

void matrixInvert(int **a,int n);//转置函数
void Print(int **a,int n);//打印
void Free(int **a,int n);//释放动态内存
int main(void)
{
	int i,j,n;
	int **a;
	scanf("%d",&n);
	a = (int **)malloc(sizeof(int *)*n);
	for(i = 0;i < n;++i)
	{
		a[i] = (int *)malloc(sizeof(int)*n);
		for(j = 0;j < n;++j)
		{
			scanf("%d",*(a+i)+j);
		}
	}
	puts("转置前：");
	Print(a,n);
	matrixInvert(a,n);
	puts("\n转置后：");
	Print(a,n);
	Free(a,n);
	return 0;
}
void matrixInvert(int **a,int n)
{
	int i,j;
	int temp;
	for(i = 0;i < n;++i)
		for(j = 0;j < i;++j)//j只能到一半，因为如果到n，又会换回来  这里到i实际上就是到对角线，也就是一半
		{
			temp = a[i][j];
			a[i][j] = a[j][i];
			a[j][i] = temp;
		}
}
void Free(int **a,int n)
{
	int i = 0;
	for(i = 0;i < n;++i)
		free(a[i]);
	free(a);
}
void Print(int **a,int n)
{
	int i,j;
	for(i = 0;i < n;++i)
	{
		for(j = 0;j < n;++j)
		{
			printf("%3d",a[i][j]);
		}
		putchar('\n');
	}
}
