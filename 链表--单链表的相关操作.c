//功能：实现单链表的插入、打印、排序（从小到大）、遍历删除（指定数）
//时间：2018年12月27日 21:35:35
//思路：
#include<stdio.h>
#include<malloc.h>
#define ENDDATA 32767  //作为输入的结束符

typedef struct simpleList
{
	int data;
	struct simpleList *next;
}SimpleList;//定义了一个单链表的节点数据类型


//创建一个单链表，返回它的头节点
SimpleList* CreateSimple()
{
	//创建一个头节点，然后让用户输入数据，当输入结束的数据时就停止创建，并返回头节点
	int data;
	SimpleList *pHead = (SimpleList *)malloc(sizeof(SimpleList));//申请一个头节点
	SimpleList *temp = pHead;
	
	printf("请依次输入数据并用空格隔开，当输入%d时结束：",ENDDATA);
	while(1)
	{
		scanf("%d",&data);
		if(data != ENDDATA)//不为结束的，则造一个节点连接上
		{
			temp->next = (SimpleList *)malloc(sizeof(SimpleList));
			temp = temp->next;//往后移一个
			temp->data = data;//给这个新节点赋值
		}
		else
			break;
	}
	temp->next = NULL;
	return pHead;
}
//单链表插入到第k个位置   成功返回1,否则返回-1
int SimpleInsert(SimpleList *pHead,int data,int pos)
{
	int i;
	SimpleList *temp,*q = pHead;
	for(i = 1;i < pos;++i)//因为有头节点  所以从1开始往后，插入需要找到待插入位置的前一个节点
	{
		if(q != NULL)//可以移
		{
			q = q->next;
		}
		else
			return -1;
	}
	//已经移到了这个位置
	temp = (SimpleList *)malloc(sizeof(SimpleList));
	temp->data = data;
	temp->next = q->next;
	q->next = temp;
	return 1;
}

//单链表的遍历
void SimpleTreaverse(SimpleList *pHead)
{
	SimpleList *p = pHead->next;
	while(p)//p不为空时输出它的值
	{
		printf("%3d",p->data);
		p = p->next;
	}
	putchar('\n');
}

//单链表排序
void SimpleSort(SimpleList *pHead)
{
	//依次遍历整个链表，找到最小的一个并从原链摘掉
	SimpleList * p = pHead,*r = pHead->next,*q,*pre;
	int min = 32767;
	//从p开始找，找到最小的一个放到已排序的最后地方，p是未排序的第一个
	while(p->next != NULL)//还有未排序的
	{
		min = 32767;
		q = pre = p;
		r = p->next;
		while(r != NULL)//当r不为空，则继续遍历
		{
			if(r->data < min)
			{
				q = pre;//始终保存最小节点的前一个节点
				min = r->data;//更新最小的节点
			}
			pre = pre->next;
			r = r->next;
		}
		//此时q是最小的那个节点的前一个节点
		r = q->next;
		q->next = r->next;
		r->next = p->next;
		p->next = r;
		p = p->next;
	}
}

//单链表按值删除一个数，成功返回1  否则返回-1
int SimpleDelete(SimpleList *pHead,int value)
{
	SimpleList *p = pHead,*q = p->next;
	while(q != NULL)
	{
		if(q->data == value)//找到了这个值，那我就删除它
		{
			p->next = q->next;
			free(q);
			return 1;
		}
		q = q->next;
		p = p->next;
	}
	return -1;
}

int main(void)
{
	int value,pos;
	SimpleList *pHead = CreateSimple();//创建一个单链表
	SimpleTreaverse(pHead);//遍历
	printf("请输入要插入的值以及位置，用空格隔开：");
	scanf("%d%d",&value,&pos);
	if(SimpleInsert(pHead,value,pos) == 1)//插入一个值
		printf("%d插入成功\n",value);
	else
		puts("插入失败");
	SimpleTreaverse(pHead);
	printf("排序结果为：");
	SimpleSort(pHead);
	SimpleTreaverse(pHead);
	printf("请输入要删除的数：");
	scanf("%d",&value);
	if(SimpleDelete(pHead,value) == 1)
		printf("%d删除成功\n",value);
	else
		puts("删除失败！没有这个数");
	SimpleTreaverse(pHead);
	return 0;
}
