//可用于判断是否有环
//算法思想：1、先从图中找出一个没有前驱的顶点输出
//			2、将这个顶点删除并将从这个顶点发出的边全部删除
//			3、重复12过程，直到顶点全部输出或者不存在无前驱的顶点(如果是这种情况，图中必定有环)
//  AOV网  活动位于顶点上的网   

#include<stdio.h>
#include<malloc.h>
#define maxSize 30
#define Inf 32768

typedef struct ArcNode
{
	int adjVex;
	struct ArcNode* nextArc;
	int w;
}ArcNode;
typedef struct
{
	int data;
	int IDG;
	int ODG;
	ArcNode *firstArc;
}VNode;
typedef struct 
{
	VNode adjList[maxSize];
	int n,e;
}AGraph;

void CreateAGraph(AGraph *G);
void CalculateDegree(AGraph *G);
int TopSort(AGraph *G);
int main(void)
{
	int result = 0;
	AGraph G;
	CreateAGraph(&G);
	CalculateDegree(&G);
	result = TopSort(&G);
	if(result == 1)
		printf("\n拓扑排序成功！\n");
	else
		printf("\n拓扑排序失败！该图有环！\n");
	return 0;
}

void CreateAGraph(AGraph *G)
{
	int i,j,k,w;
	ArcNode *p;
	scanf("%d%d",&G->n,&G->e);
	for(i = 0;i < G->n;++i)
	{
		scanf("%d",&G->adjList[i].data);//输入顶点标号
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
void CalculateDegree(AGraph *G)
{
	int i,j,count = 0;
	ArcNode *p;
	for(i = 0;i < G->n;++i)
	{
		count = 0;
		p = G->adjList[i].firstArc;
		while(p != NULL)
		{
			++count;
			p = p->nextArc;
		}
		G->adjList[i].ODG = count;
	}
	//计算出度
	for(i = 0;i < G->n;++i)
	{
		count =  0;
		//计算i顶点的。把所有的都遍历一遍，是i就加
		for(j = 0;j < G->n;++j)
		{
			if(i == j)
				continue;
			p = G->adjList[j].firstArc;
			while(p != NULL)
			{
				if(p->adjVex == i)
					++count;
				p = p->nextArc;
			}
		}
		G->adjList[i].IDG = count;
	}
}
int TopSort(AGraph *G)
{
	int j,now,count = 0;
	int stack[maxSize];
	int top = -1;
	ArcNode*p;
	//选出一个入度为0的顶点。
	for(j = 0;j < G->n;++j)
	{
		if(G->adjList[j].IDG == 0)
		{//如果入度为0，则入栈
			stack[++top] = j;
		}
	}
	while(top != -1)
	{
		now = stack[top--];
		printf("%2d",now);
		++count;
		//遍历这个节点所连接的顶点
		p = G->adjList[now].firstArc;
		while(p != NULL)
		{
			j = p->adjVex;
			G->adjList[j].IDG--;
			if(G->adjList[j].IDG == 0)
				stack[++top] = j;
			p = p->nextArc;
		}
	}
	if(count == G->n)
		return 1;
	else
		return 0;
}
/*
7 11
0 1 2 3 4 5 6
0 1 1
0 2 1
0 3 1
1 2 1
1 4 1
2 4 1 
2 5 1
3 5 1
4 6 1
5 4 1
5 6 1
*/

/*
7 11
0 1 2 3 4 5 6
0 1 1
0 2 1
0 3 1
1 2 1
1 4 1
2 4 1 
2 5 1
3 5 1
4 6 1
5 4 1
6 5 1
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
