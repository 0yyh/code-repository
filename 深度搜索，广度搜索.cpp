#include<iostream>
using namespace std;

#define MAX 11   //这里的max我定义为和结点数一样
typedef struct    //邻接矩阵的结构
{
	int num;    //结点的总个数
	int edge;   //边的总数
	int no[MAX];    //节点的编号
	int graph[MAX][MAX];
}Graph;

typedef struct ANode  //边结点的结构体
{
	int orno;  //临结点的编号
	struct ANode* next;
}EdgeAnode;
typedef struct VNode  //顶点的结构
{
	EdgeAnode* FirstEdge; //指向第一个边结点
}Vertex;
typedef struct  //邻接表的结构
{
	Vertex adjlist[MAX];
	int num, edge;
}AdjGraph;

void CreatGraph(Graph& G)  //邻接矩阵的创建
{
	int t, t1;
	int orno, endno;
	cout << "输入节点的个数和边的总数" << endl;
	cin >> G.num >> G.edge;
	cout << "输入节点的编号" << endl;
	for (int i = 0; i < G.num; i++)
		cin >> G.no[i];
	for (int i = 0; i < MAX; i++)
	{
		for (int k = 0; k < G.num; k++)
		{
			G.graph[i][k] = 0;
		}
	}
	for (int i = 0; i < G.edge; i++)
	{
		cout << "按顺序输入起始节点的编号，结束节点的编号" << endl;
		cin >> orno >> endno ; //输入的编号不一定会如书上一样恰好和数组的下标相等，例如我可以输入 ABCD 等
		for (int i = 0; i < G.num; i++)  //这个循环的作用就是找到编号在数组中的位置，并记录该位置
		{
			if (G.no[i] == orno)
				t = i;
			if (G.no[i] == endno)
				t1 = i;
		}
		G.graph[t][t1] = 1; //将对应位置的值改为权值
		G.graph[t1][t] = 1;
	}
}

void DisGraph(Graph G)  //输出邻接矩阵
{
	cout << "邻接矩阵为：" << endl;
	for (int i = 0; i < MAX; i++)  //因为这里我的MAX被我定义为结点的个数了，这样其实不太严谨，应该定义为G.num
	{
		for (int k = 0; k < MAX; k++)
		{
				cout << G.graph[i][k] << "\t";
		}
		cout << endl;
	}
}

void Change(AdjGraph*& G1, Graph G, int num, int edge)  //邻接矩阵转换为邻接表
{
	EdgeAnode* p;
	G1 = new AdjGraph; //邻接表的初始化
	for (int i = 0; i < G.num; i++)
		G1->adjlist[i].FirstEdge = NULL; //将所有头节点的指针置空
	for (int i = 0; i < num; i++)
	{
		for (int k = num - 1; k >= 0; k--)
		{
			if (G.graph[i][k] != 0)  //存在关系
			{
				p = new EdgeAnode;
				p->orno = G.no[k]; //存放邻接点的编号
				p->next = G1->adjlist[i].FirstEdge; //头插法插入
				G1->adjlist[i].FirstEdge = p;
			}
		}
	}
	G1->num = num; G1->edge = edge;
}

void DisAdj(AdjGraph* G1)  //输出邻接表
{
	EdgeAnode* p;
	for (int i = 0; i < G1->num; i++)
	{
		p = G1->adjlist[i].FirstEdge;
		cout << i;
		while (p != NULL)
		{
			cout << "--->" << p->orno;
			p = p->next;
		}
		cout << "^" << endl;
	}
}

int visit[MAX] = { 0 };      //判断访问是否进行过
void DFS(AdjGraph* G1, int v)        //深度搜索
{
	EdgeAnode* p;
	visit[v] = 1;
	cout << v << " ";
	p = G1->adjlist[v].FirstEdge;
	while (p != NULL)
	{
		if (visit[p->orno] == 0)
			DFS(G1, p->orno);   //递归
		p = p->next;
	}
}

int visit1[MAX] = { 0 };   //判断是否进行过访问
void BFS(AdjGraph* G1, int v)  //广度搜索
{
	int queue[MAX];   //数组（当队列来用）
	EdgeAnode* p;
	int front = -1, rear = -1;
	queue[++rear] = v;
	visit1[v] = 1;
	while (front != rear)  //队列不为空的时候
	{
		cout << queue[front + 1] << " ";
		p = G1->adjlist[queue[front + 1]].FirstEdge;  //第一条边的结点
		while (p != NULL) 
		{
			if (visit1[p->orno] == 0)  //是否进行过访问
			{
				queue[++rear] = p->orno;  //进队列
				visit1[p->orno] = 1;
			}
			p = p->next;
		}
		front++;
	}
}

void main()
{
	Graph G;
	CreatGraph(G);
	DisGraph(G);

	AdjGraph* G1;
	Change(G1, G, G.num, G.edge);
	cout << "图G的邻接矩阵转邻接表为：" << endl;
	DisAdj(G1);

	int n, m;
	cout << "以下进行深度优先搜索遍历，请输入起点："; cin >> n;
	cout << "以"; cout << n; cout << "为起点的深度优先搜索遍历顺序是："; DFS(G1, n); cout << endl;

	cout << "以下进行广度优先搜索遍历，请输入起点："; cin >> m;
	cout << "以"; cout << m; cout << "为起点的广度优先搜索遍历顺序是："; BFS(G1, m);
}