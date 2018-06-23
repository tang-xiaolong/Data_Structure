#include<stdio.h>
int Zong = 0;

void transport(int count,char start,char temp,char end)
{
	/*
	将start上的n个盘子借助temp移动到end上
	如果只剩下一个
		直接从start上移动到end上
	否则
		先将start上的n-1个盘子借助end移动到temp
		再将1个盘子直接从start移动到end
		最后将temp上的n-1个盘子借助start移动到end上
	*/
	if(1 == count)
	{
		Zong++;
		printf("将编号为%d的盘子从%c柱子移到%c柱子\n",count,start,end);
	}
	else
	{
		transport(count-1,start,end,temp);
		Zong++;
		printf("将编号为%d的盘子从%c柱子移到%c柱子\n",count,start,end);
		transport(count-1,temp,start,end);
	}
}
int main(void)
{
	char start = 'A';
	char temp = 'B';
	char end  = 'C';
	int count;
	printf("请输入汉诺塔的个数：");
	scanf("%d",&count);
	transport(count,start,temp,end);
	printf("总共移动了%d次\n",Zong);
	return 0;
}