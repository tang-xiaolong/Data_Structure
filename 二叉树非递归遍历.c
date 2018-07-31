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
void LastPrint(pTree);
void FloorPrint(pTree);

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
	printf("非递归后序输出结果：");
	LastPrint(&tree);
	putchar('\n');
	printf("层次遍历输出的结果：");
	FloorPrint(&tree);
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

void PrePrint(pTree p)
{
	pTree bucket[maxSize];
	int top = -1;
	while(p!= NULL || top != -1)
	{
		while(p)
		{
			bucket[++top]  = p;
			printf("%c",p->c);
			p = p->lC;
		}
		if(top != -1)
		{
			p = bucket[top--];
			p = p->rC;
		}
	}
}

void MidPrint(pTree p)
{
	pTree bucket[maxSize];
	int top = -1;
	while(p != NULL || top != -1)
	{
		while(p)
		{
			bucket[++top] = p;
			p =  p->lC;
		}
		if(top != -1)
		{
			p = bucket[top--];
			putchar(p->c);
			p =  p->rC;
		}
	}
}

void LastPrint(pTree p)
{
	pTree bucket[maxSize];
	int top =  -1;
	int flag[maxSize] =  {0};
	while(p != NULL || top != -1)
	{
		while(p)
		{//老规矩，一路向左，直到为空
			bucket[++top] = p;
			flag[top] = 0;
			p = p->lC;
		}
		if(top != -1)
		{//取出栈顶元素，这时候根据flag数组对应的值来判断要不要pop来这个元素
			p = bucket[top];
			if(flag[top] == 0)//如果是0，证明之前还只是访问一次，这是第二次，所以不要访问，放flag对应位置变成1，并访问右孩子
			{
				flag[top] = 1;
				p = p->rC;
			}//当碰到他且flag数组是1，证明已经访问过右孩子了，所以直接pop出来并输出值。当一个节点值输出后，必须继续pop数，所以将p其置为NULL
			else if(flag[top] == 1)
			{
				putchar(p->c);
				top--;
				p = NULL;
			}
		}
	}
}

void FloorPrint(pTree p)
{
	pTree queue[maxSize];
	int n = 0,front = 0;
	if(p)
		queue[n++] = p;
	else
		return;
	while(n != front)
	{
		p =  queue[front++];
		putchar(p->c);
		if(p->lC)
			queue[n++] = p->lC;
		if(p->rC)
			queue[n++] = p->rC;
		
	}
}
//示例输入
/*
ABD##E##CF###
  递归前序输出结果：ABDECF
非递归前序输出结果：ABDECF
非递归中序输出结果：DBEAFC
非递归后序输出结果：DEBFCA
层次遍历输出的结果：ABCDEF
Press any key to continue
*/
