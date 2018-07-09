//1800题线性表填空题30题
//对单链表元素按插入方法排序
#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	int data;
	struct node *next;
}linknode,*link;

link Init();//初始化单链表
void Fuzhi(link pHead);
void Treaverse(link pHead,char *info);
void Insertsort(link L);

int main(void)
{
	link pHead = Init();
	Fuzhi(pHead);
	Treaverse(pHead,"排序前的链表数据为：");
	Insertsort(pHead);
	Treaverse(pHead,"排序后的链表数据为：");
	return 0;
}

link Init()
{
	link pHead = (link)malloc(sizeof(linknode));
	pHead->next = NULL;
	return pHead;
}

void Fuzhi(link pHead)
{
	int value = 0;
	link p = pHead,q;
	printf("请输入您链表要存取的数据（输入32768结束）：");
	scanf("%d",&value);
	while(value!=32768)
	{
		q = (link)malloc(sizeof(linknode));
		q->data = value;
		p->next =  q;
		p = q;
		scanf("%d",&value);
	}
	p->next = NULL;
}

void Treaverse(link pHead,char *info)
{
	link p = pHead->next;
	if(p != NULL)
		printf("%s",info);
	while(p!=NULL)
	{
		printf("%3d ",p->data);
		p = p->next;
	}
	putchar('\n');
}

void Insertsort(link L)
{
	link p,q,r,u;
	p = L->next;
	L->next = NULL;
	while(p!=NULL)
	{
		r = L;
		q = L->next;
		while(q!=NULL && q!=p && q->data <= p->data)
		{
			r = q;
			q = q->next;
		}
		u = p->next;
		p->next =  r->next;
		r->next = p;
		p = u;
	}
}
