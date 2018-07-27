#include<stdio.h>
#define maxSize 10
#define Error -32767

typedef struct stack
{
	int data[maxSize];
	int top[2];
}Stack;

void Init(Stack*);
int Push(Stack* p,int id,int value);
int Pop(Stack* p,int id);

int main(void)
{
	int i;
	Stack p;
	Init(&p);
	for(i = 0;i < maxSize;++i)
		if(i < 5)
			Push(&p,1,i);
		else
			Push(&p,2,i);
	Push(&p,1,12);
	printf("%d\n",Pop(&p,1));
	Push(&p,1,12);
	return 0;
}

void Init(Stack* p)
{
	p->top[0] = -1;
	p->top[1] = maxSize;
}

int Push(Stack* p,int id,int value)
{
	if(p->top[0] == p->top[1]-1)
	{
		printf("Õ»ÒÑÂú£¡\n");
		return Error;
	}
	if(id == 1)
	{
		p->top[0]++;
		p->data[p->top[0]] = value;
	}
	else
	{
		p->top[1]--;
		p->data[p->top[1]] = value;
	}
	return 1;
}
int Pop(Stack* p,int id)
{
	int num = Error;
	if(id ==1)
	{
		if(p->top[0] != -1)
			num = p->data[p->top[0]],p->top[0]--;
		else
		{
			printf("Õ»%dÎª¿Õ£¡\n",id);
			return Error;
		}
	}
	else
	{
		if(p->top[1] != maxSize)
			num = p->data[p->top[1]],p->top[1]++;
		else
		{
			printf("Õ»%dÎª¿Õ£¡\n",id);
			return Error;
		}
	}
	return num;
}