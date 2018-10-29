#include<stdio.h>
typedef struct node
{
	int data;
	struct node *lc;
	struct node *rc;
}Node;
void Transform(int *pre,int l1,int r1,int *las,int l2,int r2);
int main(void)
{
	int begin = 0,end = 6;
	int Pre[] = {12,9,7,11,35,21,54};
	int Las[7] = {0};
	int i;
	for(i = 0;i < end+1;++i)
		printf("%3d",Pre[i]);
	putchar('\n');
	Transform(Pre,begin,end,Las,begin,end);
	for(i = 0;i < end+1;++i)
		printf("%3d",Las[i]);
	putchar('\n');
	return 0;
}
void Transform(int *pre,int l1,int r1,int *las,int l2,int r2)
{
	if(l1 <= r1)
	{
		las[r2] = pre[l1];
		Transform(pre,l1+1,(l1+r1+1)/2,las,l2,(r2+l2-1)/2);//左半边树   先把前序中的左子树切割出来，再把对应的后序的位置切割出来
		Transform(pre,(l1+r1+1)/2+1,r1,las,(r2+l2-1)/2+1,r2-1);
	}
}
