#include<iostream>
using namespace std;

typedef int ElemType;
typedef struct LNode
{
	ElemType date;
	struct LNode* next;
}LinkNode;

void InitList(LinkNode*& L)
{
	L = new LinkNode;
	L->next = NULL;
}

void FList(LinkNode*& L, int e)
{
	LinkNode * s;
	InitList(s);
	s->date = e;
	s->next = L->next;
	L->next = s;
}
void main()
{
	LinkNode* L1; InitList(L1); L1->next = NULL;
	LinkNode* k; InitList(k); k->next = L1->next; L1->next = k;
	k->date = 1;
	LinkNode* s; 
	int n; cin >> n;
	for (int i = 2; i <= n; i++)
	{
		int sum = 0;
		k = L1;
		while (k->next)
		{
			k = k->next;
			k->date = k->date * i + sum;
			sum = k->date / 10;
			k->date = k->date % 10;
		}
		while (sum)
		{
			InitList(s);
			k->next = s;
			s->date = sum % 10;
			sum = sum / 10;
			k = s;
		}
	}
	LinkNode* L2; InitList(L2);
	for (L1=L1->next; L1; L1 = L1->next)
		FList(L2, L1->date);
	int i = 0;
	k = L2;
	while (k->next != NULL)
	{
		k = k->next;
		i++;
	}
	cout << "一共有" << i << "位数" << endl;
	while (L2->next != NULL)
	{
		cout << L2->next->date;
		L2 = L2->next;
	}
	
}