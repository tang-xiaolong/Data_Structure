#include<stdio.h>
#define maxSize 30
#define Inf 32768
typedef struct vertex //顶点定义
{
	int no;//顶点编号
	char info;//顶点信息
}VertexType;

typedef struct graph
{
	int edges[maxSize][maxSize];	//邻接矩阵定义
	int n,e;//顶点数和边数
	VertexType vex[maxSize];//存放顶点信息
}MGraph;



int visit1[maxSize] = {0};
int visit2[maxSize] = {0};
void CreateMGraph(MGraph * G);//创建无向图
void DFS1(MGraph *G,int id);//深度优先遍历
void DFSNotConnect(MGraph *G);
void DFS2(MGraph *G);
void BFS(MGraph *G);
//7 9 1 2 3 4 5 6 7 1 2 1 3 1 4 2 4 3 4 3 5 4 6 5 6 6 7
int main(void)
{
	MGraph G;
	CreateMGraph(&G);
	DFSNotConnect(&G);
	putchar('\n');
	DFS2(&G);
	putchar('\n');
	BFS(&G);
	putchar('\n');
	return 0;
}

void CreateMGraph(MGraph * G)
{
	int i,j,k,w;
	//printf("请输入顶点数和边数：");
	scanf("%d%d",&(G->n),&G->e);
	for(i = 0;i < G->n;++i)//输入顶点信息
		scanf("%d",&G->vex[i].no);
	for(i = 0;i < G->n;++i)//邻接矩阵初始化
		for(j = 0;j < G->n;++j)
			G->edges[i][j] = Inf;
	for(k = 0;k < G->e;++k)//读入n条边及他们的权值
	{
		//printf("请输入边（Vi,Vj）的下标i、下标j和权：");
		//scanf("%d%d%d",&i,&j,&w);
		scanf("%d%d",&i,&j);
		G->edges[i-1][j-1] = 1;
		G->edges[j-1][i-1] = 1;
		//G->edges[i][j] = w;
		//G->edges[j][i] = w;
	}
}
void DFS1(MGraph *G,int id)//深度优先遍历
{
	int j = 0;
	printf("%d",id+1);
	visit1[id] = 1;
	for(j =  0;j < G->n;++j)
	{
		if(G->edges[id][j] == 1 && visit1[j] == 0)
			DFS1(G,j);
	}
}
void DFSNotConnect(MGraph *G)
{
	int i = 0;
	for(i = 0;i < G->n;++i)
		visit1[i] = 0;
	for(i = 0;i < G->n;++i)
		if(visit1[i] == 0)
			DFS1(G,i);
}

void DFS2(MGraph *G)
{
	int stack[maxSize];
	int top = -1;
	int i = 0,j = 0;
	int now = 0;
	for(i = 0;i < G->n;++i)
		visit1[i] = 0;
	stack[++top] = G->vex[0].no;
	
	while(top != -1)
	{
		now = stack[top--];
		visit1[G->vex[now-1].no] = 1;
		for(i = 0;i < G->n;++i)
		{
			if(G->edges[now][i] == 1 && visit1[i+1] == 0)
			{
				visit1[i+1] = 1;
				stack[++top] = i+1;
			}
		}
		printf("%d",now);
	}
}
void BFS(MGraph *G)
{
	int queue[maxSize];
	int n,f;
	int i,now;
	n = 0,f = 0;
	queue[n] = G->vex[0].no;//入队一个
	n =  (n+1)%maxSize;
	while(n != f)
	{
		now = queue[f];
		f = (f+1)%maxSize;
		visit2[now] = 1;
		for(i = 0;i < G->n;++i)
		{
			if(G->edges[now-1][i] == 1 && visit2[i+1] == 0)
			{
				visit2[i+1] = 1;
				queue[n] = i+1;
				n =  (n+1)%maxSize;
			}
		}
		printf("%d",now);
	}
}
