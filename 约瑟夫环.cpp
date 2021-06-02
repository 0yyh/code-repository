#include<iostream>
using namespace std;

typedef int ElemType;
typedef struct LNode
{
	ElemType data;
	struct LNode* next;
}LinkNode;

void InitLink(LinkNode*& L)                                    //初始化链表
{
	L = new LinkNode;
	L->next = NULL;
}

void CreateLink(LinkNode*& L, ElemType N)                    //建立循环链表
{
	LinkNode* p, * r;
	r = L;
	r->data = 1;
	for (int i = 2; i <= N; i++)
	{
		InitLink(p);
		p->data = i;
		r->next = p;
		r = p;
	}
	r->next = L;                                               //循环链表的标志
}

void DispLink(LinkNode* L)                                   //链表的输出
{
	LinkNode* p;
	p = L->next;
	cout << L->data << " ";
	while (p != L)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

void YSF(LinkNode* L,ElemType M,ElemType K)
{
	LinkNode* p, * r,* j;
	p = L; r = L; 
	for (int i = 1; i < M; i++)
	{
		p = p->next;
	} 
	j = p;                                                             //j 是和 p 挂钩的，用来判断j 和 p是不是在一起
	if (K != 1)                                                        //这是当死亡数字不为1的情况
	{
		while (p->next != j)                                           //如果j p 不在一起说明这个链表的数据节点起码在两个以上
		{
			int i = 1;
			while (i != K - 1)                                        //找到要 死 的那个位置的前一位
			{
				i++;
				p = p->next;          
			}
			r = p; cout << r->next->data << " ";                     //先标记要死的那个位置，先把要死的位置的数据输出
			r->next = p->next->next; p = r->next; j = p;             //然后删除掉死掉的那个节点
		}
		cout << p->data;
	}
	else                                                            //这里是当死亡数字为 1 的情况
	{
		while (p->next != j)
		{
			cout << p->data << " ";
			p = p->next;
		}
		cout << p->data;
	}
}

void main()                                                                            
{
	LinkNode* L1; InitLink(L1);
	ElemType N; cout << "请输入总人数："; cin >> N;
	CreateLink(L1, N);
	DispLink(L1);

	ElemType M, K;
	cout << "请输入开始报数的位置："; cin >> M;
	cout << "请输入死亡数字："; cin >> K;
	cout << "死亡顺序为："; YSF(L1, M, K);
	cout << endl;
}