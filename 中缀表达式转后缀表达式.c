#include<stdio.h>
int main(void)
{//9+(3-1)*3+8/2  
	char input[100] = {'\0'},c,temp;
	int i,top = -1;
	char stack[50] = {'\0'};
	scanf("%s",input);
	for(i = 0;(c = input[i]) != '\0';++i)
	{
		if(c>='0' && c<= '9' || (c >='a' && c <='z')||(c>='A' && c<= 'Z'))
			putchar(c);
		else
		{
			//判断当前符号与栈顶符号优先级，自己高
			if(c == '(')
			{
				stack[++top] = c;
			}
			else if(c == ')')
			{
				while((c = stack[top--])!='(')
					putchar(c);
			}
			else
			{
				//判断自己与栈顶符号优先级强弱，若自己不高于它，将它出栈输出将自己入栈
				if(top == -1)//如果是空栈，直接入栈
					stack[++top] = c;
				else 
				{
					while(1)
					{
						temp = stack[top];
						if(temp == '\0')
						{
							//(A+B)*D+E/(F+A*D)+C
							stack[++top] = c;
							break;
						}
						if((c == '*'||c == '/') && (temp == '+'|| temp == '-'))
						{
							stack[++top] = c;
							break;
						}
						else if(temp == '(')
						{
							stack[++top] = c;
							break;
						}
						else
						{
							temp = stack[top--];
							putchar(temp);
						}
					}
				}
			}
		}
	}
	while(top != -1)
		putchar(stack[top--]);
	putchar('\n');
	return 0;
}
