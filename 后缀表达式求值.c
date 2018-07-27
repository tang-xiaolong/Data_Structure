#include<stdio.h>
#include<Struct.h>
int op(int a,char Op,int b);
int com(char exp[]);
int main(void)
{
	int result = 0;
	char shizi[20];
	scanf("%s",shizi);
	result = com(shizi);
	printf("结果为：%d\n",result);
	return 0;
}
int op(int a,char Op,int b)
{
	if(Op == '+')
		return a+b;
	else if(Op == '-')
		return a-b;
	else if(Op == '*')
		return a*b;
	else
	{
		if(b != 0)
			return a/b;
		else
			return -1;
	}
			
}
int com(char exp[])
{
	int i,a,b,result;
	PIS myS = InitI();
	char Op;

	for(i = 0;exp[i] != '\0';++i)
	{
		if(exp[i] >= '0' && exp[i] <= '9')//当前是数字
		{
			PushI(myS,exp[i]-'0');
		}
		else
		{
			Op = exp[i];
			b = PopI(myS);
			a = PopI(myS);
			result = op(a,Op,b);
			PushI(myS,result);
		}
	}
	return PopI(myS);
}