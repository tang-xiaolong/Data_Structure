#include<stdio.h>
#include<malloc.h>
#define maxSize 30
typedef struct ArcNode
{
	int adjVex;//该边指向的顶点位置
	struct ArcNode *nextArc;//指向下一条边的指针
	int info;
}ArcNode;

typedef struct
{
	int data;
	ArcNode *firstArc;
}VNode;

typedef struct 
{
	VNode adjList[maxSize];//邻接表  存放所有的顶点
	int e,n;//边和顶点数目
}AGraph;

int visit[maxSize] = {0};
void CreateAGraph(AGraph *G);
int BFS(AGraph *G,int v);

// 7 9 1 2 3 4 5 6 7 1 2 1 3 1 4 2 4 3 4 3 5 4 6 5 6 6 7
int main(void)
{
	AGraph G;
	int id = 0;
	CreateAGraph(&G);
	id = BFS(&G,1);
	printf("\n%d距离顶点1最远\n",id);
	return 0;
}


void CreateAGraph(AGraph *G)
{
	int i,j,k;
	ArcNode *p;
	scanf("%d%d",&(G->n),&(G->e));
	for(i = 0;i < G->n;++i)
	{
		scanf("%d",&(G->adjList[i].data));
		G->adjList[i].firstArc = NULL;
	}//处理完顶点后，再来处理边
	for(i = 0;i < G->e;++i)
	{
		scanf("%d%d",&j,&k);//j  和 k有关联
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

int BFS(AGraph *G,int v)
{
	int queue[maxSize];
	int i,j;
	ArcNode *p;
	int rear = 0,front =  0;
	for(i = 0;i < G->n+1;++i)
		visit[i] = 0;
	rear = (rear+1)%maxSize;
	queue[rear] = v;
	visit[v] = 1;
	while(rear != front)
	{
		//从队列中取出一个
		front = (front+1)%maxSize;
		j = queue[front];
		printf("%d",j);
		p = G->adjList[j-1].firstArc;
		while(p != NULL)
		{
			//如果p未被访问，则将其加入到队列中，设为1
			if(visit[p->adjVex] == 0)
			{
				visit[p->adjVex] = 1;
				rear = (rear+1)%maxSize;
				queue[rear] = p->adjVex;
			}
			p = p->nextArc;
		}
	}
	//队列为空时，此时j存放的就是最后一个顶点，它距首节点最远
	return j;
}
