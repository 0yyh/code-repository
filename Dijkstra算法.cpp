#include<iostream>
using namespace std;

#define MAX 20    
#define INF 32456  //无穷
typedef struct    //邻接矩阵的结构
{
	int num;    //节点的总个数
	int edge;   //边的总数
	int graph[MAX][MAX];
}Graph;

void CreatGraph(Graph& G)  //邻接矩阵的创建
{
	int orno, endno, weight;
	cout << "输入节点的个数和边的总数" << endl;
	cin >> G.num >> G.edge;
	for (int i = 0; i < MAX; i++)
	{
		for (int k = 0; k < MAX; k++)
		{
			G.graph[i][k] = INF;
		}
	}
	for (int i = 0; i < G.edge; i++)
	{
		cout << "按顺序输入起始节点的编号，结束节点的编号，权值" << endl;
		cin >> orno >> endno >> weight; 
		G.graph[orno][endno] = weight; //将对应位置的值改为权值
		G.graph[orno][orno] = 0; //自己接自己定义为0
		G.graph[endno][endno] = 0;
	}
}

void Dijkstra(Graph G, int v)
{
	int dist[MAX], path[MAX], S[MAX];  //dist为权值（距离）数组，path为结点前驱数组，S为已找到最短路径的集合
	int mindis, t = -1;
	for (int i = 0; i < G.num; i++)
	{
		dist[i] = G.graph[v][i];   //结点权值（距离）的初始化
		S[i] = 0; //S置空
		if (G.graph[v][i] < INF)   //有路径的情况下
			path[i] = v;  //前驱为v
		else
			path[i] = -1;  //没有前驱
	}
	S[v] = 1; path[v] = 0; //起点的情况            S[i]==0表示不在S内，S[i]==1表示在S内
	for (int k = 0; k < G.num; k++)
	{
		if (dist[k] == INF)
			cout << "∞" << " ";
		else
			cout << dist[k] << " ";
	}
	cout << "\t\t";
	for (int k = 0; k < G.num; k++)
	{
		cout << path[k] << " ";
	}
	cout << endl;
	for (int i = 0; i < G.num - 1; i++)  //找路径只需要结点个数-1
	{
		mindis = INF;
		for (int j = 0; j < G.num; j++)  //找到不在S内的且有最短权值（路径）的结点
		{
			if (S[j] == 0 && dist[j] < mindis)
			{
				t = j;
				mindis = dist[j];
			}
		}
		S[t] = 1;  //将找到的结点放入S
		int m[MAX] = {0};
		for (int j = 0; j < G.num; j++)  //修改不在S内的结点的最短路径
		{
			if (S[j] == 0)
			{
				if (G.graph[t][j] < INF && dist[t] + G.graph[t][j] < dist[j])
				{
					dist[j] = dist[t] + G.graph[t][j];
					path[j] = t;
					m[j] = 1;
				}
			}
		}
		for (int k = 0; k < G.num; k++)
		{
			if (m[k] == 1)
				cout << "(" << dist[k] << ")" << " ";
			else
			{
				if (dist[k] == INF)
					cout << "∞" << " ";
				else
					cout << dist[k] << " ";
			}
		}
		cout << "\t\t";
		for (int k = 0; k < G.num; k++)
		{
			if (m[k] == 1)
				cout << "(" << path[k] << ")" << " ";
			else
				cout << path[k] << " ";
		}
		cout << endl;
	}
}

int main()
{
	Graph G;
	CreatGraph(G);
	Dijkstra(G, 0);
}