#include<stdio.h>
int op(int a,char Op,int b);
int com(char exp[]);

//931-3*+82/+
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
	int stack[50],top = -1;
	char Op;

	for(i = 0;exp[i] != '\0';++i)
	{
		if(exp[i] >= '0' && exp[i] <= '9')//当前是数字，压栈
		{
			stack[++top] = exp[i]-'0';
		}
		else//碰到符号，则弹出两个数运算，算完再将结果入栈
		{
			Op = exp[i];
			b = stack[top--];
			a = stack[top--];
			result = op(a,Op,b);
			stack[++top] = result;
		}
	}
	return stack[top--];
}
