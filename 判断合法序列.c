#include<stdio.h>
#include<string.h>
int IsLaw(char *);
int main(void)
{
	char ch[20];
	int flag = 0;
	
	while(1)
	{
		gets(ch);
		flag = IsLaw(ch);
		if(1 == flag)
			printf("合法！\n");
		else
			printf("不合法！\n");
	}
	
	return 0;
}

int IsLaw(char *ch)
{
	int len = strlen(ch);
	int l1 = 0,l2 = 0,i = 0;
	if(len %2 != 0)
		return 0;
	while(ch[i] != '\0')
	{
		if(ch[i] == 'I')
			++l1;
		else if(ch[i] == 'O')
		{
			if(l1<= l2)
				return 0;
			++l2;
		}
		else
			return 0;
		++i;
	}
	if(ch[i-1] != 'O' || l1 != l2)
		return 0;
	else
		return 1;
}