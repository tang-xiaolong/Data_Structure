#include<stdio.h>
#define maxSize 8
void MergeSort(int *,int ,int );
void Merge(int *,int ,int ,int );
void Print(int * arr,char info[]);
int main(void)
{
	int num[maxSize] = {49,38,65,97,76,13,27,49};
	Print(num,"原数组为：");
	MergeSort(num,0,maxSize-1);
	Print(num,"排序后为：");
	return 0;
}

void Print(int *arr,char info[])
{
	int i;
	printf("%s",info);
	for(i = 0;i < maxSize;++i)
		printf("%3d",arr[i]);
	putchar('\n');
}
void MergeSort(int *a,int low,int high)
{
	int mid;
	if(low < high)
	{
		mid = (high+low)/2;
		MergeSort(a,low,mid);
		MergeSort(a,mid+1,high);
		Merge(a,low,mid,high);
	}
}
void Merge(int * a,int low,int mid,int high)
{
	//把a数组中low到mid   与mid+1到high合并到一起
	int i,j,k;
	int temp[maxSize];
	i = low;
	k = 0;
	j = mid+1;
	while(i <= mid && j <= high)
	{
		//只要任意一个到了边界，都退出去
		if(a[i] < a[j])//要小的
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}//若哪边还有剩余，则加进去
	while(i <= mid)
		temp[k++] = a[i++];
	while(j <= high)
		temp[k++] = a[j++];
	for(i = high;i >= low;--i)//逆序把值放回a数组
		a[i] = temp[--k];
}
