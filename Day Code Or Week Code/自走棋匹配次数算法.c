/*
G社的同学们最近都沉迷于一种叫做自走棋的游戏。这是一种对战游戏，人数相同的玩家组成两队进行对战。但是它的对战模式十分独特，游戏中的每一轮，玩家将随机匹配到其他玩家的镜像进行战斗，而且不会有玩家在同一轮被镜像两次。这种独特的匹配模式引起了GGer的兴趣，GGer想知道对于给定的玩家人数，到底有多少种不同的匹配方式。
	输入描述
一个整数N(N<=100)，表示给定的玩家数量。
	输出描述
一个整数，表示可能的匹配种数
	示例：
输入
3
输出
2
说明
3名玩家A, B, C可能有(A, B), (B, C), (C, A)和(A, C), (B, A),  (C, B)两种匹配； (A, A) (B, C) (C, B)为非法匹配，自己不能匹配自己; (A, B), (B, C), (C, B)为非法匹配，B匹配了两次
*/
/* 思路
使用动态规划。
公式有两个
kp[n] = (n - 1) * dp[n - 2]
dp[n] = kp[n] + n * dp[n - 1]

前一个就是n个均未匹配时的组合个数  例如求ABCDE的匹配种数。即求kp[5]
后一个是除掉连续匹配部分后剩余n个的组合个数  例如A->B->C DEF 即在A匹配B的镜像，B匹配C的镜像的情况下，求剩下的匹配种数  即求dp[3](非连续部分有3个)
第一个 假设有n个人，把一个拿出来（假如叫X），剩下的有n - 1个可以放在X后面被X攻击，所以有n - 1种选择；当选择了一个人Y后，情况就变成了X->Y A...D，即dp[n - 1] 综合起来就是(n - 1)*dp[n - 1]
第二个 有两种情况，第一种：如果连续部分自己组合起来(A->B B->C C->D D->A E...F)(后面未连续部分有n个)，那剩下的n个就变成了kp[n]
				   第二种：如果连续部分再从后面选一个继续组成连续部分，有n种选法。选完后情况就变成了dp[n-1]的情况了。故 kp[n] + n * dp[n - 1]
*/
#include<stdio.h>
long long MatchNum(int n);
int main(void)
{
	long long res = 0;
	int n = 0;
	long long temp = 1;
	scanf("%d",&n);
	res = MatchNum(n);
	printf("%lld\n", res);
	getchar();
	getchar();
	return 0;
}
long long MatchNum(int n)
{//滚动数组，使用index记录两个数组当前算到第几个了 
	long long dp = 1,dpIndex = 1;//dp始终保存dp数组中下标为dpIndex的数  dp[n] = kp[n] + n * dp[n - 1]
	long long kp[2] = { 1,2 }, kpIndex = 3;//第二个是n等于3的值  kp[1]始终保存着kp数组中下标为kpIndex的数 
	long long tempNum = 0;
	if (n < 2)
		return 0;
	else if (n == 2)
		return 1;
	//要算的是kp[kpIndex + 1]的值,需要dp[kpIndex - 1]的值 故判断dpIndex是否等于kpIndex-1
	while (dpIndex < kpIndex - 2)//若小于则往后算，此时dpIndex + 1 == 2 即kpIndex - 1
	{
		//dp[dpIndex + 1] = kp[dpIndex + 1] + (dpIndex + 1) * dp[dpIndex]
		dp = kp[kpIndex - dpIndex - 2] + (dpIndex + 1) * dp;//计算下标为dpIndex + 1 的值
		dpIndex += 1;
	}
	while (kpIndex < n)//此时dpIndex == kpIndex - 2了，同步往后算，直到kpIndex算到n
	{//算kp后一项之前得把dp往后算一项
		dp = kp[kpIndex - dpIndex - 2] + (dpIndex + 1) * dp;//此时保存的是dp[dpIndex]的值,即dp[kpIndex -2]
		dpIndex += 1;
		//kp[n] = (n-1) * dp[n - 2]
		tempNum = kp[0];//kp[kpIndex - 1]
		kp[0] = kp[1];// kp[kpIndex];
		kp[1] = (kpIndex * dp);//求kp[kpIndex + 1]
		kpIndex += 1;
	}
	return kp[1];
}
