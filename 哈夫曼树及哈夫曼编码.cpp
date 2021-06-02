#include<iostream>
using namespace std;

#define N 9
typedef struct									//哈夫曼树节点的结构
{
	char data;
	double weight;
	int parent, LC, RC;
}HTNode;

typedef struct                                //哈夫曼编码的节点结构
{
	char cd[N];
	int start;
}HCode;

void CreatHT(HTNode ht[], int n0)                            //创建哈夫曼树
{
	int  lnode, rnode;                                      //lnode为最小节点的下标，rnode为次最小节点的下标
	double min1, min2;                                      //min1为最小权值，min2为次最小权值
	for (int i = 0; i < 2 * n0 - 1; i++)
		ht[i].parent = ht[i].LC = ht[i].RC = -1;            //初始化
	for (int i = n0; i <= 2 * n0 - 2; i++)                  //对新节点的操作
	{
		min1 = min2 = 1000;
		lnode = rnode = -1;
		for (int k = 0; k <= i - 1; k++)					//对所有节点进行操作
		{
			if (ht[k].parent == -1)
			{
				if (ht[k].weight < min1)                   //权值为最小值的情况下
				{
					min2 = min1; rnode = lnode;            //把原来的最小值变为次最小值
					min1 = ht[k].weight; lnode = k;
				}
				else if (ht[k].weight < min2)             //权值比次最小值小单比最小值大的情况下
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

void CreatHC(HTNode ht[], HCode hcd[], int n0)            //哈夫曼编码
{
	int i, f, c;
	HCode hc;                                            //定义一个新节点用来存储
	for (i = 0; i < n0; i++)
	{
		hc.start = n0; c = i;
		f = ht[i].parent;
		while (f != -1)                                  //当双亲不为头节点的情况下
		{
			if (ht[f].LC == c)
				hc.cd[hc.start--] = '0';                  //左孩子为0
			else
				hc.cd[hc.start--] = '1';                  //右孩子为1
			c = f; f = ht[f].parent;
		}
		hc.start++;
		hcd[i] = hc;
	}
}

void Disp(HTNode ht[], HCode hcd[], int n0)              //输出哈夫曼编码
{
	for (int i = 0; i < n0; i++)
	{
		if (ht[i].data == NULL)
			break;
		cout << ht[i].data << "的哈夫曼编码为：";
		for (int k = hcd[i].start; k <= n0; k++)
			cout << hcd[i].cd[k];
		cout << endl;
	}
}

void WPL(HTNode ht[], HCode hcd[], int n0)              //求最小带权路径
{
	double WPL = 0;
	for (int i = 0; i < n0; i++)
		WPL = WPL + ht[i].weight * (n0 - hcd[i].start + 1);      //和头节点的距离等于已有编码的个数
	cout << "最小带权路径长度为：" << WPL;
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