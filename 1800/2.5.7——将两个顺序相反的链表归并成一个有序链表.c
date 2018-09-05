#include<stdio.h>
#include<malloc.h>
#define maxSize 5
typedef struct node
{
	int data;
	struct node *next;
}Node;
void Print(Node *N);
void Merge1(Node *N1,Node *N2);//将N2归并到N1中
void Merge2(Node *N1,Node *N2);
void Init(Node *N,int *num,int len);
int main(void)
{
	Node N1,N2;
	int num1[maxSize] = {2,5,6,7,15},num2[maxSize] = {32,29,24,12,4};
	Init(&N1,num1,maxSize);
	Init(&N2,num2,maxSize);
	Print(&N1);
	Print(&N2);
	Merge2(&N1,&N2);
	Print(&N1);
	Print(&N2);
	return 0;
}
void Merge1(Node *N1,Node *N2)
{
	//思路：还是用双指针，将N2的数依次插入到N1中。  最坏时间复杂度为 N*M
	Node *p = N2->next,*q = N1,*r = NULL,*l = NULL;
	while(p != NULL)
	{
		l = p->next;//取得N2的下一个节点
		q = N1;
		r = q->next;
		while(r != NULL && r->data < p->data)//N1的后指针不为空且r的值小于p的值  指针后移
		{
			q = r;
			r = r->next;
		}
		if(r == NULL)//到了N1末尾都是比p小，则插入到末尾
		{
			q->next = p;
			p->next = NULL;
		}
		else//中途找到比p的值大的节点了
		{
			q->next = p;
			p->next = r;
		}
		p = l;
	}
	N2->next = NULL;
}
void Merge2(Node *N1,Node *N2)
{
	//思路：先将N2逆序，然后把N2插入到N1中  不同于Merge1的是，这次插入是可以用到前面的位置信息的。最坏时间复杂度：2*M+N
	Node *p,*q,*r = NULL,*l = N1;
	p = N2->next;
	while(p)//逆序
	{
		q = p->next;//取得未逆序的第一个和第二个节点
		p->next = r;
		r = p;
		N2->next = r;
		p = q;
	}

	//插入
	p = N2->next;
	if(p== NULL)
		return;
	while(p)
	{
		r = p->next;
		q = l->next;//取得N1中开始搜索的位置
		while(q != NULL && q->data < p->data)
		{
			l = l->next;
			q = q->next;
		}
		if(q != NULL)//此时在N1中间找到了合适位置
		{
			l->next = p;
			p->next = q;
			l = l->next;//仅需把下一次开始搜索位置后移一个就行了，避免重复搜索
		}
		else
		{
			//需要插入到最后
			l->next = p;
			p->next = NULL;
			l = l->next;
		}
		//l = p;  //此句可代替前面两个条件语句中的l = l->next;
		p = r;
	}
	N2->next = NULL;//将N2置空
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
