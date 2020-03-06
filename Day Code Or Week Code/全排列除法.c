/*
Time Limit: 3000ms ，Memory Limit: 10000KB，Accepted: 5030 ，Total Submissions: 9489

Description
输入正整数n，按从小到大的顺序输出所有形如abcde/fghij=n的表达式，其中a~ j恰好为数字0 ~ 9的一个排列， 2≤n<=79。

Input
输入正整数n

Output
输出形如abcde/fghij=n的表达式，每行一个

Sample Input
62
Sample Output
79546/01283=62
94736/01528=62
*/
/*
思路：
全排列的时间复杂度太高，所以得在中间剪枝。
我们可以由n得到最小的那个abcde，即最大的fghij，我们按照数学里的叫法，把它们叫做被除数和除数。
全排列的经典解法就是让首位分别与后面数字交换，并均递归求解后面的那些排列。
可以发现，当我们递归到某个位置时，再对子问题去执行排列操作已经没有意义了
在n固定的前提下，除数越大则被除数越大，我们可以找到最小的5位除数，从而得到最小的可能被除数(不一定满足数字唯一)去做剪枝
若得到的最小可能被除数位数大于5则找不到。否则在查找过程中，若刚好在第五位的时候，就判断一下后面五位是否有机会排列得到结果
*/
#include<stdio.h>
#include<time.h>
#define N 11
#define LENGTH 5
//函数声明
int GetNumLength(int num);
void TreaverStr(char *str, int l, int r, int preNum, int n, int *numArray, int *len);
int GetNumForStr(char *str, int l, int r);
void SwapChar(char *str, int l, int r);
int IsValid(int bigNum, int smallNum, int n);


int main(void)
{
	int n, preNum = 0, len = 0, tempNum = 0;
	int numArray[30] = { 0 };
	char info[N] = "9876543210";
	clock_t start, stop;
	scanf("%d", &n);
	start = clock();
	//已知 五位数/五位数=n
	//用最小的五位数乘以n，得到最大可能的被除数，通过这个去剪枝
	preNum = 1234 * n;
	if (GetNumLength(preNum) > LENGTH)//Error
		return -1;
	TreaverStr(info, 0, N - 2, preNum, n, numArray, &len);

	//sort
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			if (numArray[i] > numArray[j])
			{
				tempNum = numArray[i];
				numArray[i] = numArray[j];
				numArray[j] = tempNum;
			}
		}
	}
	for (int i = 0; i < len; i++)
	{
		printf("%d/%d=%d\n", numArray[i] * n, numArray[i], n);
	}
	stop = clock();
	printf("用时：%lf\n", (double)(stop - start) / CLK_TCK);
	getchar();
	getchar();
	getchar();
	return 0;
}

void TreaverStr(char *str, int l, int r, int preNum, int n, int *numArray, int *len)
{
	int flag = 1, pN = 0, lN = 0;
	if (l >= r)//结束
	{
		pN = GetNumForStr(str, 0, LENGTH - 1);
		lN = GetNumForStr(str, LENGTH, r);
		//判断是否是需要的数
		if (!IsValid(pN, lN, n))
			return;
		numArray[*len] = lN;
		*len = *len + 1;
		return;
		/*for (int i = 0; i <= r; i++)
		{
			if (i == LENGTH)
				putchar('/');
			putchar(str[i]);
		}
		printf("=%d\n",n);*/
	}
	for (int i = l; i <= r; i++)
	{
		flag = 1;
		SwapChar(str, l, i);
		//判断是否需要继续算下去
		//刚好达到前缀项那么长，看是否可以剪枝，不行的话后面五位就不用算了
		if (i == LENGTH - 1 && GetNumForStr(str, 0, i) < preNum)
			flag = 0;
		if (1 == flag)
			TreaverStr(str, l + 1, r, preNum, n, numArray, len);
		SwapChar(str, l, i);//换回来
	}

}

int IsValid(int bigNum, int smallNum, int n)
{
	return smallNum * n == bigNum ? 1 : 0;
}
void SwapChar(char *str, int l, int r)
{
	char ch = str[l];
	str[l] = str[r];
	str[r] = ch;
}
int GetNumForStr(char *str, int l, int r)
{
	int num = 0;
	while (l <= r)
		num = num * 10 + str[l++] - '0';
	return num;
}

//获取num的长度
int GetNumLength(int num)
{
	int len = 1;
	if (num < 0)
		return num *= -1;
	while ((num /= 10))
	{
		++len;
	}
	return len;
}
