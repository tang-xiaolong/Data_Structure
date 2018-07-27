#include<stdio.h>
#define maxSize 50
int Test(char *);//实现一种括号的匹配
int main(void)
{
	int flag = -1;
	char info[maxSize];
	gets(info);
	flag = Test(info);
	if(flag == -1)
		puts("括号无法匹配");
	else
		puts("括号可以匹配");
	return 0;
}

int Test(char *s)
{
	int i = 0;
	int num = 0;//当出现左括号就++，出现右括号则--，中途小于0直接返回-1  遍历完如果不是0也返回-1
	while(s[i] != '\0')
	{
		if(s[i] == '(')
			++num;
		else if(s[i] == ')')
		{
			if(num == 0)
				return -1;
			else
				--num;	
		}
		++i;
	}
	if(num != 0)
		return -1;
	else
		return 1;
}