#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	char c;
	int lTag,rTag;
	struct node *lC,*rC;
}Tree,*pTree;

pTree pre = NULL;


pTree PreGetValue(pTree );
void MidLine(pTree p);
void MidPrint(pTree p);
pTree FindMidLast(pTree p);//找t子树上中序下的最后一个节点
pTree FindMidPre(pTree p);//找t子树上中序下的前驱
pTree FindPreLast(pTree p);//找t子树上前序的后继
pTree FindNode(pTree p,char c);

int main(void)
{
	Tree tree;
	pTree temp = NULL;
	PreGetValue(&tree);//  ABD##E##CF###
	MidLine(&tree);
	MidPrint(&tree);
	temp = FindNode(&tree,'C');
	putchar('\n');
	printf("%x\n",temp);
	temp = FindMidLast(&tree);
	printf("%c  %x\n",temp->c,temp);
	temp = FindMidPre(&tree);
	printf("%c  %x\n",temp->c,temp);
	temp = FindPreLast(&tree);
	printf("%c  %x\n",temp->c,temp);
	return 0;
}

pTree PreGetValue(pTree p)
{
	char c;
	c = getchar();
	if(c!= '#')
	{
		p->c = c;
		p->lC = PreGetValue((pTree)malloc(sizeof(Tree)));
		p->rC = PreGetValue((pTree)malloc(sizeof(Tree)));
	}
	else
		p = NULL;
	return p;
}
void MidLine(pTree p)
{
	if(p)
	{
		//如果有左子树，继续找左子树
		if(p->lC != NULL)
		{
			p->lTag =  0;
			MidLine(p->lC);
		}
		else
		{
			p->lTag = 1;
			p->lC = pre;
		}
		if(pre != NULL && pre->rC == NULL)
		{
			pre->rTag = 1;
			pre->rC = p;
		}
		pre = p;
		if(p->rC != NULL)
		{
			p->rTag =  0;
			MidLine(p->rC);
		}
	}
}

void MidPrint(pTree p)
{
	if(p == NULL)
		return ;
	if(p->lTag == 0)
		MidPrint(p->lC);
	putchar(p->c);
	if(p->rTag == 0)
		MidPrint(p->rC);
}

//找到某个值所在的节点
pTree FindNode(pTree p,char c)
{
	pTree temp = NULL;
	if(p == NULL)
		return temp;
	if(p->c != c)
	{
		if(p->lTag == 0)
			temp = FindNode(p->lC,c);
		if(temp != NULL)
			return temp;
		else if(p->rTag == 0)
			temp = FindNode(p->rC,c);
		if(temp != NULL)
			return temp;
	}
	else
		return p;
	return temp;

}

pTree FindMidLast(pTree p)//找t节点子树上中序下的最后一个节点
{
	pTree temp = p;
	while(temp && temp->rTag == 0)
		temp = temp->rC;
	return temp;
}

pTree FindMidPre(pTree p)
{
	pTree temp = p;
	if(temp && temp->lTag == 0)
		return temp = FindMidLast(temp->lC);
	return temp;
}

pTree FindPreLast(pTree p)
{
	if(p->lTag == 0)
		return p->lC;
	else if(p->rTag == 0)
		return p->rC;
	else
	{
		while(p && p->rTag == 1)
			p =  p->rC;
		if(p)
			p = p->rC;
	}
	return p;
}