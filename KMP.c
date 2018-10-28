#include<stdio.h>
#include<string.h>
int Calculate(char *target,char *match);
void GetNext(char *info,int *next);
int main(void)
{
	char target[100],match[20];
	int flag = -1;
	gets(target);
	gets(match);
	flag = Calculate(target,match);
	if(-1 == flag)
		printf("没有在目标串中找到该子串！\n");
	else
		printf("在目标串中找到了子串，位于%d的位置\n",flag);
	return 0;
}
int Calculate(char *target,char *match)
{
	int len1,len2;
	int i = 0,j = 0;
	int next[21];
	len1 = strlen(target);
	len2 = strlen(match);
	GetNext(match,next);
	while(i < len1 && j < len2)
	{
		//此处j的判断条件需要与求next数组初值相同
		if(j == -1 || target[i] == match[j])
		{
			++i;
			++j;
		}
		else
		{
			j = next[j];	
		}
	}
	if(j == len2)//到了末尾了出来的
		return i - len2;
	else
		return -1;
}
void GetNext(char *info,int *next)
{
	int i = 0,j = -1;//j的初值和next第一个值相同。i要比j大一，且必须给出next[i]的初值
	int len = strlen(info);
	next[0] = -1;
	while(i < len - 1)
	{
		if(j == -1 || info[j] == info[i])
		{
			++i;
			++j;
			//改进 //本来保存的是失配的时候应该滑到的位置，但是既然两者相等，滑到那个位置肯定也是错误的，所以直接滑到那个位置保存的位置
			if(info[i]==info[j])
				next[i] = next[j];
			else
				next[i] = j;
		}
		else
			j = next[j];
	}
	for(i = 0;i < len;++i)
		printf("%d",next[i]);
	putchar('\n');
}
