//功能：位运算--实现算数运算加减乘除
//时间：2018年12月19日 20:06:34
//思路：各种运算都是基于加法来的
#include<stdio.h>
int Plus(int a,int b);
int Subtraction(int a,int b);
int Multiply(int a,int b);
int Devide(int a,int b);
int isLow(int value);//是否是负数
int main(void)
{
	int a,b,result = 0;
	char c;
	int (*p)(int,int);
	printf("请输入表达式，中间不要用空格，如1+2：");
	scanf("%d%c%d",&a,&c,&b);
	switch(c)
	{
	case '+':
		p = Plus;
		break;
	case '-':
		p = Subtraction;
		break;
	case '*':
		p = Multiply;
		break;
	case '/':
		p = Devide;
		break;
	}
	result = p(a,b);
	printf("%d %c %d = %d\n",a,c,b,result);
	return 0;
}

int Plus(int a,int b)
{
	//先把两个数异或保存起来，这是得到无进位的加法，然后再判断是否有进位（把原来两个数做按位&，如果不为0则有进位），如果没有，结束；如果有，把进位的结果左移一位并与无进位的结果做异或；直到没有进位为止
	int c,d;
	while(1)
	{
		c = a ^ b;
		d = a & b;
		if(d == 0)//无进位了，返回c
			break;
		//有进位
		a = c;//把最新的结果异或起来，
		b = d<<1;
	}
	return c;
}
int Subtraction(int a,int b)
{
	return Plus(a,b);
}
int Multiply(int a,int b)
{
	//乘法也是借助加法，比如-3 * -5，先把后面的负号提取出来，然后
	int flag = 1,i,c = a;
	if(a == 0 || b == 0)
		return 0;
	else if(isLow(b))
	//else if(b < 0)
	{
		flag = -1;
		//b = b * -1;//保证b是正数
		b = ~(b-1);
	}
	for(i = 1;i < b;++i)//乘以b  只需要加b-1次
	{
		c = Plus(a,c);
	}
	return flag == 1?c:~(c-1);
	//return c * flag;
}
int Devide(int a,int b)
{
	//不断得减，直到无法再减
	int flag = 1,i = 0,c = a;
	if(a == 0 || b == 0)
		return 0;
	else if(isLow(b))
//	else if(b < 0)
	{
		flag = -1;
		//b = b * -1;//保证b是正数
		b = ~(b-1);
	}
	while(!isLow(c-b))//如果大于等于0，则要继续
	{
		++i;
		c-=b;
	}
	return flag == 1?i:~(i-1);
	//return i*flag;
}
int isLow(int value)//是否是负数
{
	if(value ^ ((~1u<<1>>1)^(~1u)))//判断符号位是0还是1
		return 1;
	return 0;
}
