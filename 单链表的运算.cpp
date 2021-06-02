#include<iostream>
using namespace std;

typedef char ElemType;
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

void CreateList(LinkNode*& L, ElemType a[], int n)
{
	LinkNode* s, * r;
	r = L;
	for (int i = 0; i < n; i++)
	{
		s = new LinkNode;
		s->date = a[i];
		r->next = s;
		r = s;
	}
	r->next = NULL;
}

void DispList(LinkNode* L)
{
	LinkNode* k = L->next;
	while (k != NULL)
	{
		cout << k->date << " ";
		k = k->next;
	}
	cout << endl;
}

void Lenlist(LinkNode* L)
{
	int i = 0;
	LinkNode* k = L->next;
	while (k != NULL)
	{
		i++;
		k = k->next;
	}
	cout << i << endl;
}

bool ListEmpty(LinkNode* L)
{
	return(L->next == NULL);
}

void ListDisp(LinkNode* L, int n)
{
	LinkNode* p = L->next;
	int i = 1;
	while (i!=n)
	{
		i++;
		p = p->next;
	}
	cout << p->date << endl;
}

void LocateElem(LinkNode* L, ElemType e)
{
	int i = 1;
	LinkNode* k = L->next;
	while (k != NULL && k->date != e)
	{
		k = k->next;
		i++;
	}
	if (k == NULL)
		cout << "û���ҵ���Ԫ��" << endl;
	else
		cout << i << endl;
}

void ListInsert(LinkNode*& L, int i, ElemType e)
{
	LinkNode* k = L, * s;
	int j = 1;
	while (j != i)
	{
		j++;
		k = k->next;
	}
	s = new LinkNode;
	s->date = e;
	s->next = k->next;
	k->next = s;
}

void ListDelete(LinkNode*& L, int i)
{
	int k = 1;
	LinkNode* p = L,*s;
	while (k != i)
	{
		k++;
		p = p->next;
	}
	s = p->next;
	p->next = s->next;
	free(s);
}

void DeleteList(LinkNode*& L)
{
	LinkNode* p = L, * k = L->next;
	for(int i=0;;i++)
	{
		delete(p);
		p = k;
		if (p != NULL)
			k = p->next;
		else
			break;
	}
	delete(p);
}

void main()
{
	LinkNode* L1;
	InitList(L1);
	ElemType a[5] = { 'A','B','C','D','E' },b,c;
	CreateList(L1, a, 5);
	DispList(L1);
	cout << "�ñ�ĳ���Ϊ��"; Lenlist(L1);
	if (ListEmpty(L1) == 1)
		cout << "�ñ�Ϊ��" << endl;
	else
		cout << "�ñ�Ϊ��" << endl;

	int k;
	cout << "������Ҫ���ҵ�λ�ã�";
	for (int i = 0; ; i++)
	{
		cin >> k;
		int flag = 0;
		if (k < 1 || k>5)
			flag = 1;
		if (flag == 1)
			cout << "���������������������" << endl;
		else
			break;
	}
	ListDisp(L1, k);

	cout << "������Ҫ���ҵ�Ԫ�أ�"; cin >> b;
	LocateElem(L1,b);

	int n;
	cout << "��Ҫ�����λ�ã�";  
	for (int i = 0; ; i++)
	{
		cin >> n;
		int flag = 0;
		if (n < 1 || n>6)
			flag = 1;
		if (flag == 1)
			cout << "���������������������" << endl;
		else
			break;
	}
	cout << "������Ҫ�����Ԫ�أ�"; cin >> c;
	ListInsert(L1, n, c);
	DispList(L1);

	int m;
	cout << "������Ҫɾ����λ�ã�"; cin >> m;
	ListDelete(L1, m);
	DispList(L1);

	DeleteList(L1);
}