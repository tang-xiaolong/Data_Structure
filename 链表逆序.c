//带头节点的单链表逆序，结束后返回头节点，头节点指向逆序后的第一个节点
//初始化一个带头节点的链表
/*
#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	int data;
	struct node* next;
}Node;

Node* Init();//初始化单链表
void Fuzhi(Node *pHead);
void Treaverse(Node * pHead,char *info);
Node* Inverse(Node * pHead);

int main(void)
{
	Node* pHead = Init();
	Fuzhi(pHead);
	Treaverse(pHead,"逆序前的链表数据为：");
	pHead = Inverse(pHead);
	Treaverse(pHead,"逆序后的链表数据为：");
	return 0;
}

Node* Init()
{
	Node* pHead = (Node*)malloc(sizeof(Node));
	pHead->next = NULL;
	return pHead;
}

void Fuzhi(Node *pHead)
{
	int value = 0;
	Node* p = pHead,*q;
	printf("请输入您链表要存取的数据（输入32768结束）：");
	scanf("%d",&value);
	while(value!=32768)
	{
		q = (Node*)malloc(sizeof(Node));
		q->data = value;
		p->next =  q;
		p = q;
		scanf("%d",&value);
	}
	p->next = NULL;
}
void Treaverse(Node * pHead,char *info)
{
	Node* p = pHead->next;
	if(p != NULL)
		printf("%s",info);
	while(p!=NULL)
	{
		printf("%3d ",p->data);
		p = p->next;
	}
	putchar('\n');
}

Node* Inverse(Node * pHead)
{
	Node *p= pHead->next,*q = NULL;
	while(p!=NULL)
	{
		pHead->next = p;
		p = p->next;
		pHead->next->next = q;
		q = pHead->next;
	}
	return pHead;
}
*/

//逆序不带头节点的单链表，结束后返回逆序后的第一个节点指针
#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	int data;
	struct node * next;
}Node;

Node* Fuzhi(Node *pHead);
void Treaverse(Node * pHead,char *info);
Node* Inverse(Node * pHead);


int main(void)
{
	Node* pHead = NULL;
	pHead = Fuzhi(pHead);
	
	Treaverse(pHead,"逆序前的链表数据为：");
	pHead = Inverse(pHead);
	Treaverse(pHead,"逆序后的链表数据为：");
	return 0;
}

Node* Fuzhi(Node* pHead)
{
	int value = 0;
	Node* p = pHead,*q;
	printf("请输入您链表要存取的数据（输入32768结束）：");
	scanf("%d",&value);
	while(value!=32768)
	{
		if(pHead == NULL)
		{//如果为空，则创建一个节点保存值，并使指针p也指向这个节点
			pHead = (Node*)malloc(sizeof(Node));
			pHead->data = value;
			p = pHead;
		}
		else
		{//创建一个新的节点，并使p指向这个节点
			q = (Node*)malloc(sizeof(Node));
			q->data = value;
			p->next = q;
			p = q;
		}
		scanf("%d",&value);
	}
	p->next = NULL;
	return pHead;
}

void Treaverse(Node * pHead,char *info)
{
	Node* p = pHead;
	if(p != NULL)
		printf("%s",info);
	while(p!=NULL)
	{
		printf("%3d ",p->data);
		p = p->next;
	}
	puts("");
}

Node* Inverse(Node * pHead)
{
	Node* p ,*q = NULL;
	if(pHead == NULL)
		return pHead;
	p = pHead->next;
	while(p!=NULL)
	{
		pHead->next = q;
		q = pHead;
		pHead = p;
		p = p->next;
	}
	pHead->next = q;
	return pHead;
}