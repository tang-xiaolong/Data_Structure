//功能：倒推法求解物体数目  
//时间：2018年12月4日 21:25:59
#include<stdio.h>
long int Solve(int n,long int a);
int main(void)
{
	long int a,sum = 0;
	int n;
	n = 3;
	a = 2;
	//scanf("%d%ld",&n,&a);
	sum = Solve(n,a);
	printf("%ld\n",sum);
	return 0;
}
long int Solve(int n,long int a)
{
	if(n == 1)//已经计算到第n天了，那一天是a件物体
		return a;
	else
		return (Solve(n-1,a) + 1) * 2;//本来后一天是等于前一天的一半再减1，那这里就反过来：把后一天的加1再乘2，就是前一天的，当求解到第n层的时候就有结果了
}
