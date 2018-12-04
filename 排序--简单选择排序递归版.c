//功能：选择排序递归版  
//时间：2018年12月4日 21:13:02
#include<stdio.h>
void SelectSort(int *array,int n);
void print(int *array,int n,char *info);
int main(void)
{
	int num[] = {3,5,8,1,2,4,6,7};
	print(num,sizeof(num)/sizeof(num[0]),"未排序：");
	SelectSort(num,sizeof(num)/sizeof(num[0]));
	print(num,sizeof(num)/sizeof(num[0]),"排序后：");
	return 0;
}
void SelectSort(int *array,int n)
{
	int i,j,temp;
	if(n == 1)
		return ;
	j = 0;
	for(i = 0;i < n;++i)
		if(array[i] < array[j])
			j = i;
	temp = array[0];//这个array并不总是原来数组的第一个，而是未排序的部分第一个
	array[0] = array[j];
	array[j] = temp;
	SelectSort(array+1,n-1);
}
void print(int *array,int n,char *info)
{
	int i = 0;
	printf("%s",info);
	for(i = 0;i < n;++i)
		printf("%3d",array[i]);
	putchar('\n');
}
