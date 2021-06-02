#include<iostream>
using namespace std;

#define MAX 20    
#define INF 32456  //����
typedef struct    //�ڽӾ���Ľṹ
{
	int num;    //�ڵ���ܸ���
	int edge;   //�ߵ�����
	int graph[MAX][MAX];
}Graph;

void CreatGraph(Graph& G)  //�ڽӾ���Ĵ���
{
	int orno, endno, weight;
	cout << "����ڵ�ĸ����ͱߵ�����" << endl;
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
		cout << "��˳��������ʼ�ڵ�ı�ţ������ڵ�ı�ţ�Ȩֵ" << endl;
		cin >> orno >> endno >> weight; 
		G.graph[orno][endno] = weight; //����Ӧλ�õ�ֵ��ΪȨֵ
		G.graph[orno][orno] = 0; //�Լ����Լ�����Ϊ0
		G.graph[endno][endno] = 0;
	}
}

void Dijkstra(Graph G, int v)
{
	int dist[MAX], path[MAX], S[MAX];  //distΪȨֵ�����룩���飬pathΪ���ǰ�����飬SΪ���ҵ����·���ļ���
	int mindis, t = -1;
	for (int i = 0; i < G.num; i++)
	{
		dist[i] = G.graph[v][i];   //���Ȩֵ�����룩�ĳ�ʼ��
		S[i] = 0; //S�ÿ�
		if (G.graph[v][i] < INF)   //��·���������
			path[i] = v;  //ǰ��Ϊv
		else
			path[i] = -1;  //û��ǰ��
	}
	S[v] = 1; path[v] = 0; //�������            S[i]==0��ʾ����S�ڣ�S[i]==1��ʾ��S��
	for (int k = 0; k < G.num; k++)
	{
		if (dist[k] == INF)
			cout << "��" << " ";
		else
			cout << dist[k] << " ";
	}
	cout << "\t\t";
	for (int k = 0; k < G.num; k++)
	{
		cout << path[k] << " ";
	}
	cout << endl;
	for (int i = 0; i < G.num - 1; i++)  //��·��ֻ��Ҫ������-1
	{
		mindis = INF;
		for (int j = 0; j < G.num; j++)  //�ҵ�����S�ڵ��������Ȩֵ��·�����Ľ��
		{
			if (S[j] == 0 && dist[j] < mindis)
			{
				t = j;
				mindis = dist[j];
			}
		}
		S[t] = 1;  //���ҵ��Ľ�����S
		int m[MAX] = {0};
		for (int j = 0; j < G.num; j++)  //�޸Ĳ���S�ڵĽ������·��
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
					cout << "��" << " ";
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