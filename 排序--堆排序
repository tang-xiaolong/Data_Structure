#include<stdio.h>
#define maxSize 9
int count = 0;
void HeapSort(int *,int );
void HeapAdjest(int *,int ,int );
void Print(int * arr,char info[]);
int main(void)
{
	int num[maxSize] = {-1,49,38,65,97,76,13,27,49};
	Print(num,"原数组为：");
	HeapSort(num,maxSize);
	Print(num,"排序后为：");
	return 0;
}

void Print(int *arr,char info[])
{
	int i;
	printf("%s",info);
	for(i = 1;i < maxSize;++i)
		printf("%3d",arr[i]);
	putchar('\n');
}
void HeapSort(int *a,int n)
{
	int i,temp;
	//构建大顶堆
	for(i = n/2;i > 0;--i)
	{
		HeapAdjest(a,i,n);//传入参数：数组  要调整的双亲节点  节点总数
	}

	//有了大顶堆之后，将完全二叉树根节点与最后 一个未排元素互换，并重新调整大顶堆
	for(i = n;i > 1;--i)
	{
		temp = a[1];
		a[1] = a[i];
		a[i] = temp;//换位置
		HeapAdjest(a,1,i-1);//需要调整的是1号位置的节点   还剩下i-1个节点
	}
	printf("共比较了%d次!\n",count);
}

void HeapAdjest(int *a,int s,int n)
{
	int i,temp;
	temp = a[s];//保存需要调整的节点
	//找到它应该在的位置
	for(i = 2*s; i <= n;i*=2)
	{
		++count;
		//看左右节点哪个更大，就与哪个交换
		if(i < n && a[i] < a[i+1])//右孩子更大，把下标更新成大的那个
			++i;
		//如果当前较大的一个都比temp要小  那就直接退出去
		if(a[i] < temp)
			break;
		else
		{
			//否则，将较大的那个放到上面来，并确定temp的真正位置  如果调整完后temp还是比子节点小  则继续调整
			a[s] = a[i];//把大的节点放上来
			s = i;//把下标往大的那个节点移  并继续判断
		}
	}
	a[s] = temp;
}
