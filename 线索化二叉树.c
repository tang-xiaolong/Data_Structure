#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	char c;
	int lTag,rTag;
	struct node *lC,*rC;
}Tree,*pTree;
#define maxSize 50
pTree Pre = NULL;

void Init(pTree p);
pTree PreGetValue(pTree p);
void LastPrint(pTree p);


void MidLine(pTree);//递归中序线索化
void MidLines(pTree);//封装了递归中序线索化方法，并完善了递归到最后的那个指针
void MidLinePrint1(pTree);//中序线索树输出方法1。
void MidLinePrint2(pTree);//中序线索树输出方法2。


void PreLineZiXie(pTree);//自己尝试写的
void PreLine(pTree);//参考书的
void PreLines(pTree);//封装了自己写的。
void PreLinePrint(pTree);//前序线索树输出

void LastLine(pTree);
void LastLinePrint(pTree);
pTree GetNext(pTree,pTree);
pTree FindPar(pTree,pTree);


int main(void)
{// ABD##E##CF###
	Tree tree;
	Init(&tree);
	PreGetValue(&tree);
	LastPrint(&tree);//后序输出检验二叉树构造的正确性
	putchar('\n');

	//中序线索化
	//MidLines(&tree);
	//putchar('\n');
	//MidLinePrint1(&tree);
	//putchar('\n');
	//MidLinePrint2(&tree);
	//putchar('\n');

	//前序线索化
	//PreLine(&tree);   //PreLines(&tree);  //或者用后面这种方法
	//PreLinePrint(&tree);
	//putchar('\n');

	LastLine(&tree);
	//printf("%c",FindPar(&tree,(&tree)->lC->lC)->c);
	LastLinePrint(&tree);
	return 0;
}
void Init(pTree p)
{
	p->c = '\0';
	p->lC = p->rC = NULL;
	p->lTag = p->rTag = 0;
}

pTree PreGetValue(pTree p)
{
	char c;
	pTree temp;
	c = getchar();
	if(c != '#')
	{
		p->lTag = p->rTag = 0;
		p->c = c;
		temp = (pTree)malloc(sizeof(Tree));
		p->lC = PreGetValue(temp);
		temp = (pTree)malloc(sizeof(Tree));
		p->rC = PreGetValue(temp);
	}
	else
		p = NULL;
	return p;
}

void LastPrint(pTree p)
{
	pTree A[maxSize];
	int top = -1;
	int B[maxSize] = {0};
	while(p != NULL || top != -1)
	{
		while(p)
		{
			A[++top] = p;
			B[top] = 0;
			p = p->lC;
		}
		if(top != -1)
		{
			p = A[top];
			if(B[top] == 0)
			{
				B[top] = 1;
				p = p->rC;
			}
			else if(B[top] == 1)
			{
				top--;
				putchar(p->c);
				p = NULL;
			}
			
		}
	}
}

void MidLine(pTree p)
{
	if(p != NULL)
	{
		MidLine(p->lC);
		if(p->lC == NULL)
		{
			p->lTag = 1;
			p->lC = Pre;
		}
		if(Pre != NULL && Pre->rC == NULL)
		{
			Pre->rC = p;
			Pre->rTag = 1;
		}
		Pre = p;
		putchar(p->c);
		MidLine(p->rC);
	}
}
void MidLines(pTree p)
{
	if(p)
	{
		MidLine(p);//线索化完成后，处理一下最后一个节点
		Pre->rTag = 1;
		Pre->rC =  NULL;
	}
}
void MidLinePrint1(pTree p)
{
	while(p)
	{//碰到左节点指向的是孩子，则继续查找，知道找到那个不是孩子的，此时自己为要输出的节点
		while(p->lTag == 0)
			p = p->lC;
		putchar(p->c);//如果自己的右孩子是指向直接后继的，则输出并直接转换成直接后继.当自己右边是指向孩子的时候，跳出去，并更新p
		while(p->rTag == 1 && p->rC != NULL)
		{
			p = p->rC;
			putchar(p->c);
		}
		p = p->rC;	//回头继续往自己最左边走
	}
}
void MidLinePrint2(pTree p)
{
	if(!p)
		return ;
	while(p->lTag == 0)//获得第一个要输出的节点
		p = p->lC;
	while(p)
	{
		putchar(p->c);//输出当前节点的值。
		if(p->rTag == 1)//如果是指向直接后继，直接更新就是了
			p = p->rC;
		else//如果不是，找到最左边
		{
			p = p->rC;
			while(p->lTag == 0)
				p = p->lC;
		}
	}
}
//自己写的前序线索化递归程序
void PreLineZiXie(pTree p)
{
	if(p)
	{
		if(p->lC != NULL)
		{
			if(Pre != NULL && Pre->rC == NULL)
			{
				Pre->rTag  = 1;
				Pre->rC = p;
			}
			Pre =  p;
			p->lTag = 0;
			PreLineZiXie(p->lC);			
		}
		else
		{
			p->lC = Pre;
			p->lTag = 1;
			if(Pre != NULL && Pre->rC == NULL)
			{
				Pre->rTag = 1;
				Pre->rC = p;
			}
			Pre = p;	
		}
		if(p->rTag == 0 && p->rC != NULL)
		{
			p->rTag =  0;
			PreLineZiXie(p->rC);
		}
		else
		{
			if(p->lTag == 0)
			{
				p->rC = p->lC;
				p->rTag = 0;
			}
		}
	}
}
void PreLine(pTree p)
{
	if(p)
	{
		if(p->lC == NULL)
		{
			p->lTag = 1;
			p->lC = Pre;
		}//链接上前后节点
		if(Pre != NULL && Pre->rC == NULL)
		{
			Pre->rC = p;
			Pre->rTag = 1;
		}
		Pre = p;
		if(p->lTag != 1)
			PreLine(p->lC);
		if(p->rTag != 1)
			PreLine(p->rC);
	}
}
void PreLines(pTree p)
{
	if(p)
	{
		PreLineZiXie(p);
		Pre->rTag = 1;
		Pre->rC = NULL;
	}
}
void PreLinePrint(pTree p)
{
	while(p)
	{
		putchar(p->c);
		while(p->lTag == 0)
		{
			p = p->lC;
			putchar(p->c);
		}
		p = p->rC;
	}
}

void LastLine(pTree p)
{
	if(p)
	{
		LastLine(p->lC);
		LastLine(p->rC);
		//putchar(p->c);
		if(p->lC == NULL)
		{
			p->lC = Pre;
			p->lTag = 1;
		}
		if(Pre != NULL && Pre->rC == NULL)
		{
			Pre->rC = p;
			Pre->rTag = 1;
		}
		Pre = p;
	}
}
pTree GetNext(pTree p1,pTree p2)
{
	pTree temp;
	if(p1 == p2)//是根节点，没有直接后继
		return NULL;
	else
	{
		if(p2->rTag == 1)
			return p2->rC;
		//找到父节点  判断有没有右子树
		temp = FindPar(p1,p2);
		if(temp != NULL && temp->rC == NULL)
			;
		else if(temp != NULL && temp->rC != NULL)//父节点有右子树，找到右子树里最左下的那一个节点
		{
			temp = temp->rC;//如果左边还有，就继续
			while(temp->lTag == 0)
				temp =  temp->lC;
		}
		return temp;
	}
}
pTree FindPar(pTree p,pTree p2)
{
	pTree temp = NULL;
	if(p)
	{
		if(p->lTag == 0 && p->lC == p2)
		{
			temp = p;
		}
		if(temp != NULL)
			return temp;
		if(p->lTag == 0)
			temp = FindPar(p->lC,p2);
		if(p->rTag == 0)
			if(temp == NULL)
				FindPar(p->rC,p2);
	}
	return temp;
}
void LastLinePrint(pTree p)
{
	pTree temp = p;
	while(temp->lTag == 0)
			temp = temp->lC;
	while(temp)
	{
		putchar(temp->c);
		temp = GetNext(p,temp);
	}
}
