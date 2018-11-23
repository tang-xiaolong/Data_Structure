//程序输入一个整数n（1<=n<=20），在0和1组成的长度为n的字符串中，输出不包含“101”子串的字符串个数
//例如：n = 4时，不包含“101”子串的字符串有12个：0000,0001,0010,0011,0100,0110,0111,1000,1001,1100,1110,1111 
//此时输出12
#include<stdio.h>
int Calculate(int n);
void Print(unsigned value,int n);
int main(void)
{
	printf("%d\n",Calculate(4));
	return 0;
}

int Calculate(int n)
{
	unsigned int mask = 7u;//7u对应的即0000 0111，正好取出一个数的最后三位
	int count = 0;
	unsigned int i = 0u,temp;
	int flag;
	for(i = 0;i < 1u<<n;++i)//i从0到(1>>n)-1   如n=4时   1<<4 = 0001 0000
	{
		//要判断i这个值是否符合条件
		flag = 0;
		for(temp = i;temp;temp>>=1)//如果没取到101就左移一位
		{
			if((temp&mask) == 5)//结果是101   5对应的是101，如果取出最后三位是101
			{
				//Print(i,n);
				flag = 1;
				break;
			}
		}
		if(!flag)//如果没有101
		{
			++count;
			//Print(i,n);
		}
	}
	return count;
}
void Print(unsigned int value,int n)
{
	//几位0
	unsigned int mask = 1u<<(n-1);
	for(;mask;mask>>=1)
		printf("%c",mask&value?'1':'0');
	putchar('\n');
}
