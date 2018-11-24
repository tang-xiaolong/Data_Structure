//矩阵相加
#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int Add(int **a,int **b,int **c);
void Print(int **a);
void Free(int **a);
int main(void)
{
	int **a,**b,**c;
	int i,j;
	a = (int **)malloc(sizeof(int *) * MAX);//首先a是一个指针，指向一个指针数组
	b = (int **)malloc(sizeof(int *) * MAX);
	c = (int **)malloc(sizeof(int *) * MAX);
	for(i = 0;i < MAX;++i)
	{
		a[i] = (int *)malloc(sizeof(int) * MAX);//a的第i行也是一个数组，不过这里是一个整型数组
		b[i] = (int *)malloc(sizeof(int) * MAX);
		c[i] = (int *)malloc(sizeof(int) * MAX);
		for(j = 0;j < MAX;++j)
		{
			a[i][j] = i*MAX + j + 1;
			b[i][j] = i*MAX + j + 1;
		}
	}
	printf("相加前：\n");
	Print(a);
	Print(b);

	Add(a,b,c);//矩阵相加
	printf("相加后：\n");
	Print(c);

	Free(a);//释放内存
	Free(b);
	Free(c);
	return 0;
}
int Add(int **a,int **b,int **c)
{
	int i,j;
	for(i = 0;i < MAX;++i)
		for(j = 0;j < MAX;++j)
			c[i][j] = a[i][j] + b[i][j];
	return 0;
}
void Print(int **a)
{
	int i,j;
	for(i = 0;i < MAX;++i)
	{
		for(j = 0;j < MAX;++j)
			printf("%3d",a[i][j]);
		putchar('\n');
	}
	putchar('\n');
}
void Free(int **a)
{
	int i;//释放内存时要注意，不能直接释放a，这样会导致内存泄漏，因为你只释放了a的那个数组，数组里面的每个元素也是一个整型数组，也需要释放。所以先释放里面的，再是外面的
	for(i = 0;i < MAX;++i)
		free(a[i]);
	free(a);
}
