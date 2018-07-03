#include<stdio.h>
#define N 8
#define Inf -32768
int Num[N] = { 1, -2, 3, 10, -4, 7, 2, -5};
//int Num[N] = {-1,-1,-1,-1,-1,-1,-1,-1};
void Print(int *a,int bIndex,int eIndex,char *p);//打印函数，参数分别为：要打印的数组首地址，开始下标，结束下标，提示语
void Baoli(int *a);//暴力穷举法  时间复杂度为n^2
int FenZhi(int *a,int begin,int end);//分治法  
int FenXi(int *a);//分析法  p[i] = a[0]+a[1]+a[2]+...+a[i]  s[i,j] = p[j]-p[i-1]  先将p[i]全部计算出来。找到最大的那个，减去最小的那个就是结果
int DongTaiGuiHua(int *a);//动态规划法  s[i]表示以a[i]结尾的数组中和最大的一个   s[0] = a[0]  s[i+1] = max(s[i],a[i+1])


int main(void)
{
	int i =  0;
	Print(Num,0,N-1,"原数组为：");
	Baoli(Num);
	printf("分治法求得最大子列和为：%d\n\n",FenZhi(Num,0,N-1));
	FenXi(Num);
	DongTaiGuiHua(Num);
	return 0;
}
void Print(int *a,int bIndex,int eIndex,char *p)
{
	printf("%s",p);
	for(;bIndex <= eIndex;bIndex++)
		printf("%3d ",*(a+bIndex));
	printf("\n");
}
void Baoli(int *a)
{
	int i,j,len = N;
	int begin=0,end=0,nowValue = 0,maxValue = Inf;
	for(i = 0;i < len;i++)
	{
		nowValue = 0;
		for(j = i;j < len;j++)
		{
			nowValue += *(a+j);
			if(nowValue >= maxValue)
			{
				maxValue = nowValue;
				begin = i;
				end = j;
			}
		}
	}
	Print(a,begin,end,"暴力穷举法计算得到的最大子列为");
	printf("最大子列和为：%d\n\n",maxValue);
}

int FenZhi(int *a,int begin,int end)
{
	//将区间分成两段，分别计算左边的最大和、右边的最大和以及跨越区间的最大和
	int middle = (begin+end)/2;
	int leftValue,rightValue,kuaValue=0,maxLeft=Inf,maxRight=Inf;
	int i;
	if(begin == end)
		return *(a+begin);
	leftValue = FenZhi(a,begin,middle);
	rightValue = FenZhi(a,middle+1,end);
	//计算跨越的值时，从中间向两边计算。
	for(i = middle;i>=begin;i--)
	{
		kuaValue+=*(a+i);
		if(kuaValue >= maxLeft)
		{
			maxLeft = kuaValue;
		}
	}
	kuaValue = 0;
	for(i = middle+1;i <= end;i++)
	{
		kuaValue+=a[i];
		if(kuaValue >= maxRight)
		{
			maxRight = kuaValue;
		}
	}
	kuaValue = maxLeft+maxRight;
	//返回leftValue、rightValue、kuaValue中较大的一个
	return leftValue>rightValue?(leftValue>kuaValue?leftValue:kuaValue):(rightValue>kuaValue?rightValue:kuaValue);
}
int FenXi(int *a)
{
	int p[N],len = N;
	int i,minValue = 0,maxValue = Inf,temp;
	int leftIndex=0,rightIndex = 0;
	p[0] = a[0];
	for(i = 1;i < len;i++)//计算p[i]
		p[i] = p[i-1]+a[i];
	//循环遍历，时时更新最小值，同时，计算减去的最大值
	for(i = 0;i < len;i++)
	{
		if(p[i] < minValue)
		{
			minValue = p[i];
			leftIndex = i+1;
		}
		temp = p[i] - minValue;
		if(temp > maxValue)
		{
			maxValue = temp;
			rightIndex = i;
		}
	}
	Print(a,leftIndex,rightIndex,"分析法计算得到的最大子列为");
	printf("最大子列和为：%d\n\n",maxValue);
}
int DongTaiGuiHua(int *a)
{
	int s[N];
	int i,maxValue=a[0],leftIndex=0,rightIndex=0,flag = 0;
	s[0] = a[0];
	for(i = 1;i < N;i++)
	{
		flag = 0;
		if(s[i-1]+a[i] >= a[i])
		{
			s[i] = s[i-1]+a[i];
		}
		else
		{
			flag = 1;//证明这个s[i]是需要重置左右下标的
			s[i] = a[i];
		}
		if(s[i] > maxValue)
		{
			maxValue = s[i];
			if(1 == flag)
				leftIndex = i;
			rightIndex = i;//只要当前比最大的大，右下标是肯定需要重置的。
		}
	}
	Print(a,leftIndex,rightIndex,"动态规划法计算得到的最大子列为");
	printf("最大子列和为：%d\n\n",maxValue);
}