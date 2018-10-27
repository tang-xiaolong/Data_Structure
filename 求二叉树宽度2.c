#include<stdio.h>
#include<malloc.h>
#define MaxSize 20
typedef struct node
{
	int data;
	struct node *lc;
	struct node *rc;
}Node;


//前序创建二叉树
Node *PreCreate(Node *p);
void PreTreaver(Node *p);
void Visit(Node *t);
int GetWeigth(Node *p);

int main(void)
{
	Node tree;
	//freopen("Input.txt","r",stdin);
	//freopen("Output.txt","w",stdout);
	PreCreate(&tree);
	PreTreaver(&tree);
	printf("\n");
	printf("宽度为：%d\n",GetWeigth(&tree));
	return 0;
}
void Visit(Node *t)
{
	printf("%3d",t->data);
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
int GetWeigth(Node *p)
{
	Node *que[MaxSize];
	Node *t,*end,*preEnd;
	int front,rear;
	int max,count;
	front = rear = max = count = 0;
	preEnd = p;
	que[rear] = p;
	rear = (rear + 1) % MaxSize;
	while(rear != front)
	{
		t = que[front];
		front = (front + 1) % MaxSize;
		++count;
		if(t->lc)
		{
			end = t->lc;
			que[rear] = t->lc;
			rear = (rear + 1) % MaxSize;
		}
		if(t->rc)
		{
			end = t->rc;
			que[rear] = t->rc;
			rear = (rear + 1) % MaxSize;
		}
		if(t == preEnd)
		{
			preEnd = end;
			if(count > max)
				max = count;
			count = 0;
		}
	}
	return max;
}
void PreTreaver(Node *p)
{
	if(p)
	{
		Visit(p);
		if(p->lc)
			PreTreaver(p->lc);
		if(p->rc)
			PreTreaver(p->rc);
	}
}

/*
思路：借助层次遍历，在上一层结束时确定这一层最后一个节点，并把计数器置零。当出来新节点的时候判断是否为最后的节点，如果是，根据情况更新（或不更新）当前最大宽度，并把下一层的准备工作完成。
样例：
1 2 4 32767 32767 32767 3 5 32767 32767 32767 
*/
