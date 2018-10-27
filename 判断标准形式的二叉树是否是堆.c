#include<stdio.h>
#include<malloc.h>
//如果判断小顶堆，把递归函数中的 BIG 换成 SMALL
#define BIG >=
#define SMALL <=
typedef struct node
{
	int data;
	struct node *lc;
	struct node *rc;
}Node;

Node *PreCreate(Node *p);
int estimate_stack(Node *t,int *n);
#include<stdio.h>
int main(void)
{
	Node tree;
	int n = 0;
	//freopen("Input.txt","r",stdin);
	PreCreate(&tree);//按照先序输入一棵树，值为32767表示这个节点是空节点
	if(estimate_stack(&tree,&n))
		printf("这是一个堆！节点个数为：%d\n",n);
	else
		printf("这不是一个堆！节点个数为：%d\n",n);
	return 0;
}

int estimate_stack(Node *t,int *n)
{
	int a = 1,b = 1;//标志位
	int n1 = 0,n2 = 0;
	if(t)
	{
		if(t->lc)//如果存在左子树，先判断值是否满足条件，如果满足再递归判断左子树是否满足条件。将最终的结果&&起来
			a = (t->data BIG t->lc->data) && estimate_stack(t->lc,&n1);
		if(t->rc && a)//如果左子树已经不满足了，不用继续递归右子树了
			b = (t->data BIG t->rc->data) && estimate_stack(t->rc,&n2);
		if(n1 < n2)//如果左子树个数比右子树个数少，则不是
			a = b = 0;
		*n = n1 + n2 + 1;//左右子树加1为自己当前的节点个数
	}
	else
		*n = 0;
	return a && b;//如果为空，则表示这个节点满足定义
}
Node *PreCreate(Node *p)
{
	int value = 32767;
	scanf("%d",&value);
	if(value != 32767)
	{
		p->data = value;
		p->lc = PreCreate((Node *)malloc(sizeof(Node)));
		p->rc = PreCreate((Node *)malloc(sizeof(Node)));
	}
	else
		free(p),p = NULL;
	return p;
}
/*
输入样例1：
45 32 17 20 32767 32767 10 32767 32767 14 11 32767 32767 12 32767 32767 32767
输入样例2：
45 32 17 14 32767 32767 10 32767 32767 20 11 32767 32767 12 32767 32767 32767
输入样例3：
45 32 32767 32767 20 12 32767 32767 14 32767 32767
*/
