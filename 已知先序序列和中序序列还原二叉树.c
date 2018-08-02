#include<stdio.h>
#include<malloc.h>
#define maxSize 7
typedef struct node
{
	char c;
	struct node *lC,*rC;
}Tree,*pTree;

char Pre[maxSize] = "ABDECF";
char Mid[maxSize] = "BDEACF";
int nowIndex = 0;

pTree Creat(pTree tree,char *p2,int l,int r);
int FindIndex(char *p,char c);
void PreTreaverse(pTree p);
int main(void)
{
	Tree tree;
	Creat(&tree,Mid,0,5);//根据已知的两种输出，把二叉树构建出来，并前序输出
	PreTreaverse(&tree);
	putchar('\n');
	return 0;
}

pTree Creat(pTree tree,char *p2,int l,int r)
{
	int i;
	i = FindIndex(p2,Pre[nowIndex]);//找到当前字母在中序中的下标
	tree->c =  Pre[nowIndex];
	if(i > l)//若i比左边界大，则查找当前字母的下一个左孩子
	{
		++nowIndex;
		tree->lC = Creat((pTree)malloc(sizeof(Tree)),p2,l,i-1);
	}
	else//若小，则没有左孩子。右同
		tree->lC = NULL;
	if(i < r)
	{
		++nowIndex;
		tree->rC = Creat((pTree)malloc(sizeof(Tree)),p2,i+1,r);
	}
	else
		tree->rC = NULL;
	return tree;
}

int FindIndex(char *p,char c)
{
	int i = 0;
	while(p[i] != '\0')
		if(p[i] == c)
			return i;
		else
			++i;
	return -1;
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