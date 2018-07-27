#include<malloc.h>
//×Ö·ûË³ĞòÕ»
typedef struct cStack
{
	char data[101];
	int top;
	int bottom;
}CS,*PCS;

//ÕûĞÍË³ĞòÕ»
typedef struct iStack
{
	char data[101];
	int top;
	int bottom;
}IS,*PIS;

PCS InitC()
{
	PCS pHead = (PCS)malloc(sizeof(CS));
	pHead->top = -1; 
	pHead->bottom = -1;
	return pHead;
}

PIS InitI()
{
	PIS pHead = (PIS)malloc(sizeof(CS));
	pHead->top = -1; 
	pHead->bottom = -1;
	return pHead;
}

int PushC(PCS pHead,char c)
{
	if(pHead->top == 101-1)
	{
		//printf("Õ»Âú£¡ÈëÕ»Ê§°Ü£¡\n");
		return -1;
	}
	pHead->top++;
	pHead->data[pHead->top] = c;
	return 1;
}
char PopC(PCS pHead)
{
	char c;
	if(pHead->top == -1)
	{
		//printf("Õ»¿Õ£¡³öÕ»Ê§°Ü£¡\n");
		return '\0';
	}
	c = pHead->data[pHead->top];
	pHead->top--;
	return c;
}

int PushI(PIS pHead,int c)
{
	if(pHead->top == 101-1)
	{
		//printf("Õ»Âú£¡ÈëÕ»Ê§°Ü£¡\n");
		return -1;
	}
	pHead->top++;
	pHead->data[pHead->top] = c;
	return 1;
}
int PopI(PIS pHead)
{
	int c;
	if(pHead->top == -1)
	{
		//printf("Õ»¿Õ£¡³öÕ»Ê§°Ü£¡\n");
		return -1;
	}
	c = pHead->data[pHead->top];
	pHead->top--;
	return c;
}

void ClearC(PCS pHead)
{
	while(PopC(pHead) != '\0')
		;
}

void ClearI(PIS pHead)
{
	while(PopI(pHead) != -1)
		;
}

char GetC(PCS pHead)
{
	if(pHead->top != -1)
		return pHead->data[pHead->top];
	else
		return '\0';
}

int GetI(PIS pHead)
{
	if(pHead->top != -1)	
		return pHead->data[pHead->top];
	else
		return -32767;
}
int EmptyC(PCS pHead)
{
	if(pHead->top == -1)
		return 1;
	else
		return 0;
}

int EmptyI(PIS pHead)
{
	if(pHead->top == -1)
		return 1;
	else
		return 0;
}
