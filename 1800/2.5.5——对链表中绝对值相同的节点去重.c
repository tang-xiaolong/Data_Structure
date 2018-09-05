#include<stdio.h>
#include<malloc.h>
#define maxSize 5
typedef struct node
{
	int data;
	struct node *next;
}Node;
void RemoveRepeat(Node * N);
void Print(Node *N);
void Init(Node *N,int *num,int len);
int main(void)
{
	Node N;
	int num[maxSize] = {21,-15,-15,-7,15};
	Init(&N,num,maxSize);
	Print(&N);
	RemoveRepeat(&N);
	Print(&N);
	return 0;
}
void RemoveRepeat(Node * N)
{
	//用双指针
	Node *p,*q,*r;
	q = N->next;
	while(q != NULL)
	{
		r = q;
		p = q->next;
		while(p != NULL)
		{
			if(p->data == q->data || p->data == -1*q->data)//若这个节点绝对值和q的相同，删除这个节点
			{
				r->next = p->next;
				free(p);
				p = r->next;
			}
			else//否则，双指针分别后移
			{
				r = r->next;
				p = p->next;
			}
		}
		q = q->next;
	}
}
void Print(Node *N)
{
	Node *p = N->next;
	while(p)
	{
		printf("%4d ",p->data);
		p = p->next;
	}
	putchar('\n');
}
void Init(Node *N,int *num,int len)
{
	Node *p = N,*q;
	int i;
	for(i = 0;i < len;++i)
	{
		q = (Node*)malloc(sizeof(Node));
		q->data =  num[i];
		p->next = q;
		p = q;
	}
	p->next = NULL;
}
