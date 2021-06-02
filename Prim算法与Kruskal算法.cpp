#include<iostream>
#include<iomanip>   //setw������ͷ�ļ�
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
		G.graph[endno][orno] = weight;
		G.graph[orno][orno] = 0; //�Լ����Լ�����Ϊ0
		G.graph[endno][endno] = 0;
	}
}

void Prim(Graph G, int v)       //prim�㷨�����õ�ı仯           ������״̬ת�Ƶ�˼��
{
	int lowcost[MAX];         //�������������СȨֵ
	int min;
	int closest[MAX];        //ÿһ���������������
	int k = 0, t;
	cout << v;
	for (int i = 0; i < G.num; i++)  //��ʼ�����飬�������һ������
	{
		lowcost[i] = G.graph[v][i];
		closest[i] = v;
		cout << setw(2) << "(" << v << "," << i << "):";
		if (lowcost[i] == INF)
			cout << "��";
		else
			cout << lowcost[i] << " ";
	}
	for (int i = 1; i < G.num; i++)  //��ʣ��ĵ�
	{
		min = INF;
		for (int j = 0; j < G.num; j++)      //��������ĵ����ҵ���������С�ı�
		{
			if (lowcost[j] != 0 && lowcost[j] < min)
			{
				min = lowcost[j];
				k = j;   //��¼����ĵ�ı��
			}
		}
		cout <<setw(4)<< "��(" << closest[k] << "," << k << ")ȨΪ:" << min << endl;
		t = k;
		lowcost[k] = 0;  //˵��k�Ž���Ѽ�����
		if (i == G.num - 1) //ֻ�����n-1������
			break;
		cout << t;
		for (int j = 0; j < G.num; j++)
		{
			if (lowcost[j] != 0 && G.graph[k][j] < lowcost[j])  //�ı������״̬
			{
				lowcost[j] = G.graph[k][j];
				closest[j] = k;
			}
			cout << " (" << closest[j] << "," << j << "):";
			if (lowcost[j] == INF)
				cout << "��";
			else
				cout << lowcost[j] << " ";
		}
	}
}

typedef struct  //�ߵĽṹ
{
	int u; //���
	int v; //�յ�
	int w; //Ȩֵ
}Edge;     

void Insertsort(Edge E[], int n)   //ð�����򣬽��߰���Ȩֵ��С��������
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

void Kruskal(Graph G)  //kruskal�㷨�����ñ߽��й���
{
	int vest[MAX]; //��������
	Edge E[MAX];  //������бߵ�����  
	int k = 0, m = 0;
	for (int i = 0; i < G.num; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (G.graph[i][j] != 0 && G.graph[i][j] != INF) //¼��ߵ�����
			{
				E[k].u = i;
				E[k].v = j;
				E[k].w = G.graph[i][j];
				k++;
			}
		}
	}
	Insertsort(E, G.edge);
	for (int i = 0; i < G.num; i++)  //��������ĳ�ʼ��
		vest[i] = i;
	k = 1;
	int u1, u2;
	int s1, s2;
	while (k < G.num)  //����С��nѭ��
	{
		u1 = E[m].u; u2 = E[m].v; //ȡһ���ߵ�������
		s1 = vest[u1]; s2 = vest[u2]; //�õ�������ļ��ϱ��
		if (s1 != s2) //���ϲ�ͬʱ����������й���
		{
			cout << "��㣬�յ��ȨֵΪ��";
			cout << "(" << u1 << "," << u2 << "):" << E[m].w;
			k++;
			cout << " ���Ϻŵı仯��";
			for (int i = 0; i < G.num; i++)  //ͳһ���ϵı�Ž��յ�ı�Ÿ�Ϊ�����
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
		cout << "���" << setw(30) << "lowcost���鱣��ĺ�ѡ��" << setw(38) << "ѡ��ıߣ���Ϊ0��Ȩֵ����Сֵ��" << endl;
		cout << "-----------------------------------------------------------------------" << endl;
		Prim(G, i);
		cout << "-----------------------------------------------------------------------" << endl;
	}
	Kruskal(G);
}