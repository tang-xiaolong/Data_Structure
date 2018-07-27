#include<stdio.h>
#define maxSize 50
void Test(char *);
int main(void)
{
	char info[maxSize+1];
	gets(info);
	printf("原字符串为：%s\n",info);
	Test(info);
	printf("新字符串为：%s\n",info);
	return 0;
}
void Test(char *s)
{
	int i = 0,k = 0;
	while(s[i]!='\0')
	{
		if(s[i] == ' ')
		{
			++k;//统计空格个数
		}
		++i;
	}
	while(i > 0 || k == 0)//已经不存在需要替换的空格或者已经替换到开始位置  注：其实只要判断k即可，只是习惯性判断数组是否到头
	{
		if(s[i] != ' ')
		{//从后往前扫描，将各个字符放到正确的位置（包括'\0'）
			s[i+k*2] = s[i];
		}
		else
		{//如果是空格了，将对应的三个位置填上值，同时k--
			s[i+k*2] = '0';
			s[i+k*2-1] = '2';
			s[i+k*2-2] = '%';
			--k;
		}
		--i;
	}
}