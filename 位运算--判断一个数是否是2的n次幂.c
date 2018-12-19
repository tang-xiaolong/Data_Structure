//功能：判断一个数是否是2的n次幂
//时间：2018年12月19日 19:49:11
//思路：因为2的n次幂的数结构一定是高位一个1，低位全是0  比如10  100  1000  只要减一，每一位的数字都会改变，与原来的数&一次即可
#include<stdio.h>
int isPow(unsigned int value);
int main(void)
{
	unsigned int num;
	int flag = 0;
	scanf("%u",&num);
	flag = isPow(num);
	if(flag)
		puts("True");
	else
		puts("False");
	return 0;
}
int isPow(unsigned int value)
{
	int flag = 0;
	if(value != 1 && !(value&(value-1)))//如果是1，减1后成为0，与原来的数按位&结果为0，但是这不对
		flag = 1;
	return flag;
}
