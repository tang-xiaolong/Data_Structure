#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	char c;
	struct node *lC,*rC;
}Tree,*pTree;

pTree PreGetValue(pTree p);
int CalculateLeafNum(pTree p);



int main(void)
{
	Tree tree;// ABD##E##CF###
	int count = 0;
	PreGetValue(&tree);
	count = CalculateLeafNum(&tree);
	printf("有%d个叶子节点\n",count);
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
int CalculateLeafNum(pTree p)
{//总叶子节点个数等于左子树叶子节点个数加右子树叶子节点个数
	int l = 0,r = 0;
	if(p == NULL)//如果为空，则个数为0
		return 0;
	else
	{//如果自身左孩子右孩子都没有，则自己为叶节点，返回1  否则，遍历左右孩子  也可以判断不空再遍历，那样注意要初始化为0
		if(p->lC == NULL && p->rC == NULL)
			return 1;
		else
		{
			l = CalculateLeafNum(p->lC);
			r = CalculateLeafNum(p->rC);
		}
	}
	return l+r;
}