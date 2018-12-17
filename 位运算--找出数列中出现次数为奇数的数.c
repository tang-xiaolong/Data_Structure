//功能：有一个数列，其中的自然数都是出现偶数次，只有一个是出现奇数次，请找出这个数
//时间：2018年12月17日 19:57:18
//思路：同样的数异或结果为0  0与其他数异或就是那个数自己。且按位异或满足交换律和结合律，可以将所有的数异或，消除偶数个相同的数
#include<stdio.h>
int main(void)
{
	int num[] = {2,3,7,5,2,8,7,8,5,3,8};
	int result = 0;
	int i = 0;
	for(i = 0;i < sizeof(num)/sizeof(num[0]);++i)
		result = result ^ num[i];
	printf("%d\n",result);
	return 0;
}
