#include<stdio.h>
#include<stdlib.h>
#define N 13
typedef struct node
{
	int data;
	struct node* next;
}Node;
Node* Create(int );
void LinkFu(Node*);
void Treaverse(Node*);


void ListFu(int *);

int main(void)
{
	int a[N] = {0};
	int i = 0;

	Node* myTree = Create(13);
	LinkFu(myTree);
	Treaverse(myTree);
	/*ListFu(a);

	for(i = 0;i < N;i++)
		printf("%d  ",a[i]);
	putchar('\n');
	*/
	return 0;
}

Node* Create(int n)
{
	int i;
	Node* pHead = (Node*)malloc(sizeof(Node));
	Node* p = pHead;
	Node* s;
	for(i = 0;i < n;i++)
	{
		s = (Node*)malloc(sizeof(Node));
		s->data = 0;
		p->next = s;
		p = s;
	}
	s->next = pHead->next;
	return s->next;
}

void LinkFu(Node* myTree)
{
	Node* p = myTree;
	int count,i = 2;
	myTree->data = 1;
	while(i <= 13)
	{
		count = 0;
		while(1)
		{
			p = p->next;
			if(p->data == 0)
			{
				count++;
			}	
			if(count == i)
				break;
		}
		p->data = i;
		i++;
	}
}
void Treaverse(Node* myTree)
{
	Node* p = myTree;
	while(p->next != myTree)
	{
		printf("%d  ",p->data);
		p = p->next;
	}
	printf("%d\n",p->data);
}
void ListFu(int *a)
{
	int i=2,j,count,index=0;
	a[0] = 1;
	while(i <= 13)
	{
		count = 0;
		//根据i决定往后移多少次
		for(j = index;count < i;j = (j+1)%N)
		{
			if(a[j] == 0)
			{
				count++;
				index = j;
			}
		}
		a[index] = i;
		i++;
	}
	printf("数组计算  牌按如下顺序排列即可：");
}
