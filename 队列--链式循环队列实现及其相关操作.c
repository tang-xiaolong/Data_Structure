//功能：用链表实现循环队列
//时间：2018年12月27日 21:36:16
//思路：
#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	int data;
	struct node *next;
}Node;//定义节点类型

typedef struct que//定义一个队列类型
{
	Node *front;
	Node *rear;
	int len;//队列内元素个数
	int size;//最多容纳的元素个数
}Que;

Que * Create(int len);//创建一个长度为len的循环队列
int isEmpty(Que *que);//队列是否为空  是则返回1  否则返回0
int isFull(Que *que);//队列是否为满   是则返回1  否则返回0
int Push(Que *que,int value);//入队   成功返回入队的值   失败返回-1
int Pop(Que *que);//出队   成功返回出队的值   失败返回-1
void Print(Que *que);//打印队列里的值

int main(void)
{
	int value = 5,len,select;
	Que *que;//创建长度为4的循环队列
	printf("请输入队列的长度：");
	scanf("%d",&len);
	que = Create(len);
	while(1)
	{
		printf("请选择您的操作：1、入队一个元素   2、出队   3、打印   4、退出");
		scanf("%d",&select);
		if(select == 4)
			break;
		switch(select)
		{
		case 1:
			printf("请输入您要入队的元素值：");
			scanf("%d",&value);
			if(Push(que,value) != -1)
				puts("入队成功");
			else
				puts("入队失败");
			break;
		case 2:
			if((value = Pop(que)) != -1)
				printf("出队成功，刚出队的元素值为%d\n",value);
			else
				puts("出队失败");
			break;
		case 3:
			Print(que);
			break;
		default:
			puts("输入有误！");
		}
	}
	return 0;
}

Que *Create(int len)//创建一个长度为len的队列
{
	Que *myQue = (Que *)malloc(sizeof(Que));
	Node *p,*q;
	int i;
	if(len <= 0)//如果长度不合适，返回NULL
		return NULL;
	p = (Node *)malloc(sizeof(Node));//创建第一个节点
	myQue->front = myQue->rear = p;//队列初始化
	myQue->len = 0;
	myQue->size = len;
	p->next = q = p;
	for(i = 0;i < len;++i)
	{
		q->next = (Node *)malloc(sizeof(Node));
		q = q->next;
	}
	q->next = p;//收尾相连
	return myQue;
}

int isEmpty(Que *que)//队列是否为空
{
	if(que->len == 0)
		return 1;
	else
		return 0;
}
int isFull(Que *que)//队列是否为满
{
	if(que->len == que->size)
		return 1;
	else
		return 0;
}
int Push(Que *que,int value)//入队
{
	//初始的时候front和rear相等    当rear->next 与front相等时，则不能放了
	if(!isFull(que))//如果没有满
	{
		//把value放到rear的位置
		que->rear->data = value;
		que->rear = que->rear->next;
		que->len++;//长度加1
		return value;
	}
	else
		return -1;
}
int Pop(Que *que)//出队
{
	int value;
	if(!(isEmpty(que)))//如果不为空
	{
		value = que->front->data;
		que->front = que->front->next;
		que->len--;
		return value;
	}
	else
		return -1;
}
void Print(Que *que)//打印队列里的值
{
	Node *p;
	if(!que)//如果队列不存在
		return ;
	p = que->front;
	while(p != que->rear)
	{
		printf("%3d",p->data);
		p = p->next;
	}
	putchar('\n');
}
