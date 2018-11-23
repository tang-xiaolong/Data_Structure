#include<stdio.h>
char *ui2hex(unsigned n,char *s);
int main(void)
{
	char s[12] = "\0";
	unsigned int num;
	scanf("%u",&num);
	ui2hex(num,s);
	puts(s);
	return 0;
}
char *ui2hex(unsigned n,char *s)
{
	unsigned int mask = 0xF<<28;//1111 0000 0000 0000
	unsigned temp;
	int flag = 0;
	char *p = s;
	char info[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	if(n == 0)//如果本来就是0，则直接把s设置为0并返回
	{
		s[0] = '0';
		s[1] = '\0';
		return s;
	}
	for(;mask;mask>>=4)//从左到右，每次读取四位，判断是否大于0
	{
		temp = mask&n;
		while(temp > 15)//去掉多余的0  如取到的是 1001 0000  则需要去掉后面这四个0
			temp>>=4;
		if(flag || temp)//如果已经是碰到一个非0了，那不管是什么都存进去
		{
			flag = 1;
			*p++ = info[temp];	
		}
	}
	*p = '\0';
	return s;
}
