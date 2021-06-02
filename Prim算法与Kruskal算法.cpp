#include<iostream>
#include<iomanip>   //setw函数的头文件
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
		G.graph[endno][orno] = weight;
		G.graph[orno][orno] = 0; //自己接自己定义为0
		G.graph[endno][endno] = 0;
	}
}

void Prim(Graph G, int v)       //prim算法，利用点的变化           利用了状态转移的思想
{
	int lowcost[MAX];         //各点距离树的最小权值
	int min;
	int closest[MAX];        //每一步操作，树的起点
	int k = 0, t;
	cout << v;
	for (int i = 0; i < G.num; i++)  //初始化数组，并输出第一列数据
	{
		lowcost[i] = G.graph[v][i];
		closest[i] = v;
		cout << setw(2) << "(" << v << "," << i << "):";
		if (lowcost[i] == INF)
			cout << "∞";
		else
			cout << lowcost[i] << " ";
	}
	for (int i = 1; i < G.num; i++)  //找剩余的点
	{
		min = INF;
		for (int j = 0; j < G.num; j++)      //在树外面的点中找到距离树最小的边
		{
			if (lowcost[j] != 0 && lowcost[j] < min)
			{
				min = lowcost[j];
				k = j;   //记录最近的点的编号
			}
		}
		cout <<setw(4)<< "边(" << closest[k] << "," << k << ")权为:" << min << endl;
		t = k;
		lowcost[k] = 0;  //说明k号结点已加入树
		if (i == G.num - 1) //只用输出n-1行数据
			break;
		cout << t;
		for (int j = 0; j < G.num; j++)
		{
			if (lowcost[j] != 0 && G.graph[k][j] < lowcost[j])  //改变数组的状态
			{
				lowcost[j] = G.graph[k][j];
				closest[j] = k;
			}
			cout << " (" << closest[j] << "," << j << "):";
			if (lowcost[j] == INF)
				cout << "∞";
			else
				cout << lowcost[j] << " ";
		}
	}
}

typedef struct  //边的结构
{
	int u; //起点
	int v; //终点
	int w; //权值
}Edge;     

void Insertsort(Edge E[], int n)   //冒泡排序，将边按照权值由小到大排列
{
	Edge t;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (E[j].w > E[j + 1].w)
			{
				t = E[j];
				E[j] = E[j + 1];
				E[j + 1] = t;
			}
		}
	}
}

void Kruskal(Graph G)  //kruskal算法，利用边进行构造
{
	int vest[MAX]; //辅助数组
	Edge E[MAX];  //存放所有边的数据  
	int k = 0, m = 0;
	for (int i = 0; i < G.num; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (G.graph[i][j] != 0 && G.graph[i][j] != INF) //录入边的数据
			{
				E[k].u = i;
				E[k].v = j;
				E[k].w = G.graph[i][j];
				k++;
			}
		}
	}
	Insertsort(E, G.edge);
	for (int i = 0; i < G.num; i++)  //辅助数组的初始化
		vest[i] = i;
	k = 1;
	int u1, u2;
	int s1, s2;
	while (k < G.num)  //边数小于n循环
	{
		u1 = E[m].u; u2 = E[m].v; //取一条边的两个点
		s1 = vest[u1]; s2 = vest[u2]; //得到两个点的集合编号
		if (s1 != s2) //集合不同时将两个点进行构造
		{
			cout << "起点，终点和权值为：";
			cout << "(" << u1 << "," << u2 << "):" << E[m].w;
			k++;
			cout << " 集合号的变化：";
			for (int i = 0; i < G.num; i++)  //统一集合的编号将终点的编号改为起点编号
			{
				if (vest[i] == s2)
					vest[i] = s1;
				cout << vest[i] << " ";
			}
			cout << endl;
		}
		m++;
	}
}

int main()
{
	Graph G;
	CreatGraph(G);
	for (int i = 0; i < G.num; i++)
	{
		cout << endl << endl << endl;
		cout << "-----------------------------------------------------------------------" << endl;
		cout << "起点" << setw(30) << "lowcost数组保存的候选边" << setw(38) << "选择的边（不为0的权值中最小值）" << endl;
		cout << "-----------------------------------------------------------------------" << endl;
		Prim(G, i);
		cout << "-----------------------------------------------------------------------" << endl;
	}
	Kruskal(G);
}