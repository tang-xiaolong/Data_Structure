//求解一元一次方程
//输入一个式子：只含数字、小写字母、+、-、=，输出结果   
//如输入6a-5+1 = 2-2a  输出a = 0.750
#include<stdio.h>
void Resort(char *equation);
int main(void)
{
	char info[20];
	scanf("%s",info);
	Resort(info);
	return 0;
}

void Resort(char *equation)
{
	char x,c;
	double factor = 0;//自变量前的总系数
	int num = 0;//保存当前的数字结果
	int flag = 1,sum = 0;//标记是+还是-
	int isLeft = 1;//标记是左边还是右边
	while((c = *equation++) != '\0')
	{
		flag = 1;
		if(c == '-')//和后面的数字一起处理
		{
			flag = -1;
			c = *equation++;
		}
		else if(c == '+')
		{
			flag = 1;
			c = *equation++;
		}
		if(c >= '0' && c <= '9')//如果是数字，一直读，读到符号为止
		{
			num = c-'0';
			while(c = *equation)//继续读，直到读到符号
			{
				if(c >= '0' && c <= '9')
				{
					num = num * 10 + c - '0';
					equation++;
				}
				else
					break;
			}
			num *=(flag*isLeft);//加上符号位
			if(c >= 'a' && c <= 'z')//找到自变量
			{
				factor += num;//保存系数
				x = c;
			}
			else
				sum+=num;//存入计算结果
		}
		if(c == '=')//等式一边已经计算完啦,修改标记
			isLeft = -1;
	}
	printf("%c=%.3lf\n",x,(-1.0)*sum/factor);//把所有数字和移到右边要变号，然后除以自变量前的系数
}
