#include<stdio.h>
#include<malloc.h>
#define maxSize 30
#define Inf 32768
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


int visit1[maxSize] = {0};
int visit2[maxSize] = {0};
void GreateAGraph(AGraph* G);//无向图邻接表创建
void DFS1(AGraph *G,int v);//递归深度优先遍历  Deepth First Search   这是对连通图的遍历，而对于非连通图，只需要用一个for循环循环图的arcList即可，当节点visit1数组中标志位是0则对这个节点调用一次
void DFSNotConnect(AGraph *G);
void DFS2(AGraph *G,int v);//非递归深度优先遍历
void BFS(AGraph *G,int v);//广度优先遍历	Breadth First Search

//连通图输入示例：  7 9 1 2 3 4 5 6 7 1 2 1 3 1 4 2 4 3 4 3 5 4 6 5 6 6 7
//非连通图输入示例：6 6 1 2 3 4 5 6 1 2 1 3 1 4 2 4 3 4 5 6
int main(void)
{
	AGraph G;
	GreateAGraph(&G);
	DFS1(&G,1);
	putchar('\n');
	DFS2(&G,1);
	putchar('\n');
	DFSNotConnect(&G);//使用非连通图时，前两个输出会不完整
	putchar('\n');
	BFS(&G,1);
	putchar('\n');
	return 0;
}




void GreateAGraph(AGraph* G)
{
	int i,j,k;
	ArcNode *e;
	//printf("请输入顶点数和边数：");
	scanf("%d%d",&(G->n),&(G->e));
	//printf("请分别输入顶点：");
	//读入顶点信息
	for(i = 0;i < G->n;++i)
	{
		scanf("%d",&(G->adjList[i].data));
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
		//因为是无向图   所以也需要将i节点放到j位置的那个节点后面去
		e = (ArcNode *)malloc(sizeof(ArcNode));
		e->adjVex = i;
		e->nextArc = G->adjList[j-1].firstArc;
		G->adjList[j-1].firstArc = e;
	}
}

void DFS1(AGraph *G,int v)
{
	ArcNode *p;
	printf("%d",v);
	visit1[v] = 1;
	//让p指向图的第v个顶点的下一个位置
	p = G->adjList[v-1].firstArc;
	while(p)
	{//如果p指向的那个节点还没被访问，则访问他
		if(!visit1[p->adjVex])
			DFS1(G,p->adjVex);
		p = p->nextArc;
	}
}

void DFS2(AGraph *G,int v)
{
	int S[maxSize];
	int top = -1;
	ArcNode *p;
	S[++top] = v;//入栈了则标记为1
	visit2[v] = 1;
	while(top != -1)
	{
		//visit2[S[top]-1] = 1;
		printf("%d",G->adjList[S[top]-1].data);
		p = G->adjList[S[top--]-1].firstArc;
		while(p)
		{//如果p还没有被压入栈，则入栈并标记为1
			if(!visit2[p->adjVex])
			{
				S[++top] = p->adjVex;
				visit2[p->adjVex] =  1;
			}
			p = p->nextArc;
		}
	}
}

void DFSNotConnect(AGraph *G)
{
	int i = 0;
	for(i = 0;i < G->n+1;++i)//因为这里默认不使用visit的第1个位置的值，所以需要往后多初始化一个元素
		visit1[i] = 0;
	for(i = 0;i < G->n;++i)
		if(!visit1[i])//当是连通图时，这里只会执行一次
			DFS1(G,i+1);
}

void BFS(AGraph *G,int v)
{
	ArcNode *p;
	int queue[maxSize];//定义一个队列
	int n = 0,f = 0;//队尾和队首
	int i = 0;
	for(i = 1;i < G->n+1;++i)//将标志数组初始化
		visit2[i] = 0;
	
	queue[n++] = v;
	visit2[v] =  1;
	printf("%d",G->adjList[v-1].data);
	while(n != f)
	{
		i = queue[f++];//取出一个元素
		p = G->adjList[i-1].firstArc;
		while(p)
		{//这里的代码逻辑其实和非递归深度优先遍历一样，只不过我们这里取出元素的顺序和栈取出顺序不同，所以也就导致我们的遍历顺序不同
			if(!visit2[p->adjVex])
			{
				visit2[p->adjVex] = 1;
				printf("%d",G->adjList[p->adjVex-1].data);
				queue[n++] = p->adjVex;
			}
			p = p->nextArc;
		}
	}
}
