#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	char c;
	struct node *lC,*rC;
}Tree,*pTree;

pTree PreGetValue(pTree p);
int CalculateNum(pTree p);



int main(void)
{
	Tree tree;// ABD##E##CF###
	int count = 0;
	PreGetValue(&tree);
	count = CalculateNum(&tree);
	printf("有%d个节点\n",count);
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
int CalculateNum(pTree p)
{
	int l = 0,r = 0;
	if(p == NULL)
		return 0;
	else
	{
		l = CalculateNum(p->lC);
		r = CalculateNum(p->rC);
	}
	return l+r+1;
}