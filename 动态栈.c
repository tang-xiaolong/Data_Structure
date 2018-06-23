/*
#include<stdio.h>
#include<malloc.h>
typedef int dataType;
typedef struct Linkstack
{
	dataType data;
	struct Linkstack * sNext;
}LinkStack;


LinkStack * init(LinkStack *);
LinkStack * pushValue(LinkStack *,dataType);
LinkStack * popValue(LinkStack *);
int isEmpty(LinkStack *);
void traverse(LinkStack *);


int main(void)
{
	LinkStack *s;
	s = init(s);
	s = pushValue(s,1);
	s = pushValue(s,2);
	s= pushValue(s,3);
	traverse(s);

	s= popValue(s);
	traverse(s);
	return 0;
}

LinkStack * init(LinkStack * pS)
{
	pS=(LinkStack *)malloc(sizeof(LinkStack));
	pS->sNext = NULL;
	return pS;
}

LinkStack * pushValue(LinkStack * pS,dataType value)
{
	LinkStack * temp = (LinkStack *)malloc(sizeof(LinkStack));
	temp->data = value;
	temp->sNext = pS;
	pS = temp;
	return pS;
}

int isEmpty(LinkStack * pS)
{
	if(pS->sNext == NULL)
		return 1;
	else
		return 0;
}

LinkStack * popValue(LinkStack * pS)
{
	if(1 == isEmpty(pS))
	{
		printf("栈为空\n");
		return NULL;
	}
	else
	{
		printf("%d\n",pS->data);
		pS = pS->sNext;
		//return pS;
	}
	return pS;
}

void traverse(LinkStack * pS)
{
	LinkStack * temp = pS;
	while(temp->sNext != NULL)
	{
		printf("%d ",temp->data);
		temp = temp->sNext;
	}
	printf("\n");
}

*/


#include<stdio.h>
#include<malloc.h>
typedef int dataType;
typedef struct Node
{
	dataType data;
	struct Node * sNext;
}NODE;

typedef struct Stack
{
	NODE * top;
	NODE * button;
}STACK;

//函数声明
void init(STACK *);
int pushStack(STACK *,dataType);
int isEmpty(STACK *);
int popStack(STACK *);
void traverseStack(STACK *);
void destroyStack(STACK *);



int main(void)
{
	STACK s;
	init(&s);



	pushStack(&s,1);
	pushStack(&s,2);
	pushStack(&s,3);
	pushStack(&s,4);
	traverseStack(&s);

	popStack(&s);
	popStack(&s);
	traverseStack(&s);

	destroyStack(&s);

	return 0;
}

void init(STACK *pS)
{
	NODE * temp = (NODE *)malloc(sizeof(NODE));
	if(temp == NULL)
	{
		printf("初始化栈失败\n");
	}
	else
	{
		temp->sNext = NULL;
		pS->top = temp;
		pS->button = temp;
	}
}

int pushStack(STACK * pS,dataType value)
{
	NODE * temp = (NODE *)malloc(sizeof(NODE));
	temp->data = value;
	temp->sNext = pS->top;
	pS->top = temp;
	return 1;
}


int isEmpty(STACK * pS)
{
	if(pS->button == pS->top)
		return 1;
	else 
		return 0;
}

int popStack(STACK *pS)
{
	NODE * temp = pS->top;
	if(1 == isEmpty(pS))
	{
		printf("出栈失败，栈为空！\n");
		return 0;
	}
	else
	{
		printf("本次出栈的元素为%d\n",pS->top->data);
		pS->top = pS->top->sNext;
		free(temp);
		temp = NULL;
	}
	return 1;
}

void traverseStack(STACK * pS)
{
	NODE * temp = pS->top;
	while(temp->sNext != NULL)
	{
		printf("%d ",temp->data);
		temp = temp->sNext;
	}
	printf("\n");
}

void destroyStack(STACK * pS)
{
	NODE * temp = pS->top;
	while(temp->sNext != NULL)
	{
		temp = temp->sNext;
		free(pS->top);
		pS->top = temp;
	}
	free(temp);
}