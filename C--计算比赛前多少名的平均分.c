//功能：有8位选手，20位评委给他们打分。最终评分按照平均分来评比（去掉最高分去掉最低分），输出前三名选手的编号以及对应的平均分
//时间：2018年12月10日 15:11:37
//思路：当得到分数后，依次求取选手的平均分。并与前三的平均分做比较，及时更新排名和分数即可
/*
示例输入：
10 7 7 8 6 9 10 4 7 8 10 9 7 8 9 5 6 7 9 10
10 7 7 8 6 9 10 4 7 8 10 9 7 8 9 5 5 8 6 9
10 7 7 8 6 9 10 4 7 8 10 9 7 6 5 6 7 8 4 9
10 7 7 8 6 9 10 4 7 8 10 9 7 8 9 4 6 8 5 3
10 7 7 8 6 9 10 4 7 8 10 9 7 8 9 5 7 8 8 8
10 7 7 8 6 9 10 4 7 8 10 9 7 8 9 5 7 7 7 7
10 7 7 8 6 9 10 4 7 8 10 9 7 8 9 9 9 8 7 6
10 7 7 8 6 9 10 4 7 8 10 9 7 8 9 8 2 4 5 6


输出：
第1名编号为：  7，平均分为：8.000000
第2名编号为：  1，平均分为：7.888889
第3名编号为：  5，平均分为：7.833333
*/
#include<stdio.h>
#include<malloc.h>
#define PEOPLE 8
#define JUDGES 20
#define COUNT 3
void Calculate(void);
void Free(int **a);
int main(void)
{
	Calculate();
	return 0;
}
void Calculate()
{
	int i,j,k;
	float ave[COUNT];//保存前COUNT个选手分数和id
	int id[COUNT];
	int **score;
	int sum,max,min;
	float item,temp;
	int tempId,itemId;
	for(i = 0;i < COUNT;++i)
	{
		ave[i] = -1;
		id[i] = -1;
	}
	score = (int **)malloc(sizeof(int *) * PEOPLE);
	for(i = 0;i < PEOPLE;++i)
	{
		score[i] = (int *)malloc(sizeof(int) * JUDGES);
		for(j = 0;j < JUDGES;++j)
		{
			scanf("%d",&score[i][j]);//读入分数
		}
	}
	for(i = 0;i < PEOPLE;++i)
	{
		sum = 0;
		max = -1;
		min = 32767;
		for(j = 0;j < JUDGES;++j)
		{
			sum += score[i][j];
			if(score[i][j] > max)//记录最大值最小值
				max = score[i][j];
			if(score[i][j] < min)
				min = score[i][j];
		}
		temp = (sum-max-min)*1.0f/(JUDGES-2);//计算平均分
		tempId = i+1;
		for(k = 0;k < COUNT;++k)
		{
			if(ave[k] == -1)//本来这个位置还没人
			{
				ave[k] = temp;
				id[k] = tempId;
				break;
			}
			else if(temp > ave[k])//比这个位置上的人分数要高，那不好意思，您请挪挪
			{
				item = ave[k];//先把那个位置的信息保存
				itemId = id[k];
				ave[k] = temp;
				id[k] = tempId;
				temp = item;
				tempId = itemId;
			}
		}
	}
	for(i = 0;i < COUNT;++i)
	{
		printf("第%d名编号为：%3d，平均分为：%f\n",i+1,id[i],ave[i]);
	}
	Free(score);
}
void Free(int **a)
{
	int i;
	for(i = 0;i < PEOPLE;++i)
		free(a[i]);
	free(a);
}
