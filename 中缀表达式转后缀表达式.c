#include<stdio.h>
#include<struct.h>
int main(void)
{//9+(3-1)*3+8/2  
	char input[100] = {'\0'},c,temp;
	int i;
	PCS p = InitC();
	scanf("%s",input);
	for(i = 0;(c = input[i]) != '\0';++i)
	{
		if(c>='0' && c<= '9')
			putchar(c);
		else
		{
			//判断当前符号与栈顶符号优先级，自己高
			if(c == '(')
				PushC(p,c);
			else if(c == ')')
			{
				while((c = PopC(p))!='(')
					putchar(c);
			}
			else
			{
				//判断自己与栈顶符号优先级强弱，若自己不高于它，将它出栈输出将自己入栈
				if(EmptyC(p))//如果是空栈，直接入栈
					PushC(p,c);
				else 
				{
					temp = GetC(p);
					if((c == '*'||c == '/') && (temp == '+'|| temp == '-'))
						PushC(p,c);
					else if(temp == '(')
						PushC(p,c);
					else
					{
						temp = PopC(p);
						putchar(temp);
						PushC(p,c);
					}
				}
			}
		}
	}
	while((c = PopC(p)) != '\0')
		putchar(c);
	putchar('\n');
	return 0;
}