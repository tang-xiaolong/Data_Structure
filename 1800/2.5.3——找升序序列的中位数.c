#include<stdio.h>
#define maxSize 5
int FindMid(int *S1,int *S2);
int main(void)
{
	int S1[5] = {11,13,15,17,19},S2[5]  = {2,4,6,8,20};
	int result = -1;
	result = FindMid(S1,S2);
	printf("中位数为：%d\n",result);
	return 0;
}
int FindMid(int *S1,int *S2)
{
	int i,j,k,l,flag;
	i = j = l = 0;
	k = maxSize;
	while(i < maxSize-1 && j < maxSize-1)
	{
		flag = 0;
		if(S1[i] < S2[j])
			++i,flag = 1;
		else
			++j,flag = 2;
		++l;
		if(l == k)
			if(flag == 1)
				return S1[--i];
			else
				return S2[--j];
	}
	while(i < maxSize-1)
	{
		++l;
		if(l == k)
			return S1[i];
		++i;
	}
	while(j < maxSize-1)
	{
		++l;
		if(l == k)
			return S2[j];
		++j;
	}
	return -1;
}
