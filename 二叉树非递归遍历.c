#include<stdio.h>
#include<malloc.h>
#define maxSize 50
typedef struct node
{
	char c;
	struct node *lC,*rC;
}Tree,*pTree;

void Init(pTree);
pTree PreGetValue(pTree);
void PreTreaverse(pTree);
void PrePrint(pTree);
void MidPrint(pTree);

int main(void)
{
	Tree tree;
	Init(&tree);
	PreGetValue(&tree);
	printf("  递归前序输出结果：");
	PreTreaverse(&tree);
	putchar('\n');
	printf("非递归前序输出结果：");
	PrePrint(&tree);
	putchar('\n');
	printf("非递归中序输出结果：");
	MidPrint(&tree);
	putchar('\n');
	return 0;
}
void Init(pTree p)
{
	p = (pTree)malloc(sizeof(Tree));
	p->c = '\0';
	p->lC = p->rC = NULL;
}
//前序获得值
pTree PreGetValue(pTree p)
{
	char c;
	c = getchar();
	if(c != '#')
	{
		p->c = c;//ABD##E##CF###
		p->lC = (pTree)malloc(sizeof(Tree));
		p->rC = (pTree)malloc(sizeof(Tree));
		//printf("%x  %x  %x\n",p,p->lC,p->rC);
		p->lC = PreGetValue(p->lC);
		p->rC = PreGetValue(p->rC);
	}
	else
	{
		free(p);
		p = NULL;
	}
	return p;
}
void PreTreaverse(pTree p)
{
	if(p!= NULL)
	{
		printf("%c",p->c);
		if(p->lC)
			PreTreaverse(p->lC);
		if(p->rC)
			PreTreaverse(p->rC);
	}
}


//非递归前序输出
void PrePrint(pTree p)
{
	pTree bucket[maxSize];
	int top = -1;
	bucket[++top] = p;
	while(top != -1)//栈不为空
	{//算法思路：先访问当前节点。然后右孩子不为空则将右孩子压栈，左孩子不为空则将左孩子压栈，然后出栈继续
		p =  bucket[top--];
		putchar(p->c);
		if(p->rC)
		{
			bucket[++top] = p->rC;
		}
		if(p->lC)
		{
			bucket[++top] = p->lC;
		}
	}
}

//非递归中序输出
void MidPrint(pTree p)
{
	pTree bucket[maxSize];
	int top = -1;
	while(top != -1 || p!= NULL)//满足一个就循环
	{//当栈为空，且最后的p是空，就退出了
		while(p)
		{//一路向左，把左孩子全部入栈先
			bucket[++top] = p;
			p = p->lC;
		}
		//左孩子都进去了，现在输出自身，并访问右孩子
		if(top != -1)
		{
			p = bucket[top--];
			putchar(p->c);
			p = p->rC;//访问右孩子，右孩子也一路向左
		}
	}
}

