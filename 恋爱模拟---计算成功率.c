/*
在一款恋爱模拟游戏中，男主角进入了某个女主角的线路，现在遵循“与其约会，使其娇羞”的战略，共有9个约会场所提供使用。其中，有四个约会场景，较为浪漫，男主可以取得好感度+2或者好感度+0，五个约会场景较为普通，男主可以取得好感度+1或者好感度-1。在男主角使用所有约会场景之后，女主角好感度达到5及其以上，可以进入happy end，否则攻略失败，请输出男主能攻略成功女主的方法总数。 例如，在所有场景中均取得正向的好感度，那么总好感度为+13>=5，为其中一种攻略方案。
*/

#include<stdio.h>
#define M 4
#define N 5
int num[M+N] = {0};
int count =  0;
int Sum();
void Test(int i);
int main(void)
{
	Test(0);
	printf("%d\n",count);
	return 0;
}
int Sum()
{
	int s = 0,i = 0;
	for(i = 0;i < M+N;++i)
		s += num[i];
	return s;
}
void Test(int i)
{
	int s = 0;
	if(i == M+N)
	{//这里还可以改进，不是每次到最后计算sum 而是在每次调用前把自己加上，调用完回来再减去，会减少很多运算量
		s = Sum();
		if(s >= 5)
			++count;
		return;
	}
	if(i < M)
	{
		num[i] = 2;
		Test(i+1);
		num[i] = 0;
		Test(i+1);
	}
	else if(i < M+N)
	{
		num[i] = 1;
		Test(i+1);
		num[i] = -1;
		Test(i+1);
	}
}

