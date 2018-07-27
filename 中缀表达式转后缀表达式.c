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
		if(c>='0' && c<= '9' || (c >='a' && c <='z')||(c>='A' && c<= 'Z'))
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
					while(1)
					{
						temp = GetC(p);
						if(temp == '\0')
						{
							//(A+B)*D+E/(F+A*D)+C
							PushC(p,c);
							break;
						}
						if((c == '*'||c == '/') && (temp == '+'|| temp == '-'))
						{
							PushC(p,c);
							break;
						}
						else if(temp == '(')
						{
							PushC(p,c);
							break;
						}
						else
						{//若是和里面的优先级一样，让栈里面的出来，同时，自己需要继续喝里面的进行比较看是否可以进栈
							temp = PopC(p);
							putchar(temp);
						}
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
