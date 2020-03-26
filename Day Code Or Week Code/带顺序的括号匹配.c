/*
字符串中只含有括号 (),[],<>,{},判断输入的字符串中括号是否匹配。如果括号有互相包含的形式，从内到外必须是<>,(),[],{}，例如。输入: [()] 输出:YES，而输入([])，([)]都应该输出NO。

格式
输入格式
第一行为一个整数n，表示以下有多少个由括好组成的字符串。接下来的n行，每行都是一个由括号组成的长度不超过255的字符串。
输出格式
在输出文件中有n行，每行都是YES或NO。
样例
输入样例
5
{}{}<><>()()[][]
{{}}{{}}<<>><<>>(())(())[[]][[]]
{{}}{{}}<<>><<>>(())(())[[]][[]]
{<>}{[]}<<<>><<>>>((<>))(())[[(<>)]][[]]
><}{{[]}<<<>><<>>>((<>))(())[[(<>)]][[]]
输出样例
YES
YES
YES
YES
NO
*/


#include<stdio.h>
#define YES printf("YES\n")
#define NO printf("NO\n")
int GetIndex(char c);
void ClearFlagArray(int *array, int n);

int main(void)
{
	char info[257],*p,stack[257];
	int num[4] = { 0 };//保存左括号的次数
	int n, top = -1,tempIndex = 0,flag = -1,haveMatch = 1;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
	{
		//每次输入新的前先置0
		scanf("%s",info);
		p = info;
		top = -1;
		haveMatch = 1;
		ClearFlagArray(num, 4);
		while (*p != '\0')
		{
			//判断是左括号或者是右括号
			tempIndex = GetIndex(*p);
			flag = 1;
			if (tempIndex == 0)//无关字符
			{
				haveMatch = 0;
				break;
			}
			else if (tempIndex > 0)//这是左括号，判断在前面的是否为0，如果不为0那就不合格
			{
				for (int j = 0; j < tempIndex - 1; ++j)
				{
					if (num[j] != 0)
					{
						flag = 0;
						break;
					}
				}
				if (flag == 1)//可以放
				{
					stack[++top] = *p;
					num[tempIndex - 1]++;//左括号计数
				}
			}
			else//右括号，则需要抵消一个左括号
			{
				if (top != -1 && GetIndex(stack[top]) == tempIndex * -1)//栈不为空，且里面和自己正好匹配
				{
					//对应的
					num[-1 * tempIndex - 1]--;//取消一个左括号的计数
					--top;
				}
				else
					flag = 0;
			}
			if (flag == 0)
			{
				haveMatch = 0;
				break;
			}
			p++;
		}
		if (haveMatch != 0)
			YES;
		else
			NO;
	}
	getchar();
	getchar();
	return 0;
}
int GetIndex(char c)
{
	char str1[] = "<([{";
	char str2[] = ">)]}";
	for (int i = 0; i < 4; ++i)
		if (str1[i] == c)
			return i + 1;
	for (int i = 0; i < 4; ++i)
		if (str2[i] == c)
			return -(i + 1);
	return 0;
}
void ClearFlagArray(int *array, int n)
{
	for (int i = 0; i < n; ++i)
		array[i] = 0;
}
