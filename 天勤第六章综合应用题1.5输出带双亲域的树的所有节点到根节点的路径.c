#include<stdio.h>
#include<malloc.h>
typedef struct node 
{
	char c;
	struct node *lC,*rC,*parent;
}Tree,*pTree;

pTree PreGetValue(pTree parent,pTree p);
void PutLoad(pTree p);


int main(void)
{
	Tree tree;
	PreGetValue((pTree)NULL,&tree);//  ABD##E##CF###
	PutLoad(&tree);
	return 0;
}

pTree PreGetValue(pTree parent,pTree p)
{
	char c;
	c = getchar();
	if(c != '#')
	{
		p->c = c;
		p->parent = parent;
		p->lC = PreGetValue(p,(pTree)malloc(sizeof(Tree)));
		p->rC = PreGetValue(p,(pTree)malloc(sizeof(Tree)));
	}
	else
		p = NULL;
	return p;
}

void PutLoad(pTree p)
{
	pTree temp = p;
	if(p == NULL)
		return;
	while(temp->parent != NULL)
	{
		putchar(temp->c);
		temp = temp->parent;
	}
	putchar(temp->c);
	putchar('\n');
	if(p->lC != NULL)
		PutLoad(p->lC);
	if(p->rC != NULL)
		PutLoad(p->rC);
}