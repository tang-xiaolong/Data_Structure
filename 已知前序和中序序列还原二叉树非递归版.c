#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *lc;
	struct node *rc;
}Node;

int GetIndex(int *a,int value);
void MidTreaver(Node *p);
Node *GetTree(int *pre,int *mid,int l,int r);

int main(void)
{
	int begin = 0,end = 5;
	int Pre[] = {13,9,11,10,12,35};//{12,9,7,11,35,21,54,43};
	int Mid[] = {9,10,11,12,13,35};//{7,9,11,12,21,35,43,54};
	Node *p = NULL;
	p = GetTree(Pre,Mid,begin,end);
	MidTreaver(p);
	putchar('\n');
	return 0;
}

void MidTreaver(Node *p)
{
	Node *t;
	Node *stack[20];
	int top = -1;
	t = p;
	while(top != -1 || t != NULL)
	{
		while(t)//一直把左孩子压进去。
		{
			stack[++top] = t;
			t = t->lc;
		}
		if(top != -1)//没有左孩子了，出一个访问，访问后换成右孩子  否则就死循环了
		{
			t = stack[top--];
			printf("%3d",t->data);
			t = t->rc;
		}
	}
}
int GetIndex(int *a,int value)
{
	//首先保证了这个值肯定存在于这个数组里，且数组的值均不同
	int i = 0;
	while(a[i] != value)
		++i;
	return i;
}
Node *GetTree(int *pre,int *mid,int l,int r)
{
	Node *Stack[20];
	int left[20],right[20];
	int top1,top2,top3;
	int k,now = 0,flag = 1;//now记录前序中读取到的下标  
	Node *temp,*root;
	top1 = top2 = top3 = -1;
	//每次把当前生成的节点与当前求的k r存入栈中，生成结束后再取出来
	//先求一个k存进去
	do
	{
		do
		{
			k = GetIndex(mid,pre[now]);//获取当前数字在中序中的下标
			temp = (Node *)malloc(sizeof(Node));
			temp->data = pre[now];
			if(now == 0)//如果是根，则保存起来
				root = temp;
			if(top1 != -1 && flag == 1)//栈不为空，在那个里面有节点，我自己作为它的左子树根节点，应该连上
				Stack[top1]->lc = temp;
			else if(flag == 2)//证明这个temp是栈顶节点的右子树，所以把这个栈顶右孩子指向temp，并把栈顶节点出栈
				Stack[top1--]->rc = temp,top2--,top3--;
			
			//管你右有没有，右先入，并把当前的这个temp放进去
			Stack[++top1] = temp;
			left[++top2] = k;
			right[++top3] = r;
			if(l < k)//左子树还有
				//更新r和now
				++now,r = k - 1,flag = 1;
			else
				//这个temp是最后一个左子树节点了，把temp的左子树置空
				temp->lc = NULL;
		}while(l < k);//跳出来的时候就证明左子树空了
		
		//从里面取一个元素出来，看有没有右子树
		//判断栈顶是否有右子树，如果没有，置空退栈继续判断，直到有或者是栈空
		while(top2 != -1 && left[top2] >= right[top3])//右子树没东西了,把这个节点退栈,直到有一个节点是有右子树的，或者结束
		{
			Stack[top1--]->rc = NULL;
			--top2;
			--top3;
		}
		if(left[top2] < right[top3])//now+1的位置的节点值将是它的右子树
		{
			++now;
			l = left[top2]+1;//把栈里的数取出来作为新的左和右，并修改标志
			r = right[top3];
			flag = 2;
		}
	}while(top2 != -1);
	return root;
}
