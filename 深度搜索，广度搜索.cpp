#include<iostream>
using namespace std;

#define MAX 11   //�����max�Ҷ���Ϊ�ͽ����һ��
typedef struct    //�ڽӾ���Ľṹ
{
	int num;    //�����ܸ���
	int edge;   //�ߵ�����
	int no[MAX];    //�ڵ�ı��
	int graph[MAX][MAX];
}Graph;

typedef struct ANode  //�߽��Ľṹ��
{
	int orno;  //�ٽ��ı��
	struct ANode* next;
}EdgeAnode;
typedef struct VNode  //����Ľṹ
{
	EdgeAnode* FirstEdge; //ָ���һ���߽��
}Vertex;
typedef struct  //�ڽӱ�Ľṹ
{
	Vertex adjlist[MAX];
	int num, edge;
}AdjGraph;

void CreatGraph(Graph& G)  //�ڽӾ���Ĵ���
{
	int t, t1;
	int orno, endno;
	cout << "����ڵ�ĸ����ͱߵ�����" << endl;
	cin >> G.num >> G.edge;
	cout << "����ڵ�ı��" << endl;
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
		cout << "��˳��������ʼ�ڵ�ı�ţ������ڵ�ı��" << endl;
		cin >> orno >> endno ; //����ı�Ų�һ����������һ��ǡ�ú�������±���ȣ������ҿ������� ABCD ��
		for (int i = 0; i < G.num; i++)  //���ѭ�������þ����ҵ�����������е�λ�ã�����¼��λ��
		{
			if (G.no[i] == orno)
				t = i;
			if (G.no[i] == endno)
				t1 = i;
		}
		G.graph[t][t1] = 1; //����Ӧλ�õ�ֵ��ΪȨֵ
		G.graph[t1][t] = 1;
	}
}

void DisGraph(Graph G)  //����ڽӾ���
{
	cout << "�ڽӾ���Ϊ��" << endl;
	for (int i = 0; i < MAX; i++)  //��Ϊ�����ҵ�MAX���Ҷ���Ϊ���ĸ����ˣ�������ʵ��̫�Ͻ���Ӧ�ö���ΪG.num
	{
		for (int k = 0; k < MAX; k++)
		{
				cout << G.graph[i][k] << "\t";
		}
		cout << endl;
	}
}

void Change(AdjGraph*& G1, Graph G, int num, int edge)  //�ڽӾ���ת��Ϊ�ڽӱ�
{
	EdgeAnode* p;
	G1 = new AdjGraph; //�ڽӱ�ĳ�ʼ��
	for (int i = 0; i < G.num; i++)
		G1->adjlist[i].FirstEdge = NULL; //������ͷ�ڵ��ָ���ÿ�
	for (int i = 0; i < num; i++)
	{
		for (int k = num - 1; k >= 0; k--)
		{
			if (G.graph[i][k] != 0)  //���ڹ�ϵ
			{
				p = new EdgeAnode;
				p->orno = G.no[k]; //����ڽӵ�ı��
				p->next = G1->adjlist[i].FirstEdge; //ͷ�巨����
				G1->adjlist[i].FirstEdge = p;
			}
		}
	}
	G1->num = num; G1->edge = edge;
}

void DisAdj(AdjGraph* G1)  //����ڽӱ�
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

int visit[MAX] = { 0 };      //�жϷ����Ƿ���й�
void DFS(AdjGraph* G1, int v)        //�������
{
	EdgeAnode* p;
	visit[v] = 1;
	cout << v << " ";
	p = G1->adjlist[v].FirstEdge;
	while (p != NULL)
	{
		if (visit[p->orno] == 0)
			DFS(G1, p->orno);   //�ݹ�
		p = p->next;
	}
}

int visit1[MAX] = { 0 };   //�ж��Ƿ���й�����
void BFS(AdjGraph* G1, int v)  //�������
{
	int queue[MAX];   //���飨���������ã�
	EdgeAnode* p;
	int front = -1, rear = -1;
	queue[++rear] = v;
	visit1[v] = 1;
	while (front != rear)  //���в�Ϊ�յ�ʱ��
	{
		cout << queue[front + 1] << " ";
		p = G1->adjlist[queue[front + 1]].FirstEdge;  //��һ���ߵĽ��
		while (p != NULL) 
		{
			if (visit1[p->orno] == 0)  //�Ƿ���й�����
			{
				queue[++rear] = p->orno;  //������
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
	cout << "ͼG���ڽӾ���ת�ڽӱ�Ϊ��" << endl;
	DisAdj(G1);

	int n, m;
	cout << "���½����������������������������㣺"; cin >> n;
	cout << "��"; cout << n; cout << "Ϊ�������������������˳���ǣ�"; DFS(G1, n); cout << endl;

	cout << "���½��й������������������������㣺"; cin >> m;
	cout << "��"; cout << m; cout << "Ϊ���Ĺ��������������˳���ǣ�"; BFS(G1, m);
}