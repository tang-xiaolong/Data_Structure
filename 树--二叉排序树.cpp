
/* 
C语言版
5 7 2 8 12 23
#include<stdio.h>
#include<malloc.h>
#define maxSize 20
typedef struct btNode
{
	int key;
	struct btNode* lc;
	struct btNode* rc;
}BtNode;

BtNode* Create(BtNode *bt,int *num,int len);
int Insert(BtNode **bt,int value);
void MidPrint(BtNode *bt);

int main(void)
{
	BtNode *tree = NULL;
	int num[maxSize];
	int len,i;
	scanf("%d",&len);
	for(i = 0;i < len;++i)
		scanf("%d",&num[i]);
	tree = Create(tree,num,len);
	MidPrint(tree);
	putchar('\n');
	return 0;
}

BtNode* Create(BtNode *bt,int *num,int len)
{
	int i;
	bt = NULL;
	for(i = 0;i < len;++i)
	{
		Insert(&bt,num[i]);
	}
	return bt;
}

int Insert(BtNode **bt,int value)
{
	if(*bt == NULL)
	{
		*bt = (BtNode*)malloc(sizeof(BtNode));
		(*bt)->lc = (*bt)->rc = NULL;
		(*bt)->key = value;
		return 1;
	}
	else
	{
		if((*bt)->key == value)
		{//插入失败了，已经存在一个value了
			return 0;
		}
		else if((*bt)->key > value)
			return Insert(&((*bt)->lc),value);
		else
			return Insert(&((*bt)->rc),value);
	}
}

void MidPrint(BtNode *bt)
{
	if(bt  == NULL)
		return ;
	else
	{
		MidPrint(bt->lc);
		printf("%3d",bt->key);
		MidPrint(bt->rc);
	}
}
 */


//C++版  使用了引用类型变量
//5 7 2 8 12 23
#include<stdio.h>
#include<malloc.h>
#define maxSize 20
typedef struct btNode
{
	int key;
	struct btNode* lc;
	struct btNode* rc;
}BtNode;

BtNode* Create(BtNode *bt,int *num,int len);
int Insert(BtNode *&bt,int value);
void MidPrint(BtNode *bt);
BtNode * Find(BtNode *bt,int value);
int Delete(BtNode *bt,int value);

//12 5 4 3 8 7 6 19 17 12 13 18 30
int main(void)
{
	BtNode *tree = NULL;
	int num[maxSize];
	int len,i;
	scanf("%d",&len);
	for(i = 0;i < len;++i)
		scanf("%d",&num[i]);
	tree = Create(tree,num,len);
	MidPrint(tree);
	putchar('\n');
	Delete(tree,8);
	MidPrint(tree);
	putchar('\n');
	return 0;
}

BtNode* Create(BtNode *bt,int *num,int len)
{
	int i;
	bt = NULL;
	for(i = 0;i < len;++i)
	{
		Insert(bt,num[i]);
	}
	return bt;
}

int Insert(BtNode *&bt,int value)
{
	if(bt == NULL)
	{
		bt = (BtNode*)malloc(sizeof(BtNode));
		bt->lc = bt->rc = NULL;
		bt->key = value;
		return 1;
	}
	else
	{
		if(bt->key == value)
		{//插入失败了，已经存在一个value了
			return 0;
		}
		else if(bt->key > value)
			return Insert(bt->lc,value);
		else
			return Insert(bt->rc,value);
	}
}
BtNode * Find(BtNode *bt,int value)
{
	if(bt == NULL)
	{
		return NULL;
	}
	else
	{
		if(bt->key == value)
			return bt;
		else if(bt->key > value)
			return Find(bt->lc,value);
		else
			return Find(bt->rc,value);
	}
}
void MidPrint(BtNode *bt)
{
	if(bt  == NULL)
		return ;
	else
	{
		MidPrint(bt->lc);
		printf("%3d",bt->key);
		MidPrint(bt->rc);
	}
}

int Delete(BtNode *bt,int value)
{
	BtNode *p = bt,*q = NULL,*temp,*temp1;
	int v = 0;
	while(p)
	{
		if(p->key == value)//找到这个节点了，判断p的情况
		{
			if(p->lc == NULL && p->lc == NULL)
			{
				if(q != NULL && q->lc == p)
					q->lc = NULL;
				else if(q != NULL &&q->rc == p)
					q->rc = NULL;
				free(p);
				return 1;
			}
			else if(p->lc != NULL && p->rc != NULL)
			{
				//左右子树都不为空  用直接后继来代替自己  或者是直接前驱代替自己  
				temp = p->rc;
				while(temp->lc != NULL)
				{
					if(temp->lc->lc != NULL)
						temp = temp->lc;
					else
					{
						v = temp->lc->key;
						temp1 = temp->lc;
						temp->lc = temp->lc->rc;
						temp = temp1;
					}
				}
				p->key = v;
				free(temp);
				return 1;
			}
			else
			{
				if(q != NULL && q->lc == p)
					q->lc = p->lc == NULL?p->rc:p->lc;
				else if(q != NULL && q->rc == p)
					q->rc = p->lc == NULL?p->rc:p->lc;
				free(p);
				return 1;
			}
		}
		else if(p->key > value)
		{
			q = p;
			p = p->lc;
		}
		else
		{
			q = p;
			p = p->rc;
		}
	}
	return 0;
}
