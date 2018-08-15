#include<stdio.h>
#include<malloc.h>
#define maxSize 30
#define Inf 32768

typedef struct ArcNode
{
	int adjVex;
	struct ArcNode *nextArc;
	int w;
}ArcNode;
typedef struct 
{
	int data;
	ArcNode *firstArc;
}VNode;

typedef struct 
{
	VNode adjList[maxSize];
	int n,e;
}AGraph;


void CreateAGraph(AGraph *G);
void DFS1(AGraph *G,int v);//方法一   好理解一些，但是会破环原本的顺序
void DFS2(AGraph *G,int v);//会按照邻接表的顺序输出，更合适
int main(void)
{
	AGraph G;
	CreateAGraph(&G);
	DFS1(&G,0);
	putchar('\n');
	DFS2(&G,0);
	putchar('\n');
	return 0;
}

void CreateAGraph(AGraph *G)
{
	int i,j,k,w;
	ArcNode *p;
	scanf("%d%d",&G->n,&G->e);
	for(i = 0;i < G->n;++i)
	{
		G->adjList[i].data = i;
		G->adjList[i].firstArc = NULL;
	}

	for(i = 0;i < G->e;++i)
	{
		scanf("%d%d%d",&j,&k,&w);
		p = (ArcNode *)malloc(sizeof(ArcNode));
		p->adjVex = k;
		p->w = w;
		p->nextArc = G->adjList[j].firstArc;
		G->adjList[j].firstArc = p;
	}
}

void DFS1(AGraph *G,int v)
{
	int set[maxSize] = {0};
	int stack[maxSize];
	int top = -1,i;
	ArcNode *p;
	stack[++top] = v;
	set[v] = 1;
	while(top != -1)
	{
		i = stack[top--];
		printf("%2d",i);
		p = G->adjList[i].firstArc;
		while(p)
		{
			if(set[p->adjVex] == 0)
			{
				set[p->adjVex] = 1;
				stack[++top] = p->adjVex;
			}
			p = p->nextArc;
		}
	}
}
void DFS2(AGraph *G,int v)
{
	int set[maxSize] = {0};
	int stack[maxSize];
	int top = -1,i;
	ArcNode *p;
	stack[++top] = v;
	set[v] = 1;
	printf("%2d",v);
	while(top != -1)
	{
		i = stack[top];//只读不取，后面检验了自己连接的节点都访问了再取
		p = G->adjList[i].firstArc;
		while(p != NULL && set[p->adjVex] == 1)//一直往后找，找到空节点或者是一个没有被访问的节点
			p = p->nextArc;
		if(p == NULL)//如果p已经到了末尾了，证明当前的那个节点所连接的节点都被访问过了
			--top;
		else
		{//这是一个未被访问过的节点  入栈  标记  并访问
			stack[++top] = p->adjVex;
			set[p->adjVex] = 1;
			printf("%2d",p->adjVex);
		}
	}
}

/*
9 14
0 1 10 0 5 11
1 2 18 1 6 16 1 8 12
2 3 22 2 8 8
3 4 20 3 7 16 3 8 21
4 5 26 4 7 7
5 6 17
6 7 19
*/
