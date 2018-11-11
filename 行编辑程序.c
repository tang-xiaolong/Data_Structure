/*
//K&R书中的行编辑程序
一个简单的行编辑程序的功能是：接受用户从终端输入的程序或数据，并存入用户的数据区。由于用户在终端上进行输入时，
不能保证不出差错，因此，若在行编辑程序中“每接受一个字符即存入用户区”的做法显然是不恰当的。
较好的做法是，设立一个输入缓冲区，用以接收用户输入的一行字符，然后逐行存入用户数据区。允许用户输入出差错，
并在发现有误时及时改正。
例如：当用户发现刚刚建入的一个字符是错的时，可补进一个退格符“#”，以表示前一个字符无效；如果发现当前键入的行内
差错较多或难以补救，则可以输入一个退格符“@”，以表示当前行中的字符均无效。
*/
#include<stdio.h>
#include<malloc.h>
int main(void)
{
	char stack1[50] = {'\0'};
	char stack2[50] = {'\0'};
	int top1 = -1,top2 = -1;
	char c;
	while((c = getchar()))
	{
		switch(c)
		{
		
		case '#':--top1;break;
		case '@':top1 = -1;break;
		case '~':
		case '\n':
			{
				if(c != '~')
					stack1[++top1] = c;
				while(top1 != -1)
					stack2[++top2] = stack1[top1--];
				while(top2 != -1)
					putchar(stack2[top2--]);
			}
			break;
		default:stack1[++top1] = c;
		}
		if(c == '~')
			break;
	}
	putchar('\n');
	return 0;
}
