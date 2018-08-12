#include<stdio.h>
#define maxSize 30
#define Inf 32768
typedef struct
{
	int no;
	int info;
}VertexType;
typedef struct 
{
	int n,e;
	int edges[maxSize][maxSize];
	VertexType vex[maxSize];
}MGraph;

void CreateMGreaph(MGraph *G);
void Dijkstra1(MGraph *G,int v,int *dist,int *path);
void Dijkstra2(MGraph *G,int v,int *dist,int *path);
int main(void)
{
	int dist[maxSize],path[maxSize],i;
	MGraph G;
	CreateMGreaph(&G);
	Dijkstra2(&G,0,dist,path);
	for(i = 0;i < G.n;++i)
	{
		printf("%d ",path[i]);
	}
	return 0;
}

void CreateMGreaph(MGraph *G)
{
	int i,j,k,w;
	scanf("%d%d",&G->n,&G->e);
	//Input Arc
	for(i = 0;i < G->n;++i)
		scanf("%d",&G->vex[i].no);
	for(i = 0;i < G->n;++i)//Init edgesValue
		for(j = 0;j < G->n;++j)
			G->edges[i][j] = Inf;
	//Input every edgesValue
	for(i = 0;i < G->e;++i)
	{
		scanf("%d%d%d",&j,&k,&w);
		G->edges[j][k] = w;
	}
}

void Dijkstra1(MGraph *G,int v,int *dist,int *path)
{
	//先从未选取的点里找到一个权值最小的，并记录下来
	int i,j,min = -Inf,select = -1,n = 0;
	int set[maxSize] = {0};
	
	//初始化数组
	for(i = 0;i < G->n;++i)
	{
		dist[i] = G->edges[v][i];
		path[i] = v;
	}
	
	set[v] = 1;
	++n;
	path[v] = -1;
	dist[v] =  0;
	while(n != G->n)
	{
		for(i = 0;i < G->n;++i)
		{
			printf("%d ",dist[i]);
		}
		printf("\n");
		min = Inf;
	//找最小
		for(i = 0;i < G->n;++i)
			for(j = 0;j < G->n;++j)
			{//没有并入的，且和已经并入的
				if(set[i] == 1 && set[j] == 0)
				{
					if(dist[j] > dist[i]+G->edges[i][j])
					{
						dist[j] = dist[i]+G->edges[i][j];
						path[j] = i;
					}
					if(dist[j] < min)
					{
						min = dist[j];
						select = j;
					}
				}
			}
		//将新选定的节点放入我们set中
		set[select] = 1;
		++n;
	}
	for(i = 0;i < G->n;++i)
		{
			printf("%d ",dist[i]);
		}
		printf("\n");
}
void Dijkstra2(MGraph *G,int v,int *dist,int *path)
{
	int i,j,min,now;
	int set[maxSize] = {0};
	for(i = 0;i < G->n;++i)
	{
		if(G->edges[v][i] < Inf)
			path[i] = v;
		else
			path[i] = -1;
		dist[i] = G->edges[v][i];
	}
	set[v] = 1;
	path[v] = -1;
	dist[v] = 0;
	for(i = 0;i < G->n-1;++i)
	{
		//每一个回合都可以找出一个新的节点
		min = Inf;
		for(j = 0;j < G->n;++j)
		{//从未被访问的节点中找出dist最小的
			if(set[j] == 0 && dist[j] < min)
			{
				now = j;
				min = dist[j];
			}
		}
		//找到了一个节点，现在将它并入我们的集合，并更新它的代价和path   第一次找到的肯定是与v相邻的，与v相邻的初始path就是v，所以不影响
		set[now] = 1;
		for(j = 0;j < G->n;++j)
		{
			if(set[j] == 0 && dist[now]+G->edges[now][j]  < dist[j])
			{
				dist[j] = dist[now]+G->edges[now][j];
				path[j] = now;
			}
		}
	}

}

/*
7 12
0 1 2 3 4 5 6
0 1 4
0 2 6
0 3 6
1 2 1
1 4 7
2 4 6
2 5 4
3 2 2
3 5 5
4 6 6
5 4 1
5 6 8
*/
