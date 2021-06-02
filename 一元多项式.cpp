#include<iostream>
using namespace std;

typedef struct
{
	int xi;
	int zhi;
}ElemType;

typedef struct LNode
{
	ElemType data;
	struct LNode* next;
}LinkNode;

void InitList(LinkNode*& L)
{
	L = new LinkNode;
	L->next = NULL;
}

void Linkcr(LinkNode*& L, LinkNode* s)
{
	LinkNode* r;
	r = L;
	while (r->next && r->next->data.zhi < s->data.zhi)
	{
		r = r->next;
	}
	s->next = r->next;
	r->next = s;
}

void DispLink(LinkNode* L)
{
	int i = 0;
	cout << "f(x)=";
	while (L = L->next)
	{
		if (i)
			L->data.xi > 0 ? cout << "+" : cout << "-";
		else if (L->data.xi < 0)
			cout << "-";
		if (L->data.zhi == 0)
			cout << abs(L->data.xi);
		else
		{
			if (abs(L->data.xi) == 1)
			{
				if (L->data.zhi == 1 && L->data.xi == 1|| L->data.xi == -1)
					cout << "x";
				else
				cout << "x^" << L->data.zhi;
			}
			else
			{
				if (L->data.zhi == 1)
					cout << L->data.xi << "x";
				else
					cout << abs(L->data.xi) << "x^" << L->data.zhi;
			}
		}
		i++;
	}
}

void AddList(LinkNode* L1, LinkNode* L2, LinkNode*& L3)
{
	LinkNode* s, * k;
	s = L3; 
	while (L1->next)
	{
		InitList(k);
		k->data.xi = L1->next->data.xi; k->data.zhi = L1->next->data.zhi;
		s->next = k;
		s = k;
		L1 = L1->next;
	}
	LinkNode* p;
	while (L2->next)
	{
		int flag = 0;
		s = L3;
		while (s->next)
		{
			if (L2->next->data.zhi == s->next->data.zhi)
			{
				s->next->data.xi = s->next->data.xi + L2->next->data.xi;
				flag = 1;
			}
			s = s->next;
			
		}
		if (flag==0)
		{
			InitList(p);
			p->data = L2->next->data;
			Linkcr(L3, p);
		}
		L2 = L2->next;
	}
}

void MulLink(LinkNode* L1, LinkNode* L2, LinkNode*& L4)
{
	LinkNode* p1 = L1, * p2 = L2, * p3, * s;
	while (p1 = p1->next)
	{
		p2 = L2;
		while (p2 = p2->next)
		{
			InitList(s);
			s->data.xi = p1->data.xi * p2->data.xi;
			s->data.zhi = p1->data.zhi + p2->data.zhi;
			p3 = L4;
			while (p3 = p3->next)
			{
				if (s->data.zhi == p3->data.zhi)
				{
					p3->data.xi = p3->data.xi + s->data.xi;
					break;
				}
			}
			if (p3==NULL)
				Linkcr(L4, s);
		}
	}
}

void main()
{
	LinkNode* L1, * s;
	int a, b;
	InitList(L1);
	while (cin >> a >> b, a || b)
	{
		if (a == 0)
			continue;
		InitList(s);
		s->data.xi = a, s->data.zhi = b;
		Linkcr(L1, s);
	}
	cout << "第一个多项式为："; DispLink(L1); cout << endl;

	LinkNode* L2;
	int c, d;
	InitList(L2);
	while (cin >> c >> d, c || d)
	{
		if (c == 0)
			continue;
		InitList(s);
		s->data.xi = c, s->data.zhi = d;
		Linkcr(L2, s);
	}
	cout << "第二个多项式为："; DispLink(L2);

	LinkNode* L3; InitList(L3);
	AddList(L1, L2, L3); 
	cout << "\n多项式相加为："; DispLink(L3);

	LinkNode* L4; InitList(L4);
	MulLink(L1, L2, L4);
	cout << "\n多项式乘积为："; DispLink(L4);
}