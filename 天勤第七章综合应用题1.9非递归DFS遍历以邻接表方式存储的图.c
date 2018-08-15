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
void DFS(AGraph *G,int v);
int main(void)
{
	AGraph G;
	CreateAGraph(&G);
	DFS(&G,0);
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

void DFS(AGraph *G,int v)
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
