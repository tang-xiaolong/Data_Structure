#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	char data;
	struct node *lChild,*rChild;
}Node,*pNode;
void Init(pNode );
pNode PreGetValue(pNode pHead,char c);
void PreTreaverse(pNode pHead);
int CalculateHigh(pNode pHead);
int main(void)
{
	char c;
	int high = 0;
	Node tree;
	Init(&tree);
	printf("请按照前序方式一次性输完整棵树，中间不要有空格和回车,若该节点为空则输入#号\n");
	c = getchar();
	PreGetValue(&tree,c);
	PreTreaverse(&tree);
	putchar('\n');
	high = CalculateHigh(&tree);
	printf("此树的深度为：%d\n",high);
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

int CalculateHigh(pNode pHead)
{
	int A,B;
	if(pHead)
	{
		A = CalculateHigh(pHead->lChild);
		B = CalculateHigh(pHead->rChild);
		return (A>B?A:B)+1;
	}
	else
		return 0;
}

//事例输入
/*
请按照前序方式一次性输完整棵树，中间不要有空格和回车,若该节点为空则输入#号
ABD##E##CF###
ABDECF
此树的深度为：3
Press any key to continue
*/
