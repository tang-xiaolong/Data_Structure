//2018年7月9日 20:31:35
#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	int data;
	struct node *prior;
	struct node *next;
}BNODETP;

BNODETP * Init();
void Fuzhi(BNODETP* pHead);
void Treaverse(BNODETP *L,char *info);
void unknown(BNODETP *L);


int main(void)
{
	BNODETP * pHead = NULL;
	pHead = Init();
	Fuzhi(pHead);
	Treaverse(pHead,"未排序的链表为：");
	unknown(pHead);
	Treaverse(pHead,"排序后的链表为：");
	return 0;
}


BNODETP * Init()
{
	BNODETP * pHead = (BNODETP *)malloc(sizeof(BNODETP));
	pHead->next = pHead;
	pHead->prior = pHead;
	return pHead;
}

void Fuzhi(BNODETP* pHead)
{
	int value = 0;
	BNODETP *p = pHead,*q;
	printf("请输入您链表要存取的数据（输入32768结束）：");
	scanf("%d",&value);
	while(value!=32768)
	{
		q = (BNODETP *)malloc(sizeof(BNODETP));
		q->data = value;
		q->prior = p;
		q->next = pHead;
		p->next = q;
		p = q;
		scanf("%d",&value);
	}
	pHead->prior = p;
}
void Treaverse(BNODETP *L,char *info)
{
	BNODETP *p = L->next;
	if(L == NULL)
		return ;
	else
		printf("%s",info);
	while(p != L)
	{
		printf("%3d ",p->data);
		p = p->next;
	}
	putchar('\n');
}

void unknown(BNODETP *L)
{
	BNODETP *p,*q,*r;
	p = L->next;
	q = p->next;
	r = q->next;
	while(q!=L)
	{
		while((p!=L) && (p->data>q->data))
		{
			p = p->prior;
		}//还是插入排序，从尾部往头部查找合适的位置
		q->prior->next = r;//先把待插入的节点的前一个节点链接上它的后一个节点
		r->prior = q->prior;//1、把待插入节点的后一个节点前指针域指向自己的前一个节点
		q->next = p->next;//将自己的后指针域指向要插入的位置上的节点的后一个节点，
		q->prior = p;//让自己前指针域指向要插入的位置上的节点
		p->next->prior=q;//2、把要插入的位置上的节点后一个节点前指针域指向自己
		p->next=q;//3、把要插入的位置上的节点后指针域指向自己
		q = r;
		p = q->prior;
		r = q->next;//4、把r指向q的后面一个节点
	}
}