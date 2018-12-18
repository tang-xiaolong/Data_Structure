//功能：树--根据给定的满二叉树序列构建二叉树
//时间：2018年12月18日 19:11:26
//思路：因为是满二叉树，所以可以通过数组下标找到对应的孩子或者是找到父亲。构建一个临时数组保存创建的节点，然后再根据规律连接上即可
#include<stdio.h>
#include<malloc.h>
#define MAX 100
typedef struct BT
{
	char data;
	struct BT *lc;
	struct BT *rc;
}BT;
BT *Create(char A[],int n);
void Las(BT* bt);
int main(void)
{
	char info[] = "ABCDEFG";
	BT *bt;
	bt = Create(info,sizeof(info)/sizeof(info[0])-1);
	Las(bt);
	putchar('\n');
	return 0;
}
BT *Create(char A[],int n)
{
	BT *S[MAX],*p;
	int i;
	for(i = 0;i < n;++i)
	{
		p = (BT *)malloc(sizeof(BT));
		p->data = A[i];
		p->lc = p->rc = NULL;
		S[i] = p;
	}
	for(i = 0;2 * i + 1 < n;++i)
	{
		S[i]->lc = S[2 * i + 1];
		if(2 * (i + 1) < n)
			S[i]->rc = S[2 * (i + 1)];
	}
	return S[0];
}
void Las(BT* bt)
{
	//后续遍历这个树
	BT *Sta[MAX];
	int flag[MAX] = {0};
	int top = -1;
	while(top != -1 || bt != NULL)
	{
		while(bt)
		{
			//自己入栈，对应位置设为0。一路向左
			Sta[++top] = bt;
			flag[top] = 0;
			bt = bt->lc;
		}
		if(top != -1)
		{
			bt = Sta[top];//查看最上面那一个的标志
			if(flag[top] == 0)//还没有遍历右孩子，去右孩子吧
			{
				flag[top] = 1;
				bt = bt->rc;
			}
			else
			{
				//如果不是0，则说明已经遍历完右孩子了
				--top;
				putchar(bt->data);
				bt = NULL;
			}
		}
	}
}
