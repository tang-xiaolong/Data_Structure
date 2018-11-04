#include<stdio.h>
#include<malloc.h>
#define maxSize 30
//自定义数据类型应当包括：图的结构、顶点表、边表

typedef struct arcNode
{
	int adjVex;//这条边指向的那个顶点
	struct arcNode * nextArc;//下一条边
	int info;
}ArcNode;

typedef struct vertexNode
{
	int data;//顶点
	ArcNode *firstArc;//该顶点第一条边的指针
}VNode;


typedef struct graph
{
	//顶点数组
	VNode adjList[maxSize];
	int n,e;
}AGraph;


int visit[maxSize] = {0};
void GreateAGraph(AGraph* G);//有向图邻接表创建
void DFS(AGraph *G,int v);
int IsHaveRun(AGraph *G);
int main(void)
{
	AGraph G;
	int flag = 0;
	GreateAGraph(&G);
	DFS(&G,1);
	flag = IsHaveRun(&G);
	if(flag)
		printf("有环\n");
	else
		printf("无环\n");
	return 0;
}

int IsHaveRun(AGraph *G)
{
	int flag = 0;
	int i;
	for(i = 0;i < G->n;++i)
		if(visit[i] != 0)
			return 1;
	return 0;
}


void GreateAGraph(AGraph* G)
{
	int i,j,k;
	ArcNode *e;
	printf("请输入顶点数和边数：");
	scanf("%d%d",&(G->n),&(G->e));
	//printf("请分别输入顶点：");
	//读入顶点信息
	for(i = 0;i < G->n;++i)
	{
		G->adjList[i].data = i+1;
		//scanf("%d",&(G->adjList[i].data));
		G->adjList[i].firstArc = NULL;//将边指针初始化为NULL
	}

	//建立边表
	for(k = 0;k < G->e;++k)
	{
		//printf("请输入边（Vi,Vj）的序号i和j：");
		scanf("%d%d",&i,&j);
		e = (ArcNode *)malloc(sizeof(ArcNode));//申请一个边表节点
		e->adjVex = j;//先将自己的值设为j
		e->nextArc = G->adjList[i-1].firstArc;//让自己指向i那个顶点的下一个位置
		G->adjList[i-1].firstArc = e;//让i位置的指向自己
	}
}
//对原来的DFS简单修改即可：当在尝试从一个顶点遍历其连接的顶点时，如果对应visit数组标志是0，正常访问；如果是非0，让其加1，表示我又来到了这个顶点。同时，在遍历算法结束地方对应的visit标志减1，表示我从这个点退出去了。在算法外对visit数组检验即可，当出现非0的数字，则表示有环，因为无环的话应该正好都为0
void DFS(AGraph *G,int v)
{
	ArcNode *p;
	//printf("%d",v);
	visit[v] = 1;
	//让p指向图的第v个顶点的下一个位置
	p = G->adjList[v-1].firstArc;
	while(p)
	{//如果p指向的那个节点还没被访问，则访问他
		if(!visit[p->adjVex])
			DFS(G,p->adjVex);

		else
			visit[p->adjVex]+=1;
		p = p->nextArc;
	}
	visit[v]-=1;
}
/*
输入案例1
5 6
1 2
2 3
3 5
5 4
4 3
1 4
*/


/*
输入案例2
5 5
1 2
2 3
3 5
1 4
4 3
*/
