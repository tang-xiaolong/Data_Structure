#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	char c;
	struct node *lC,*rC;
}Tree,*pTree;
typedef struct buttom
{
	pTree value;
	int ceng;
}Buttom;
void Init(pTree);
pTree PreGetValue(pTree);
void PreTreaverse(pTree);
int GetWeigth(pTree);
int main(void)
{
	int weigth = 0;
	Tree tree;
	Init(&tree);
	PreGetValue(&tree);
	//PreTreaverse(&tree);
	//putchar('\n');
	puts("层次遍历结果如下");
	weigth = GetWeigth(&tree);
	printf("\n这棵树宽度为：%d\n",weigth);
	return 0;
}

void Init(pTree p)
{
	p = (pTree)malloc(sizeof(Tree));
	p->c = '\0';
	p->lC = p->rC = NULL;
}
pTree PreGetValue(pTree p)
{
	char c;
	c = getchar();
	if(c != '#')
	{
		p->c = c;//ABD##E##CF###
		p->lC = (pTree)malloc(sizeof(Tree));
		p->rC = (pTree)malloc(sizeof(Tree));
		//printf("%x  %x  %x\n",p,p->lC,p->rC);
		p->lC = PreGetValue(p->lC);
		p->rC = PreGetValue(p->rC);
	}
	else
	{
		free(p);
		p = NULL;
	}
	return p;
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
int GetWeigth(pTree p)
{
	Buttom array[100];
	int rear = 0,front = 0;
	int nowCeng,count = 0,i,k = 0,max = -1;
	array[rear].value = p;
	array[rear].ceng = 1;
	++rear;
	while(front != rear)
	{
		//取出自己，将孩子入栈，并设置它们的层
		p = array[front].value;
		nowCeng = array[front].ceng;
		++front;
		++count;
		printf("%c",p->c);
		if(p->lC)
		{
			array[rear].value = p->lC;
			array[rear].ceng = nowCeng+1;
			++rear;
		}
		if(p->rC)
		{
			array[rear].value = p->rC;
			array[rear].ceng = nowCeng+1;
			++rear;
		}
	}
	nowCeng = array[0].ceng;
	k = 0;
	for(i = 0;i < count;++i)
	{
		if(array[i].ceng == nowCeng)
		{//如果这个层次和之前的层次相同，k++
			++k;
		}
		else
		{//如果不同，把k置一，并更新nowceng
			k = 1;
			nowCeng = array[i].ceng;
		}
		if(k > max)
			max = k;
	}
	return max;
}
//示例输入
/*
ABD##E##CF###
层次遍历结果如下
ABCDEF
这棵树宽度为：3
Press any key to continue
*/
