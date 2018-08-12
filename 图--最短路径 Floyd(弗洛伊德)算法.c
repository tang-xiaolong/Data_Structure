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
void Floyd(MGraph *G,int path[][maxSize]);
void PrintPath(int path[][maxSize],int i,int j);


int main(void)
{
	int path[maxSize][maxSize];
	MGraph G;
	CreateMGreaph(&G);
	Floyd(&G,path);
	PrintPath(path,1,0);
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
			if(i != j)
				G->edges[i][j] = Inf;
			else
				G->edges[i][j] = 0;
	//Input every edgesValue
	for(i = 0;i < G->e;++i)
	{
		scanf("%d%d%d",&j,&k,&w);
		G->edges[j][k] = w;
	}
}

void Floyd(MGraph *G,int path[][maxSize])
{
	int i,j,k;
	int dist[maxSize][maxSize];
	for(i = 0;i < G->n;++i)
	{
		for(j = 0;j < G->n;++j)
		{
			dist[i][j] = G->edges[i][j];
			path[i][j] = -1;
		}
	}
	for(k = 0;k < G->n;++k)
	{
		for(i = 0;i < G->n;++i)
		{
			for(j = 0;j < G->n;++j)
			{
				if(dist[i][k] + dist[k][j] < dist[i][j])
				{
					dist[i][j] = dist[i][k] + dist[k][j];
					path[i][j] = k;
				}
			}
		}
	}
	/*
	for(i = 0;i < G->n;++i)
	{
		for(j = 0;j < G->n;++j)
			printf("% d ",dist[i][j]);
		putchar('\n');
	}
	putchar('\n');
	for(i = 0;i < G->n;++i)
	{
		for(j = 0;j < G->n;++j)
			printf("% d ",path[i][j]);
		putchar('\n');
	}
	*/
}
void PrintPath(int path[][maxSize],int i,int j)
{
	if(path[i][j] == -1)
	{
		printf("%d->%d\n",i,j);
	}
	else
	{
		printf("%d->",i);
		PrintPath(path,path[i][j],j);
	}
}

/*
4 8
0 1 2 3
0 1 5 0 3 7
1 3 2 1 2 4
2 0 3 2 1 3 2 3 2
3 2 1
*/

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
