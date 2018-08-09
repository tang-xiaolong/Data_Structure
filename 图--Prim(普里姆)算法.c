#include<stdio.h>
#define maxSize 20
#define Inf 32768
//顶点结构
typedef struct
{
	int no;
	char info;
} VertexType;
//一个图的结构：包括邻接矩阵、顶点集合和边数点数
typedef struct
{
	int edges[maxSize][maxSize];
	int e,n;
	VertexType vex[maxSize];
}MGraph;

void CreateMGraph(MGraph *G);
void Print(MGraph *G);
void Prim(MGraph g,int v0,int *sum);
int main(void)
{
	int sum = 0;
	MGraph G;
	CreateMGraph(&G);
	Print(&G);
	Prim(G,3,&sum);//传入初始的那个顶点，表示从哪个顶点出发
	printf("Prim算法计算得最小生成树代价为：%d\n",sum);
	return 0;
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
		scanf("%d",&G->vex[i].no);
	}
	//循环读入每条边
	for(i = 0;i < G->e;++i)
	{//读入两条边以及他们的权值
		scanf("%d%d%d",&j,&k,&w);
		G->edges[j][k] = w;
		G->edges[k][j] = w;
	}
}

void Print(MGraph *G)
{
	int i = 0,j = 0;
	putchar('\n');
	for(i = 0;i < G->n;++i)
	{
		for(j = 0;j < G->n;++j)
			if(G->edges[i][j] != Inf)
				printf("%4d",G->edges[i][j]);
			else
				printf("%4d",0);
		putchar('\n');
	}
	putchar('\n');
	putchar('\n');
}
void Prim(MGraph g,int v0,int *sum)
{
	int lowcost[maxSize],vest[maxSize],v;
	int i,j,k,min;
	v = v0;
	for(i = 0;i < g.n;++i)
	{
		lowcost[i] = g.edges[v0][i];
		vest[i] = 0;//表示这个节点还未被访问
	}
	vest[v0] = 1;
	printf("%2d",v);
	*sum = 0;
	for(i = 0;i < g.n-1;++i)
	{
		min = Inf;
		//选出候选边中的最小者  从还没被访问过的节点中找到代价最小的
		for(j = 0;j < g.n;++j)
		{
			if(vest[j] == 0 && lowcost[j] < min)
			{
				min = lowcost[j];//更新这个权值
				k = j;//记录最小的那个节点号码
			}
		}
		//这个时候已经选出最小的边了。更新信息
		vest[k] = 1;
		v = k;
		printf("%2d",v);
		*sum += min;
		for(j = 0;j < g.n;++j)
		{//本来和节点j的代价是lowcost  现在计算新加入的节点和j的代价，如果小，更新这个lowcost
			if(vest[j] == 0 && g.edges[v][j] < lowcost[j])
				lowcost[j] = g.edges[v][j];
		}
	}
	putchar('\n');
}
/*
9 14
0 1 2 3 4 5 6 7 8
0 1 10 0 5 11
1 2 18 1 6 16 1 8 12
2 3 22 2 8 8
3 4 20 3 7 16 3 8 21
4 5 26 4 7 7
5 6 17
6 7 19
*/
