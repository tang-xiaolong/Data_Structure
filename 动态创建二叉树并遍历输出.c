#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	int data;
	struct node *lChild,*rChild;
}Node,*pNode;

pNode Init();
pNode PreGetValue(pNode,int);//前序输入
void PreTreaverse(pNode );//前序输出

void MidTreaverse(pNode );//中序输出

void LasTreaverse(pNode );//后序输出


int main(void)
{
	pNode myTree;
	int num;
	myTree = Init();
	printf("请按中序方式输入二叉树各个节点的值，输入32768则表示该节点为空节点：\n");
	scanf("%d",&num);
	myTree = PreGetValue(myTree,num);
	printf("前序遍历如下：\n");
	PreTreaverse(myTree);
	printf("中序遍历如下：\n");
	MidTreaverse(myTree);
	printf("后序遍历如下：\n");
	LasTreaverse(myTree);
	return 0;
}

pNode Init()
{
	pNode p = (pNode)malloc(sizeof(Node));
	p->lChild = NULL;
	p->rChild = NULL;
	return p;
}
pNode PreGetValue(pNode pHead,int num)
{
	pNode p;
	int temp;
	if(num != 32768)
	{
		pHead->data = num;//先将值放到自己身上，然后创建一个新节点让自己左孩子指向它，并输入值。如果为32768会返回NULL，即左孩子为NULL
		p = (pNode)malloc(sizeof(Node));
		scanf("%d",&temp);
		pHead->lChild = PreGetValue(p,temp);
		p = (pNode)malloc(sizeof(Node));//同理，创建新节点让自己右孩子指向它，并输入值
		scanf("%d",&temp);
		pHead->rChild = PreGetValue(p,temp);//左右孩子都处理完后，返回本身
		//return pHead;
	}
	else
	{
		pHead = NULL;
	}//一直到递归输入结束，返回根节点
	return pHead;
}
void PreTreaverse(pNode pHead)
{
	if(pHead != NULL)
	{
		printf("%2d  当前节点地址：%x 左孩子地址：%x 右孩子地址：%x\n",pHead->data,pHead,pHead->lChild,pHead->rChild);
		if(pHead->lChild)
			PreTreaverse(pHead->lChild);
		if(pHead->rChild)
			PreTreaverse(pHead->rChild);
	}
}

void MidTreaverse(pNode pHead)
{
	if(pHead != NULL)
	{
		if(pHead->lChild)
			MidTreaverse(pHead->lChild);
		printf("%2d  当前节点地址：%x 左孩子地址：%x 右孩子地址：%x\n",pHead->data,pHead,pHead->lChild,pHead->rChild);
		if(pHead->rChild)
			MidTreaverse(pHead->rChild);
	}
}
void LasTreaverse(pNode pHead)
{
	if(pHead != NULL)
	{
		if(pHead->lChild)
			LasTreaverse(pHead->lChild);
		if(pHead->rChild)
			LasTreaverse(pHead->rChild);
		printf("%2d  当前节点地址：%x 左孩子地址：%x 右孩子地址：%x\n",pHead->data,pHead,pHead->lChild,pHead->rChild);
	}
}
//事例输入：
/*
请按中序方式输入二叉树各个节点的值：
1
2
4
32768
32768
5
32768
32768
3
6
32768
32768
32768
前序遍历如下：
 1  当前节点地址：583b50 左孩子地址：581618 右孩子地址：583ca0
 2  当前节点地址：581618 左孩子地址：581650 右孩子地址：583bf8
 4  当前节点地址：581650 左孩子地址：0 右孩子地址：0
 5  当前节点地址：583bf8 左孩子地址：0 右孩子地址：0
 3  当前节点地址：583ca0 左孩子地址：583cd8 右孩子地址：0
 6  当前节点地址：583cd8 左孩子地址：0 右孩子地址：0
Press any key to continue
 */
