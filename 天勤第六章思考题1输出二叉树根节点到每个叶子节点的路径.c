#include<stdio.h>
#include<malloc.h>
#define maxSize 20
typedef struct node
{
	char c;
	struct node *lC,*rC;
}Tree,*pTree;
//思路：构建一个栈，遇到一个节点就压栈，若是叶子节点，就从栈底遍历到栈顶   当从一个节点返回后，应该出栈
pTree stack[maxSize];
int top = 0;

void GetPath(pTree p);

pTree PreGetValue(pTree p);
int main(void)
{//   ABD##E##CF###
	Tree tree;
	PreGetValue(&tree);
	GetPath(&tree);
	return 0;
}

pTree PreGetValue(pTree p)
{
	char c;
	c = getchar();
	if(c != '#')
	{
		p->c = c;
		p->lC = PreGetValue((pTree)malloc(sizeof(Tree)));
		p->rC = PreGetValue((pTree)malloc(sizeof(Tree)));
	}
	else
		p = NULL;
	return p;
}

void GetPath(pTree p)
{
	int i = 0;
	if(p)
	{
		stack[top++] = p;
		if(p->lC == NULL && p->rC == NULL)
		{
			for(i = 0;i < top;++i)
				putchar(stack[i]->c);
			putchar('\n');
			//top--;//自身退栈
			return ;
		}
		if(p->lC)
		{//当有左孩子，才遍历并在结束后退栈
			GetPath(p->lC);
			top--;
		}
		if(p->rC)
		{
			GetPath(p->rC);
			top--;
		}
	}
}