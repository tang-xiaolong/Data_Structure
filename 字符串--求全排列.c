#include<stdio.h>
#include<string.h>
void swap(char *a,char *b);
void f(char *a,int begin,int end);
int main(void)
{
	char a[10] = "XYZ";
	f(a,0,strlen(a)-1);
	return 0;
}

void swap(char *a,char *b)
{
	char t = *a;
	*a = *b;
	*b = t;
}
void f(char *a,int begin,int end)
{
	int i;
	if(begin == end)
		printf("%s\n",a);
	else
		for(i = begin;i <= end;++i)
		{
			swap(&a[begin],&a[i]);
			f(a,begin+1,end);
			swap(&a[begin],&a[i]);
		}
}
