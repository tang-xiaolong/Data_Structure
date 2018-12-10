//功能：1 + 2*3 + 4*5*6 + 7*8*9*10 + ...   输入n，输出前n项的和
//时间：2018年12月10日 15:03:11
//思路：多项累加累乘，递归可以做，但是容易溢出，这里采取就地解决：用一个变量记录当前要加的这一小块是几项相乘，用一个变量记录当前这一小块第一个元素是多少
//      某一小块第一个，其实可以通过等差数列求和公式算出。这里直接采取用前一次的加上这一小块的长度
//		当得知了某一小块的长度（也就是第几项了：几项相乘），且知道了这一小块的第一个或者是最后一个，就可以很容易求出这一小块的值了。最后，每一小块计算完后累加上去即可
#include<stdio.h>
long int Calculate(int n);
int main(void)
{
	long int sum = 0;
	int n;
	scanf("%d",&n);
	sum = Calculate(n);
	printf("sum = %ld\n",sum);
	return 0;
}
long int Calculate(int n)
{
	long int sum = 0;
	long int temp = 1;
	int i,j;
	int pre = 1;
	for(i = 1;i < n + 1;++i)
	{
		temp = 1;
		for(j = 0;j < i;++j)
			temp *= (pre+j);
		sum+=temp;
		pre+=i;
	}
	return sum;
}
