#include<stdio.h>
#include<malloc.h>
#define maxSize 5
typedef struct node
{
	int data;
	struct node *lC,*rC,*parent;
}Tree,*pTree;

int Find(int *,int *,int *);
int IsOver(int *);
pTree Creat(pTree p,int *num);
void PreTreaverse(pTree p);
int GetValue(pTree p);


int main(void)
{
	int num[maxSize] = {2,5,7,9,13},sum = 0;
	Tree tree;
	Creat(&tree,num);
	PreTreaverse(&tree);
	putchar('\n');
	sum = GetValue(&tree);
	printf("带权路径长度为：%d\n",sum);
	return 0;
}

int Find(int *num,int *a,int *b)
{
	int i = 0,j = 32768,k = 32768;
	*a = *b = -1;
	for(i = 0;i < maxSize;++i)
	{
		//找到最小的放到a里，第二小的放到b里，如果
		if(num[i] != 32768)
		{
			if(num[i] <= j)
			{
				*b = *a;
				*a = i;
				k = j;
				j = num[i];
			}
			else if(num[i] <= k)
			{
				*b = i;
				k = num[i];
			}
		}
	}
	return 1; 
}
int IsOver(int *num)
{
	//判断是否已经找完了。有两个以上则需要继续组合,如果只有一个了，直接返回它的下标
	int i = 0,flag = -1;
	for(i = 0;i < maxSize;++i)
		if(num[i] != 32768)
			if(flag == -1)
				flag = i;
			else
				return maxSize+1;
	if(flag != -1)
		return flag;
	else
		return -1;
}
pTree Creat(pTree p,int *num)
{
	pTree p1,p2,p3;
	int temp = IsOver(num);
	pTree flag[maxSize] = {NULL};
	int a = 0,b = 0;
	//当不满足这个的时候，证明此时数组里只剩最后一个节点了，那这个节点就是最后的根节点
	while(temp == maxSize + 1)
	{
		//还需要继续组合
		Find(num,&a,&b);
		//创建三个节点，两个存原本的值，一个存组合节点的值。并将数组的值修改一下
		//若对应位置上已经有节点了，就不创建了，直接等于
		p1 = (pTree)malloc(sizeof(Tree));
		if(flag[a] != NULL)//对应的那个数组里已经存在了（即为合成的节点），就直接拿出来用，否则重新生成一个
			p2 = flag[a];
		else
		{
			p2 = (pTree)malloc(sizeof(Tree));
			p2->lC = p2->rC = NULL;
			flag[a] =  p1;
		}
		if(flag[b] != NULL)
			p3 = flag[b];
		else
		{
			p3 = (pTree)malloc(sizeof(Tree));
			p3->lC = p3->rC = NULL;//若为新构造的叶子节点，才需要把左右指针域赋NULL  这里刚开始就没注意，全给赋NULL了
			flag[b] = p1;
		}
		//更新节点数据
		p2->data = num[a];
		p2->parent = p1;
		p3->data = num[b];
		
		p3->parent = p1;
		p1->data = num[a]+num[b];
		p1->lC = p2;
		p1->rC = p3;
		p1->parent = NULL;
		num[a] = p1->data;
		num[b] = 32768;
		temp = IsOver(num);
	}
	//此时temp保存着最后一个根节点的下标，flag[temp]则保存着那个节点的信息，我们将真正的根节点换过来
	p->data = p1->data;
	p->lC = p1->lC;
	p->rC = p1->rC;
	p->parent = NULL;
	free(p1);
	return p;
}
void PreTreaverse(pTree p)
{
	if(p)
	{
		printf("%3d",p->data);
		PreTreaverse(p->lC);
		PreTreaverse(p->rC);
	}
}

int GetValue(pTree p)
{//层次遍历，是叶子节点就让它乘以（当前层数-1）
	int sum = 0;
	pTree queue[3*maxSize],lastNode = p,temp = p;
	int front = 0,rear = 0;
	int nowCeil = 1;
	if(temp == NULL)
		return 0;
	queue[rear++] = temp;
	while(rear != front)
	{
		temp = queue[front++];//每次取出一个
		if(temp->lC == NULL && temp->rC == NULL)//如果是叶子节点了，直接把自己的权值乘以（路径长度减一）
			sum = sum + temp->data*(nowCeil-1);
		if(temp->lC)
		{
			queue[rear++] = temp->lC;
		}
		if(temp->rC)
		{
			queue[rear++] = temp->rC;
		}
		if(temp == lastNode)//当找到当前层的最后一个元素时，更新层数，并使得新的最后元素指向队列尾部
		{
			nowCeil++;
			lastNode = queue[rear-1];
		}
	}
	return sum;
}