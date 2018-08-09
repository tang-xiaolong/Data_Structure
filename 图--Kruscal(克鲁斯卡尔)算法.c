#include<stdio.h>
#define maxSize 30
#define Inf 32768
typedef struct
{
	int no;
	char info;
}VertexType;
typedef struct
{
	int edges[maxSize][maxSize];
	int n,e;
	VertexType vex[maxSize];
}MGraph;

typedef struct 
{
	int a,b;	//a和b为一条边的两个顶点
	int w;		//边的权值
}Road;

Road road[maxSize];
int v[maxSize];//并查集数组

int GetRoot(int a);
void CreateMGraph(MGraph *G);
void InitRoad(MGraph *G,Road *road);
void sort(Road *road,int E);
void swap(int *a,int *b);
void Kruskal(MGraph G,int *sum,Road road[]);
int main(void)
{
	int sum = 0;
	MGraph G;
	CreateMGraph(&G);
	InitRoad(&G,road);
	Kruskal(G,&sum,road);
	printf("Kruskal算法计算得最小生成树代价为：%d\n",sum);
	return 0;
}
int GetRoot(int a)
{
	while(a != v[a])
		a = v[a];
	return a;
}

void CreateMGraph(MGraph *G)
{

	int i,j,k,w;
	scanf("%d%d",&G->n,&G->e);
	//初始化顶点
	for(i = 0;i < G->n;++i)
		scanf("%d",&G->vex[i].no);
	//初始化邻接矩阵
	for(i = 0;i < G->n;++i)
		for( j = 0;j < G->n;++j)
			G->edges[i][j] = Inf;
	//输入边
	for(i = 0;i < G->e;++i)
	{
		scanf("%d%d%d",&j,&k,&w);
		G->edges[j][k] = w;
		G->edges[k][j] = w;
	}
}
void InitRoad(MGraph *G,Road *road)
{
	//对存在边的两个顶点进行记录  循环只需要循环一半就可以了
	int i,j,k = 0;
	//初始化road数组
	for(i = 0;i < maxSize;++i)
		road[i].w = Inf;
	for(i = 0;i < G->n;++i)
	{
		for(j = i+1;j < G->n;++j)
			if(G->edges[i][j] != Inf)//有路径
			{
				road[k].a =  i;
				road[k].b = j;
				road[k++].w = G->edges[i][j]; 
			}
	}
}

void Kruskal(MGraph g,int *sum,Road road[])
{
	int i;
	int N,E,a,b;
	N = g.n;
	E = g.e;
	*sum = 0;
	for(i = 0;i < N;++i)
		v[i] = i;//先让并查集里每个节点都指向自己
	sort(road,E);//先让这个权值边数组排好序
	for(i = 0;i < E;++i)
	{
		a = GetRoot(road[i].a);
		b = GetRoot(road[i].b);
		//依次取出一个边，判断这里是否在同一个集合里  即根是否相同。  本来都是指向自己的，慢慢的会组合到一起
		if(a != b)
		{
			v[a] = b;//更新并查集里的节点信息，让这个点不再指向自己，而是指向那个和自己共边的点
			*sum += road[i].w;
		}
	}
}
void sort(Road *road,int E)
{
	//从小到大排序
	int i,j,min,k = 0;
	for(i = 0;i < E-1;++i)
	{
		min = road[i].w;
		k = i;
		for(j = E-1;j > i;--j)
		{
			if(road[j].w < min)
			{
				min = road[j].w;
				k = j;
			}
		}
		//交换road数组中i位置和k位置的元素
		if(i != k)
		{
			swap(&road[i].w,&road[k].w);
			swap(&road[i].a,&road[k].a);
			swap(&road[i].b,&road[k].b);
		}
	}
}

void swap(int *a,int *b)
{
	int k;
	k = *a;
	*a = *b;
	*b = k;
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
