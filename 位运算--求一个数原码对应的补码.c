//功能：求一个数原码对应的补码
//时间：2018年12月19日 19:11:37
//思路：为了程序正常运行，先写一个函数求得数的原码。     求补码的时候，如果符号位是1，则为负数，把它按位取反加1，并将符号位修改回1；如果符号位是0，直接返回即可，因为正数的原码补码反码均相同
//示例输入：-9
/*
示例输出
-9的补码为：11111111111111111111111111110111
-9的原码为：10000000000000000000000000001001
其补码对应的无符号数为：4294967287
*/
//把输出的294967287 输入到计算器中可以得到，其二进制就是上面的补码

#include<stdio.h>
int GetPre(int value);//输入一个数，返回它的原码对应的数
unsigned int getbits(unsigned int value);//获取补码
void Print(int value);//输出一个数的二进制位
int main(void)
{
	int a,b;
	printf("请输入a的值：");
	scanf("%d",&a);
	printf("%d的补码为：",a);
	Print(a);
	b = GetPre(a);
	//printf("%d\n",b);
	printf("%d的原码为：",a);
	Print(b);
	printf("其补码对应的无符号数为：%u\n",getbits((unsigned)b));
	return 0;
}
int GetPre(int value)//输入一个数，返回它的原码对应的数
{
	unsigned int mask = ((~1u<<1)>>1)^(~1u);
	if(value & mask)//是负数，为了得到原码，-1再取反，且符号位还是要置为0
	{
		value-=1;
		value = ~value;
		value = value | mask;
	}
	return value;
}
unsigned int getbits(unsigned int value)
{
	unsigned int z;
	z = value&(1<<sizeof(unsigned int)*8-1);
	if(z)//如果不为零，则是负数，取反加1，并把符号位换回来
	{
		z = ~value + 1;
		z = z|(1<<sizeof(unsigned int)*8-1);//把对应符号位改回来
	}
	else
		z = value;
	return z;
}
void Print(int value)//输出一个数的二进制位
{
	unsigned int mask = 1u<<sizeof(int)*8-1;//使得其不依赖于平台
	for(;mask;mask>>=1)
	{
		value&mask?putchar('1'):putchar('0');
	}
	putchar('\n');
}
