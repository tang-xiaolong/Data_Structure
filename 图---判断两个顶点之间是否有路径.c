#include<stdio.h>
#include<malloc.h>
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
//判断两点是否有路径，使用一种方法遍历一次，然后检查visit数组j是否为1
//示例输入：
//5 1 1 2 3 4 5 1 2
int visit[maxSize] = {0};
void CreateAGraph(AGraph *G);//创建无向图
void DFS(AGraph *G,int v);
int main(void)
{
	int i,j;
	AGraph G;
	CreateAGraph(&G);
	scanf("%d%d",&i,&j);
	DFS(&G,i);
	if(visit[j] == 1)
		printf("%d和%d之间有路径\n",i,j);
	else
		printf("%d和%d之间没有路径\n",i,j);
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

void DFS(AGraph *G,int v)
{
	ArcNode *p;
	visit[v] = 1;
	p = G->adjList[v-1].firstArc;
	while(p)
	{
		if(visit[p->adjVex] == 0)
		{
			visit[p->adjVex] = 1;
			DFS(G,p->adjVex);
		}
		p = p->nextArc;
	}
}
