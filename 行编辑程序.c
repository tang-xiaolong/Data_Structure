#include<stdio.h>
#include<malloc.h>
#include<struct.h>
int main(void)
{
	PCS p = InitC();
	PCS n = InitC();
	char c;
	while((c = getchar())!='~')
	{
		switch(c)
		{
		case '#':PopC(p);break;
		case '@':ClearC(p);break;
		case '\n':
			{
				PushC(p,c);
				while((c = PopC(p)) != '\0')
					PushC(n,c);
				while((c = PopC(n)) != '\0')
					putchar(c);
			}
			break;
		default:PushC(p,c);
		}
	}
	return 0;
}