#include<iostream>
#include<iomanip>
using namespace std;

#define MAX 20
#define INF 32767  //无穷
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
	for (int i = 0; i < G.num; i++)
	{
		for (int k = 0; k < G.num; k++)
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

void Disp1(Graph G, int A[][MAX], int path[][MAX])  //输出路径信息
{
	int apath[MAX], d, k;
	for (int i = 0; i < G.num; i++)  //起点
	{
		for (int j = 0; j < G.num; j++)  //终点
		{
			if (A[i][j] != INF && i != j)  //存在路径
			{
				cout << "从" << i << "到" << j << "的路径长度为：" << A[i][j] << "\t";
				k = path[i][j];
				d = 0; apath[d] = j;  //添加终点
				while (k != -1 && k != i)  //添加所有的中转点
				{
					d++; apath[d] = k;
					k = path[i][k];
				}
				d++; apath[d] = i;
				cout << apath[d];
				for (int s = d - 1; s >= 0; s--)
					cout << "->" << apath[s];
			}
			cout << endl;
		}
		cout << endl;
	}
}

void Disp(Graph G, int A[][MAX], int path[][MAX],int m)
{
	int apath[MAX], d, k;
	for (int i = 0; i < G.num; i++)  //起点
	{
		if (i == 2)
			cout << "path(" << setw(2) << m << ")=|";
		else
			cout << setw(10) << "|";
		for (int j = 0; j < G.num; j++)  //终点
		{
				k = path[i][j];
				d = 0; apath[d] = j;
				while (k != -1 && k != i)
				{
					d++; apath[d] = k;
					k = path[i][k];
				}
				d++; apath[d] = i;  //添加起点
				cout << apath[d];
				for (int s = d - 1; s >= 0; s--)
					cout << apath[s];
				cout << setw(6 - d);
		}
		cout << setw(6 - d) << "|\t";
		if (i == 2)
			cout << "A(" << setw(2) << m << ")=  |";
		else
			cout << "\t|";
		for (int k = 0; k < G.num; k++)
		{
			if (A[i][k] == INF)
				cout << setw(3) << "∞";
			else
				cout << setw(3) << A[i][k];
		}
		cout << setw(5) << "|\n";
	}
}

void Floyd(Graph G)
{
	int A[MAX][MAX], path[MAX][MAX];   //A是最短路径的距离   path是路径
	for (int i = 0; i < G.num; i++)    //初始化A path
	{
		for (int j = 0; j < G.num; j++)
		{
			A[i][j] = G.graph[i][j];
			if (i != j && G.graph[i][j] < INF)
				path[i][j] = i;
			else
				path[i][j] = -1;
		}
	}
	Disp(G, A, path,-1);
	cout << endl;
	for (int k = 0; k < G.num; k++)  //中转点
	{
		for (int i = 0; i < G.num; i++)  //起点
		{
			for (int j = 0; j < G.num; j++)  //终点
			{
				if (A[i][j] > A[i][k] + A[k][j])  //改变最短的路径长度和路径
				{
					A[i][j] = A[i][k] + A[k][j];
					path[i][j] = path[k][j];
				}
			}
		}
		Disp(G, A, path, k);
		cout << endl;
	}
	cout << endl;
	Disp1(G, A, path);
}

int main()
{
	Graph G;
	CreatGraph(G);
	Floyd(G);
}
