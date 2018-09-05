//求A、B两递增集合的交集  结果保存在A集合中
#include<stdio.h>
#include<malloc.h>
#define maxSize 5
typedef struct node
{
	int data;
	struct node *next;
}Node;
void Print(Node *N);
void FindSame(Node *N1,Node *N2);
void Init(Node *N,int *num,int len);
int main(void)
{
	Node N1,N2;
	int num1[maxSize] = {2,5,6,7,15},num2[maxSize] = {3,5,8,15,17};
	Init(&N1,num1,maxSize);
	Init(&N2,num2,maxSize);
	Print(&N1);
	Print(&N2);
	FindSame(&N1,&N2);
	Print(&N1);
	Print(&N2);
	return 0;
}void FindSame(Node *N1,Node *N2)
{
	//思路：依次扫描N2，若比当前N1指向的那个元素大，则表示N1这个元素不是它们的交集，记录并删除当前节点  如果小，N2继续往后扫描，如果为NULL则结束，并释放N1指向的节点及后面的所有节点。因为这意味着中途没找到和N1指向的那个元素相同的元素，且这些元素都比N1指向的那个节点值小
	Node *p = N1->next,*q = N2->next,*r = N1;//r用于指向p的前面，便于删除节点
	if(q == NULL || p == NULL)
		N1->next = NULL;//没有交集
	while(q != NULL && p != NULL)
	{
		//N1没结束且N2没结束  一个结束了，那就没必要继续找了
		while(q != NULL && q->data < p->data)
			q = q->next;
		if(q == NULL)
		{
			break;
		}
		if(q->data > p->data)
		{
			//p不是公共的部分，删除p节点
			r->next = p->next;
			free(p);
			p = r->next;
		}
		else
		{
			//相等了，则保存
			r = p;
			p = p->next;
			q = q->next;
		}
	}
	p = r->next;
	r->next = NULL;

	//释放空间
	while(p)
	{
		r = p->next;
		free(p);
		p = r;
	}
	p = N2->next;
	while(p)
	{
		r = p->next;
		free(p);
		p = r;
	}
	N2->next = NULL;
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
