//示例输入：1246##7##58##9##3##
//2018年12月17日 16:53:45
//要求：找到二叉树中两个节点最近的那个祖先
#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	char data;
	struct node *lchild;
	struct node *rchild;
}NODE;
NODE *Create();//先序创建树
void ANCESTOR(NODE *root,NODE *p,NODE *q,NODE *r);//找公共祖先的调用函数
int Pre(NODE *root,NODE *p,NODE *q,NODE **r,NODE *r1,NODE *r2);//通过先序找最近的公共祖先
NODE *GetNode(NODE *root,char c);//输入一个值得到对应的节点
void Destroy(NODE **root);//销毁二叉树

int main(void)
{
	NODE *bt = NULL;
	NODE *p,*q;
	NODE r;
	bt = Create();
	//获取p和q   可以手动输入并做安全检查   这里省略了
	p = GetNode(bt,'6');
	q = GetNode(bt,'8');
	ANCESTOR(bt,p,q,&r);
	Destroy(&bt);
	//ANCESTOR(bt,p,q,&r);
	return 0;
}
int Pre(NODE *root,NODE *p,NODE *q,NODE **r,NODE *r1,NODE *r2)
{
	int flag1 = -1,flag2 = -1;
	int f = 0;
	if(root)
	{
		if(root->data == p->data)//当前节点是p,回头如果没匹配成功，返回1，表示要更新r1
			f = 1;
		else if(root->data == q->data)//当前节点是q,回头如果没匹配成功，返回2，表示要更新r2
			f = 2;
		//如果左子树找到的是0,直接查找右子树；左右子树各找到一个，那么就意味着找到了公共祖先，即root，直接返回4 
		//得到的是1，则说明找到了p,但是未满足条件，把r1设为root
		//得到的是2，则说明找到了q,但是未满足条件；把r2设为root
		//得到的是4，说明已经找到了公共祖先，成功了，直接返回4
		flag1 = Pre(root->lchild,p,q,r,r1,r2);//遍历左子树看是不是能够得到结果
		if(flag1 == 4)//表示成功找到
			return 4;
		else if(flag1 == 1)
			r1 = root;
		else if(flag1 == 2)
			r2 = root;
		flag2 = Pre(root->rchild,p,q,r,r1,r2);
		if(flag2 == 4)
			return 4;
		else if(flag2 == 1)
			r1 = root;
		else if(flag2 == 2)
			r2 = root;
		//如果左右子树都遍历完了，但是不满足：看flag1和flag2 ，它们标志着返回后哪个r需要修改，或者都不需要改，返回f
		if(r1 != NULL && r1 == r2)//r1 和 r2 不为NULL，且相等
		{
			*r = r1;//更新*r，直接返回4
			return 4;
		}
		else if(flag1)//如果有一个不为空，那么返回它
			return flag1;
		else if(flag2)
			return flag2;
	}
	return f;
}
void ANCESTOR(NODE *root,NODE *p,NODE *q,NODE *r)
{
	int id = 0;
	if(!root)
		return;
	id = Pre(root,p,q,&r,NULL,NULL);
	if(id == 4)//找到了
		if(r)
			printf("公共祖先是节点%c\n",r->data);
}
NODE *GetNode(NODE *root,char c)
{
	NODE *p = NULL;
	if(root)
	{
		if(root->data == c)
			return root;
		p = GetNode(root->lchild,c);
		if(p)
			return p;
		p = GetNode(root->rchild,c);
	}
	return p;
}
NODE *Create()
{
	char ch;
	NODE *bt;
	ch = getchar();
	if(ch != '#')
	{
		bt = (NODE *)malloc(sizeof(NODE));
		bt->data = ch;
		bt->lchild = Create();
		bt->rchild = Create();
	}
	else
		return NULL;
	return bt;
}
void Destroy(NODE **root)//之所以采用双重指针这么麻烦，是为了在销毁后把原来的值设为NULL，否则再次运行会出现问题
{
	if(*root)
	{
		Destroy(&(*root)->lchild);
		Destroy(&(*root)->rchild);
		free((*root));
		*root = NULL;
	}
}
