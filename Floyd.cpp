#include<iostream>
#include<iomanip>
using namespace std;

#define MAX 20
#define INF 32767  //����
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
	for (int i = 0; i < G.num; i++)
	{
		for (int k = 0; k < G.num; k++)
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

void Disp1(Graph G, int A[][MAX], int path[][MAX])  //���·����Ϣ
{
	int apath[MAX], d, k;
	for (int i = 0; i < G.num; i++)  //���
	{
		for (int j = 0; j < G.num; j++)  //�յ�
		{
			if (A[i][j] != INF && i != j)  //����·��
			{
				cout << "��" << i << "��" << j << "��·������Ϊ��" << A[i][j] << "\t";
				k = path[i][j];
				d = 0; apath[d] = j;  //����յ�
				while (k != -1 && k != i)  //������е���ת��
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
	for (int i = 0; i < G.num; i++)  //���
	{
		if (i == 2)
			cout << "path(" << setw(2) << m << ")=|";
		else
			cout << setw(10) << "|";
		for (int j = 0; j < G.num; j++)  //�յ�
		{
				k = path[i][j];
				d = 0; apath[d] = j;
				while (k != -1 && k != i)
				{
					d++; apath[d] = k;
					k = path[i][k];
				}
				d++; apath[d] = i;  //������
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
				cout << setw(3) << "��";
			else
				cout << setw(3) << A[i][k];
		}
		cout << setw(5) << "|\n";
	}
}

void Floyd(Graph G)
{
	int A[MAX][MAX], path[MAX][MAX];   //A�����·���ľ���   path��·��
	for (int i = 0; i < G.num; i++)    //��ʼ��A path
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
	for (int k = 0; k < G.num; k++)  //��ת��
	{
		for (int i = 0; i < G.num; i++)  //���
		{
			for (int j = 0; j < G.num; j++)  //�յ�
			{
				if (A[i][j] > A[i][k] + A[k][j])  //�ı���̵�·�����Ⱥ�·��
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
