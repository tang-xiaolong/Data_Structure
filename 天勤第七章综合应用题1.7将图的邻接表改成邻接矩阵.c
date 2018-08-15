#include<stdio.h>
#include<malloc.h>
#define maxSize 20
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
	int e,n;
}AGraph;


typedef struct 
{
	int data;
}vertexType;

typedef struct
{
	vertexType vex[maxSize];
	int edges[maxSize][maxSize];
	int n,e;
}MGraph;


void CreateAGraph(AGraph *G);
void CreateMGraph(MGraph *G);
void Conversion(AGraph *AG,MGraph *MG);
void DFS(MGraph *MG,int v);

int main(void)
{
	AGraph AG;
	MGraph MG;
	CreateAGraph(&AG);
	Conversion(&AG,&MG);
	DFS(&MG,0);
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
		//scanf("%d",&G->adjList[i].data);//输入顶点标号
		G->adjList[i].firstArc = NULL;//让他们指向的边置空
	}
	//处理边
	for(i = 0;i < G->e;++i)
	{
		scanf("%d%d%d",&j,&k,&w);
		//j到k权值为w
		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->w = w;//权值
		p->adjVex = k;
		p->nextArc = G->adjList[j].firstArc;
		G->adjList[j].firstArc = p;
	}
}

void CreateMGraph(MGraph *G)
{
	int i,j,k,w;
	scanf("%d%d",&G->n,&G->e);//读入G的边数和点数
	//初始化邻接矩阵
	for(i = 0;i < G->n;++i)
		for(j = 0;j < G->n;++j)
		{
			G->edges[i][j] = Inf;
		}
	//循环读入每个点的信息
	for(i = 0;i < G->n;++i)
	{
		scanf("%d",&G->vex[i].data);
	}
	//循环读入每条边
	for(i = 0;i < G->e;++i)
	{//读入两条边以及他们的权值
		scanf("%d%d%d",&j,&k,&w);
		G->edges[j][k] = w;
		G->edges[k][j] = w;
	}
}

void Conversion(AGraph *AG,MGraph *MG)
{
	//将一个以邻接表方式存储的图用邻接矩阵存
	int i = 0,k;
	ArcNode *p;
	MG->n = AG->n;
	MG->e = AG->e;
	for(i = 0;i < AG->n;++i)
		MG->vex[i].data = AG->adjList[i].data;
	for(i = 0;i < MG->n;++i)//初始化权值数组
		for(k = 0;k < MG->n;++k)
			MG->edges[i][k] = Inf;
	for(i = 0;i < AG->n;++i)
	{
		p = AG->adjList[i].firstArc;
		while(p)
		{
			k = p->adjVex;//取得顶点编号
			MG->edges[i][k] = p->w;//取得权值
			p = p->nextArc;
		}
	}
}
void DFS(MGraph *MG,int v)
{
	int set[maxSize] = {0};
	int stack[maxSize];
	int top = -1,n,j = 0;
	set[v] = 1;
	stack[++top] = v;
	while(top != -1)
	{
		n = stack[top--];
		printf("%2d",n);
		for(j = 0;j < MG->n;++j)
		{
			if(set[j] == 0 && MG->edges[n][j]  != Inf)
			{
				set[j] = 1;
				stack[++top] = j;
			}
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
