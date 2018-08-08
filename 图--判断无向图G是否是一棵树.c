#include<stdio.h>
#include<malloc.h>
#define maxSize 20
typedef struct ArcNode
{
	int adjVex;
	struct ArcNode *nextArc;
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

//判断是否是树，看边的数目是否是点的数目-1，且为连通图。从顶点开始遍历，计算边的数目。结束后看点是否都已经被访问了
int visit[maxSize] = {0};
void CreateAGraph(AGraph *G);//创建无向图
void DFSTreaverse(AGraph *G,int v,int *n,int *e);
int IsTree(AGraph *G);
//  7 9 1 2 3 4 5 6 7 1 2 1 3 1 4 2 4 3 4 3 5 4 6 5 6 6 7
int main(void)
{
	AGraph G;
	int flag = 0;
	CreateAGraph(&G);
	flag = IsTree(&G);
	if(flag)
		printf(" 这个图是一棵树\n");
	else
		printf(" 这个图不是一棵树\n");
	return 0;
}

void CreateAGraph(AGraph *G)
{
	int i,j,k;
	ArcNode *p;
	scanf("%d%d",&G->n,&G->e);
	for(i = 0;i < G->n;++i)
	{
		//读入邻接表顶点信息，并初始化
		scanf("%d",&G->adjList[i].data);
		G->adjList[i].firstArc = NULL;
	}
	for(i = 0;i < G->e;++i)
	{
		scanf("%d%d",&j,&k);
		//表示j和k相邻
		p = (ArcNode *)malloc(sizeof(ArcNode));
		p->adjVex = k;
		p->nextArc = G->adjList[j-1].firstArc;
		G->adjList[j-1].firstArc = p;

		p = (ArcNode *)malloc(sizeof(ArcNode));
		p->adjVex = j;
		p->nextArc = G->adjList[k-1].firstArc;
		G->adjList[k-1].firstArc = p;
	}
}

void DFSTreaverse(AGraph *G,int v,int *n,int *e)
{
	ArcNode *p;
	visit[v-1] = 1;
	*n = *n+1;
	printf("%d",v);
	p = G->adjList[v-1].firstArc;
	while(p != NULL)
	{
		*e = *e+1;//只要不为NULL  边数就增加1 这样当前节点和已经被走过的节点之间的边也会计算进去，用邻接表更容易理解  即每个顶点后面的每条边我都加一次，在最后除以2就是了
		if(visit[p->adjVex-1] == 0)
		{	
			DFSTreaverse(G,p->adjVex,n,e);
		}
		p = p->nextArc;
	}
}
int IsTree(AGraph *G)
{
	int n = 0,e =  0;
	DFSTreaverse(G,G->adjList[0].data,&n,&e);
	if(n == G->n && e/2 == G->n-1)  //若所有顶点都被访问到了，且边数等于顶点数减1  则是一棵树
		return 1;
	else
		return 0;
}
