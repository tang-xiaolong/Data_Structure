//功能：实现双向循环链表的插入、打印、排序（从小到大）、遍历删除（指定数）
//时间：2018年12月27日 21:39:40
//思路：
#include<stdio.h>
#include<malloc.h>
#define ENDDATA 32767  //作为输入的结束符

typedef struct doubleList
{
	int data;
	struct doubleList *pre;//前驱
	struct doubleList *next;//后继
}DoubleList;//定义了一个双向循环链表的节点数据类型

/*函数声明*/
DoubleList* CreateDouble();//创建一个双向循环链表，返回它的头节点
int DoubleInsert(DoubleList *pHead,int data,int pos);//双向循环链表插入到第pos个位置   成功返回1,否则返回-1
void DoubleTreaverse(DoubleList *pHead);//双向循环链表的遍历
void DoubleSort(DoubleList *pHead);//双向循环链表排序
int DoubleDelete(DoubleList *pHead,int value);//双向循环链表按值删除一个数，成功返回1  否则返回-1

int main(void)
{
	int value,pos;
	DoubleList *pHead = CreateDouble();//创建一个单链表
	DoubleTreaverse(pHead);//遍历
	printf("请输入要插入的值以及位置，用空格隔开：");
	scanf("%d%d",&value,&pos);
	if(DoubleInsert(pHead,value,pos) == 1)//插入一个值
		printf("%d插入成功\n",value);
	else
		puts("插入失败");
	DoubleTreaverse(pHead);
	printf("排序结果为：");
	DoubleSort(pHead);
	DoubleTreaverse(pHead);
	printf("请输入要删除的数：");
	scanf("%d",&value);
	if(DoubleDelete(pHead,value) == 1)
		printf("%d删除成功\n",value);
	else
		puts("删除失败！没有这个数");
	DoubleTreaverse(pHead);
	return 0;
}

//创建一个双向循环链表，返回它的头节点
DoubleList* CreateDouble()
{
	//创建一个头节点，然后让用户输入数据，当输入结束的数据时就停止创建，并返回头节点
	int data;
	DoubleList *pHead = (DoubleList *)malloc(sizeof(DoubleList));//申请一个头节点
	DoubleList *pre = pHead,*temp;
	pHead->pre = pHead->next = pHead;//默认前驱后继都指向自己
	printf("请依次输入数据并用空格隔开，当输入%d时结束：",ENDDATA);
	while(1)
	{
		scanf("%d",&data);
		if(data != ENDDATA)//不为结束的，则造一个节点连接上
		{
			temp = (DoubleList *)malloc(sizeof(DoubleList));
			pre->next = temp;
			temp->pre = pre;
			temp->data = data;//给这个新节点赋值
			pre = temp;
		}
		else
			break;
	}
	pre->next = pHead;
	return pHead;
}
//双向循环链表插入到第pos个位置   成功返回1,否则返回-1
int DoubleInsert(DoubleList *pHead,int data,int pos)
{
	int i; 
	DoubleList *temp,*pre = pHead;
	for(i = 1;i < pos;++i)//先往后移那么多个
	{
		if(pre->next != pHead)//可以移
			pre = pre->next;
		else
			return -1;
	}
	//已经移到了这个位置
	temp = (DoubleList *)malloc(sizeof(DoubleList));
	temp->data = data;
	temp->next = pre->next;//让新节点与q的后一个节点连上
	pre->next->pre = temp;//让q后一个节点连上这个新节点
	pre->next = temp;//让q的后继变成这个新节点
	temp->pre = pre;//让新节点前驱指向q
	return 1;
}

//双向循环链表的遍历
void DoubleTreaverse(DoubleList *pHead)
{
	DoubleList *p = pHead->next;
	while(p != pHead)//p不为头节点时输出它的值
	{
		printf("%3d",p->data);
		p = p->next;
	}
	putchar('\n');
}

//双向循环链表排序
void DoubleSort(DoubleList *pHead)
{
	//依次遍历整个链表，找到最小的一个并从原链摘掉
	DoubleList * p = pHead,*r = pHead->next,*q,*pre;
	int min = 32767;
	//从p开始找，找到最小的一个放到已排序的最后地方，p是未排序的第一个
	while(p->next != pHead)//还有未排序的
	{
		min = 32767;
		q = pre = p;
		r = p->next;
		while(r != pHead)//当r不为头节点时，则继续遍历
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
		q->next = r->next;//先把自己摘出来，让前后节点连接上
		r->next->pre = q;
		r->next = p->next;//让自己的后继变成未排序的第一个
		p->next->pre = r;//让未排序的第一个与自己连上
		r->pre = p;//把自己与已排序的部分连接起来
		p->next = r;
		p = p->next;//继续往后
	}
}

//双向循环链表按值删除一个数，成功返回1  否则返回-1
int DoubleDelete(DoubleList *pHead,int value)
{
	DoubleList *p = pHead,*q = p->next;
	while(q != pHead)
	{
		if(q->data == value)//找到了这个值，那我就删除它
		{
			p->next = q->next;
			q->next->pre = p;
			free(q);
			return 1;
		}
		q = q->next;
		p = p->next;
	}
	return -1;
}
