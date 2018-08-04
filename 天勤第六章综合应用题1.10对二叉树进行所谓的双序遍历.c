#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	char c;
	struct node *lC,*rC;
}Tree,*pTree;

pTree PreGetValue(pTree p);
void DoubleTreaverse(pTree p);


int main(void)
{
	Tree tree;// ABD##E##CF###
	PreGetValue(&tree);
	DoubleTreaverse(&tree);
	putchar('\n');
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

void DoubleTreaverse(pTree p)
{
	if(p)
	{
		putchar(p->c);
		DoubleTreaverse(p->lC);
		putchar(p->c);
		DoubleTreaverse(p->rC);
	}
}
