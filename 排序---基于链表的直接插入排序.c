#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	int data;
	struct node *next;
}Node;
Node *Create(int R[],int n);
void InsertSort(Node *head);
void Treaver(Node *head);
int main(void)
{
	int num[] = {4,5,1,2,8,6,3,7};
	int count;
	Node *p = NULL;
	count = sizeof(num)/sizeof(num[0]);
	p = Create(num,count);
	Treaver(p);
	putchar('\n');
	InsertSort(p);
	Treaver(p);
	putchar('\n');
	return 0;
}
Node *Create(int R[],int n)
{
	int i;
	Node *head,*p,*q;
	head = (Node *)malloc(sizeof(Node));
	q = head;
	head->next = NULL;
	for(i = 0;i < n;++i)
	{
		p = (Node *)malloc(sizeof(Node));
		p->data = R[i];
		q->next = p;
		q = p;
	}
	q->next = NULL;
	return head;
}
void InsertSort(Node *head)
{
	Node *p,*q,*r;
	if(head->next != NULL)//保证有一个元素
	{
		p = head->next->next;//拿到第一个元素后面的部分
		head->next->next = NULL;//将链表从第一个节点那里切断
		while(p != NULL)
		{
			q = head;
			while(q->next != NULL && q->next->data < p->data)
				q = q->next;
			//找到了末尾或者是找到了一个比p节点大的
			r = p->next;
			p->next = q->next;
			q->next = p;
			p = r;
		}
	}
}
void Treaver(Node *head)
{
	Node *p = head->next;
	while(p != NULL)
	{
		printf("%2d",p->data);
		p = p->next;
	}
}
