#include<stdio.h>
typedef char type;
int HuiWen(type *R,int l,int r);
int main(void)
{
	type num[] = "AABBCDEDCBBAA";
	int flag = 0;
	flag = HuiWen(num,0,sizeof(num)/sizeof(num[0])-2);//减去空字符  同时，下标要减1  所以是减2
	if(flag)
		puts("Yes");
	else
		puts("No");
	return 0;
}
int HuiWen(type *R,int l,int r)
{
	if(r <= l)//如果左右下标指向同一个或者是交错了，则表示为真
		return 1;
	return R[l] == R[r] && HuiWen(R,l+1,r-1);//当前两个位置相等，且切割后的部分也为1，则返回1.任意一个不满足返回0
}
