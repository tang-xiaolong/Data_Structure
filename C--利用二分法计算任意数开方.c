#include<stdio.h>
#define NUM 2	//要计算的数 
#define COUNT 2	//开几次方   这里就是根号2 
const double dot = 1e-10;
double Square(double x)
{
	double s = 1;
	int i;
	for(i = 0;i < COUNT;++i)
		s*=x;
	return s;
}
int main(void)
{
	double l = 0,r = NUM,m = (l+r)/2;//从0到本身找 
	while(r - l > dot)//如果左右区间长度大于精度，则继续循环 
	{
		m = (l+r)/2;
		if(Square(m) > NUM)// 当平方大于的时候，证明m大了 
			r =  m;
		else if(Square(m) < NUM)
			l = m;
		else
			break;
	}
	printf("%lf",m);
	return 0;
}
