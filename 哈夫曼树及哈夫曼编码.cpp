#include<iostream>
using namespace std;

#define N 9
typedef struct									//���������ڵ�Ľṹ
{
	char data;
	double weight;
	int parent, LC, RC;
}HTNode;

typedef struct                                //����������Ľڵ�ṹ
{
	char cd[N];
	int start;
}HCode;

void CreatHT(HTNode ht[], int n0)                            //������������
{
	int  lnode, rnode;                                      //lnodeΪ��С�ڵ���±꣬rnodeΪ����С�ڵ���±�
	double min1, min2;                                      //min1Ϊ��СȨֵ��min2Ϊ����СȨֵ
	for (int i = 0; i < 2 * n0 - 1; i++)
		ht[i].parent = ht[i].LC = ht[i].RC = -1;            //��ʼ��
	for (int i = n0; i <= 2 * n0 - 2; i++)                  //���½ڵ�Ĳ���
	{
		min1 = min2 = 1000;
		lnode = rnode = -1;
		for (int k = 0; k <= i - 1; k++)					//�����нڵ���в���
		{
			if (ht[k].parent == -1)
			{
				if (ht[k].weight < min1)                   //ȨֵΪ��Сֵ�������
				{
					min2 = min1; rnode = lnode;            //��ԭ������Сֵ��Ϊ����Сֵ
					min1 = ht[k].weight; lnode = k;
				}
				else if (ht[k].weight < min2)             //Ȩֵ�ȴ���СֵС������Сֵ��������
				{
					min2 = ht[k].weight; rnode = k;
				}
			}
		}
		ht[i].weight = ht[lnode].weight + ht[rnode].weight;
		ht[i].LC = lnode; ht[i].RC = rnode;
		ht[lnode].parent = i; ht[rnode].parent = i;
	}
}

void CreatHC(HTNode ht[], HCode hcd[], int n0)            //����������
{
	int i, f, c;
	HCode hc;                                            //����һ���½ڵ������洢
	for (i = 0; i < n0; i++)
	{
		hc.start = n0; c = i;
		f = ht[i].parent;
		while (f != -1)                                  //��˫�ײ�Ϊͷ�ڵ�������
		{
			if (ht[f].LC == c)
				hc.cd[hc.start--] = '0';                  //����Ϊ0
			else
				hc.cd[hc.start--] = '1';                  //�Һ���Ϊ1
			c = f; f = ht[f].parent;
		}
		hc.start++;
		hcd[i] = hc;
	}
}

void Disp(HTNode ht[], HCode hcd[], int n0)              //�������������
{
	for (int i = 0; i < n0; i++)
	{
		if (ht[i].data == NULL)
			break;
		cout << ht[i].data << "�Ĺ���������Ϊ��";
		for (int k = hcd[i].start; k <= n0; k++)
			cout << hcd[i].cd[k];
		cout << endl;
	}
}

void WPL(HTNode ht[], HCode hcd[], int n0)              //����С��Ȩ·��
{
	double WPL = 0;
	for (int i = 0; i < n0; i++)
		WPL = WPL + ht[i].weight * (n0 - hcd[i].start + 1);      //��ͷ�ڵ�ľ���������б���ĸ���
	cout << "��С��Ȩ·������Ϊ��" << WPL;
}

int main()
{
	HTNode p[2*N-1];
	HCode p1[N];
	double b[N] = { 0.07,0.19,0.02,0.06,0.32,0.03,0.21,0.10 };
	char a[N] = { 'A','B','C','D','E','F','G','H' };
	for (int i = 0; i < 2 * N - 1; i++)
	{
		p[i].data = a[i];
		p[i].weight = b[i];
	}
	CreatHT(p, N);
	CreatHC(p, p1, N);
	Disp(p, p1, N);
	WPL(p, p1, N);
}