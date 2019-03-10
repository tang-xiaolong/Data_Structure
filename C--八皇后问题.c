#include<stdio.h>
#include<math.h> 
#define N 8
 
void resort(int index);
int count = 0;
int map[N],table[N] = {0};
int main(void)
{
	//freopen("out.txt","w",stdout);
	resort(0);	
	printf("共%d种\n",count); 
	return 0;
}
void resort(int index)
{
	if(index == N)
	{
		//检查这种放置方案是否可行。map[i]中放置了它的位置，我们验证这些两两之间是否会在一个斜线上 
		for(int i = 0;i < N;++i)
		{
			for(int j = i+1;j < N;++j)
			{
				if(abs(i-j) == abs(map[i] - map[j]))
				{
					return ;//不可行 
				}
			}
		}
		++count;
//		printf("  "); 
//		for(int i = 0;i < N;++i)
//			printf("%2d",i+1);
//		putchar('\n');
//		for(int i = 0;i < N;++i)
//		{
//			//输出N行，每一行输出map[i]-1个空格，再输出一个方形，再输出8-map[i]个空格与一个回车
//			int j;
//			printf("%-2d",i+1);
//			for(j = 0;j < map[i]-1;++j)
//				printf("  ");
//			printf("■");
//			for(j = 0;j < N - map[i];++j)
//				printf("  ");
//			putchar('\n');		
//		}
//		putchar('\n');
		return ;
	}
	for(int i = 0;i < N;++i)
	{
		if(table[i] == 0)
		{
			table[i] = 1;
			map[index] = i+1; 
			resort(index+1);//处理index+1个位置的数 
			table[i] = 0;
		}
	}
		
} 
