/*
矩阵a（有h行和w列）的元素只有0和1，函数maxBlock返回矩阵中包含连续1的块大小的最大值
函数原型 int maxBlock(int **a,int h,int w);
所谓连续指两个值为1的元素出现在相邻的同一行或相邻的同一列当中。
例如：h = 5,w = 10，a的元素值如下：
0 0 1 0 0 0 0 0 1 1
0 1 1 0 0 1 1 1 1 1
0 1 0 0 0 1 0 0 0 0
0 0 1 1 1 1 0 1 1 1
0 0 1 1 1 1 0 1 1 1
连续1的块有3块，大小分别为4,16,6，最大值是16，输出16
*/

/*
示范输入：
5 10
0 0 1 0 0 0 0 0 1 1
0 1 1 0 0 1 1 1 1 1
0 1 0 0 0 1 0 0 0 0
0 0 1 1 1 1 0 1 1 1
0 0 1 1 1 1 0 1 1 1
*/

#include<stdio.h>
#include<stdlib.h>
//全局变量区
int flag[100][100];
int dir[4][2] = 
{
	{1,0},
	{-1,0},
	{0,1},
	{0,-1}
};

int maxBlock(int **a,int h,int w);
int DFS(int **a,int i,int j,int h,int w);//使用DFS遍历计算连续1
int InArea(int m,int n,int h,int w);//判断是否在有效范围
int main(void)
{
	int h,w;
	int i,j,max = -1;
	int **a;
	scanf("%d%d",&h,&w);
	a = (int **)malloc(sizeof(int *)*h);
	for(i = 0;i < h;++i)
	{
		a[i] = (int *)malloc(sizeof(int) * w);
		for(j = 0;j < w;++j)
		{
			scanf("%d",*(a+i)+j);
		}
	}
	for(i = 0;i < h;++i)
	{
		for(j = 0;j < w;++j)
		{
			printf("%2d",*(*(a+i)+j));
		}
		putchar('\n');
	}
	max = maxBlock(a,h,w);
	printf("%d\n",max);
	//释放内存空间
	for(i = 0;i < h;++i)
		free(a[i]);
	free(a);
	return 0;
}
int InArea(int m,int n,int h,int w)
{
	if(m >=0 && m < h && n >= 0 && n <w)
		return 1;
	return 0;
}
int DFS(int **a,int m,int n,int h,int w)
{
	int count = 0,i;
	if(a[m][n] == 0 || !InArea(m,n,h,w))//如果这个元素是0或者不在范围内
		return 0;
	//对四周进行遍历
	//证明当前位置是1，那就遍历四周，把和加起来
	flag[m][n] = 1;
	++count;//自己是1，所以加1
	for(i = 0;i < 4;++i)
	{
		if(InArea(m+dir[i][0],n+dir[i][1],h,w) && flag[m+dir[i][0]][n+dir[i][1]] == 0)//如果在区域内，且自己的flag为0，则继续遍历
		{
			count += DFS(a,m+dir[i][0],n+dir[i][1],h,w);
		}
	}
	return count;
}
int maxBlock(int **a,int h,int w)
{
	int max = -1,i = 0,j = 0,temp;
	for(i = 0;i < h;++i)
	{
		for(j = 0;j < w;++j)
		{
			if(flag[i][j] == 0)//这个元素还没有被查找过，查找过的可以直接跳过啦，提高效率
			{
				temp = DFS(a,i,j,h,w);
				if(temp > max)
					max = temp;
			}
		}
	}
	return max;
}
