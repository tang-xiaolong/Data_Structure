#include<stdio.h>
#include<malloc.h>
typedef int dataType;
typedef struct Linklist
{
	dataType data;
	Linklist * leftLink;
	Linklist * rightLink;
}LinkList;
typedef struct Link
{
	LinkList * pHead;
	int len;
}LINK;

void init(LINK *);
void addValue(LINK *,dataType );
void traverse(LINK*);

int main(void)
{
	LINK link;

	init(&link);

	addValue(&link,1);
	addValue(&link,2);
	addValue(&link,3);
	addValue(&link,4);
	traverse(&link);
	return 0;
}


void init(LINK * pL)
{
	pL->pHead = (LinkList*)malloc(sizeof(LinkList));
	pL->pHead->leftLink = pL->pHead->rightLink = pL->pHead;
}

void addValue(LINK *pL,dataType value)
{
	LinkList * temp  = (LinkList*)malloc(sizeof(LinkList));
	LinkList * item = pL->pHead;
	while(item->rightLink != pL->pHead)
	{
		item = item->rightLink;
	}
	item->data = value;
	item->rightLink = temp;
	temp->leftLink = item;
	temp->rightLink = pL->pHead;
	pL->pHead->leftLink = temp;
	pL->len++;
}

void traverse(LINK* pL)
{
	LinkList * temp = pL->pHead;
	while(temp->rightLink!=pL->pHead)
	{
		printf("%d %x %x \n ",temp->data,temp,temp->rightLink);
		temp = temp->rightLink;
	}
	printf("\n");
}