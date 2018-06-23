#include<stdio.h>
#include<stdlib.h>


typedef struct treeNode
{
	char data;
	struct treeNode * lChild;
	struct treeNode * rChild;
}TreeNode,*pTreeNode;


pTreeNode CreatStaticTree(void);
void PreTraverseTree(pTreeNode );//前序遍历
void MiddleTraverseTree(pTreeNode );//中序遍历
void LastTraverseTree(pTreeNode );//后续遍历

int main(void)
{
	pTreeNode myTree = CreatStaticTree();
	PreTraverseTree(myTree);
	putchar('\n');
	MiddleTraverseTree(myTree);
	putchar('\n');
	LastTraverseTree(myTree);
	putchar('\n');
	return 0;
}


pTreeNode CreatStaticTree()
{
	pTreeNode pA = (pTreeNode)malloc(sizeof(TreeNode));
	pTreeNode pB = (pTreeNode)malloc(sizeof(TreeNode));
	pTreeNode pC = (pTreeNode)malloc(sizeof(TreeNode));
	pTreeNode pD = (pTreeNode)malloc(sizeof(TreeNode));
	pTreeNode pE = (pTreeNode)malloc(sizeof(TreeNode));
	pA->data = 'A';
	pB->data = 'B';
	pC->data = 'C';
	pD->data = 'D';
	pE->data = 'E';
	pA->lChild = pB;
	pA->rChild = pC;
	pB->lChild = pB->rChild = NULL;
	pC->lChild = pD;
	pC->rChild = NULL;
	pD->lChild = NULL;
	pD->rChild = pE;
	pE->lChild = pE->rChild = NULL;
	return pA;
}

void PreTraverseTree(pTreeNode pTree)
{//由于递归非常浪费内存，也很慢，所以在调用之前先判断一次
	if(pTree != NULL)
	{
		printf("%c ",pTree->data);
		if(NULL != pTree->lChild)
			PreTraverseTree(pTree->lChild);
		if(NULL != pTree->rChild)
			PreTraverseTree(pTree->rChild);
		/*
		printf("%c ",pTree->data);
		PreTraverseTree(pTree->lChild);
		PreTraverseTree(pTree->rChild);
		*/
	}

	//先打印根节点，再打印左节点，再打印右节点
	/*
	if(pTree != NULL)
	{
		printf("%c ",pTree->data);
	}
	if(pTree->lChild != NULL)
	{
		PreTraverseTree(pTree->lChild);
	}
	if(pTree->rChild != NULL)
	{
		PreTraverseTree(pTree->rChild);
	}
	*/
}

void MiddleTraverseTree(pTreeNode pTree)
{
	if(pTree != NULL)
	{
		MiddleTraverseTree(pTree->lChild);
		printf("%c ",pTree->data);
		MiddleTraverseTree(pTree->rChild);
	}
	/*
	//先打印左子树，再是中间节点，再是右子树
	if(pTree->lChild != NULL)
	{
		MiddleTraverseTree(pTree->lChild);
	}
	printf("%c ",pTree->data);
	if(pTree->rChild != NULL)
	{
		MiddleTraverseTree(pTree->rChild);
	}
	*/
}

void LastTraverseTree(pTreeNode pTree)
{
	//先左节点，再右节点，再根节点

	if(pTree != NULL)
	{
		LastTraverseTree(pTree->lChild);
		LastTraverseTree(pTree->rChild);
		printf("%c ",pTree->data);
	}
	/*
	if(pTree->lChild != NULL)
	{
		LastTraverseTree(pTree->lChild);
	}
	if(pTree->rChild != NULL)
	{
		LastTraverseTree(pTree->rChild);
	}
	putchar(pTree->data);
	putchar(' ');
	*/
}