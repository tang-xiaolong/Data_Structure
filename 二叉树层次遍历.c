#include<stdio.h>
#include<malloc.h>
#define maxSize 4
typedef struct node
{
	char data;
	struct node *lChild,*rChild;
}Node,*pNode;
void Init(pNode );
pNode PreGetValue(pNode pHead,char c);
void PreTreaverse(pNode pHead);
void LevelTreaverse(pNode pHead);
int main(void)
{
	char c;
	Node tree;
	Init(&tree);
	printf("请按照前序方式一次性输完整棵树，中间不要有空格和回车,若该节点为空则输入#号\n");
	c = getchar();
	PreGetValue(&tree,c);
	puts("前序输出为：");
	PreTreaverse(&tree);
	putchar('\n');
	puts("层次遍历为：");
	LevelTreaverse(&tree);
	putchar('\n');
	return 0;
}

void Init(pNode pHead)
{
	pHead->data = '\0';
	pHead->lChild = pHead->rChild = NULL;
}
pNode PreGetValue(pNode pHead,char c)
{
	pNode p;
	char temp;
	if(c != '#')
	{
		pHead->data = c;
		p = (pNode)malloc(sizeof(Node));
		temp = getchar();
		pHead->lChild = PreGetValue(p,temp);
		p = (pNode)malloc(sizeof(Node));
		temp = getchar();
		pHead->rChild = PreGetValue(p,temp);
	}
	else
		pHead = NULL;
	return pHead;
}

void PreTreaverse(pNode pHead)
{
	if(pHead)
	{
		printf("%c",pHead->data);
		if(pHead->lChild)
			PreTreaverse(pHead->lChild);
		if(pHead->rChild)
			PreTreaverse(pHead->rChild);
	}
}
void LevelTreaverse(pNode pHead)
{
	int front = 0,Near = 0;
	pNode queue[maxSize];//ABD##E##CF###  由于队列设置的很紧凑，所以判断条件不好设置。尽管最多只有三个元素在队列，还是无法构建长度为三的循环队列完成这棵树，输出这颗树，maxSize最少为4
	pNode p = pHead;
	if(p != NULL)
	{
		queue[Near] = p;//将根节点入队  先入队，后移下标
		Near = (Near+1)%maxSize;
		while(front != Near)
		{
			p = queue[front];//这里要先取值，再移下标
			printf("%c",p->data);
			front = (front+1)%maxSize;
			if(p->lChild != NULL)//左孩子不为空，左孩子入队
			{
				queue[Near] = p->lChild;
				Near = (Near+1)%maxSize;
			}
			if(p->rChild != NULL)//右孩子不为空，右孩子入队
			{
				queue[Near] = p->rChild;
				Near = (Near+1)%maxSize;
			}
		}
	}
}
//示例输入
/*
请按照前序方式一次性输完整棵树，中间不要有空格和回车,若该节点为空则输入#号
ABD##E##CF###
前序输出为：
ABDECF
层次遍历为：
ABCDEF
Press any key to continue
*/
