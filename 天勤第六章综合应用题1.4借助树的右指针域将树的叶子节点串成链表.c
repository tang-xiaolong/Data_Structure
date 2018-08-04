#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	char c;
	struct node *lC,*rC;
}Tree,*pTree;

pTree head = NULL,tail = NULL;

pTree PreGetValue(pTree p);
void BigChuanShao(pTree p);
void TreaverseList(pTree p);


int main(void)
{
	Tree tree;// ABD##E##CF###
	PreGetValue(&tree);
	BigChuanShao(&tree);
	TreaverseList(head);
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
void BigChuanShao(pTree p)
{
	if(p)
	{
		if(p->lC == NULL && p->rC == NULL)//叶子节点
		{
			if(head == NULL)
			{
				head = p;
				tail = p;
				//tail->rC = NULL;  叶子节点本身右指针域就为空 可以省去这句话
			}
			else
			{
				tail->rC = p;
				tail = p;
				//tail->rC = NULL;
			}
		}
		if(p->lC != NULL)
		{
			BigChuanShao(p->lC);
		}
		if(p->rC != NULL)
		{
			BigChuanShao(p->rC);
		}
	}
}

void TreaverseList(pTree p)
{
	pTree temp = p;
	while(temp!=NULL)
	{
		putchar(temp->c);
		temp = temp->rC;
	}
	putchar('\n');
}