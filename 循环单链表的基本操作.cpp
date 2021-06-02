#include<iostream>
using namespace std;

typedef char ElemType;
typedef struct LNode
{
	ElemType data;
	struct LNode* next;
}LinkNode;

void InitLink(LinkNode*& L)                                             //��ʼ�ڵ� ����
{
	L = new LinkNode;
	L->next = NULL;                                                     //��������Ϊ����Ҫ���Ǻ�Ū�������Ĳ���
}

void CreateLink(LinkNode*& L, ElemType a[],int n)                      //��������
{
	LinkNode* s, * r;
	r = L;
	for (int i = 0; i < n; i++)
	{
		s = new LinkNode;
		s->data = a[i];
		r->next = s;
		r = s;
	}
	r->next = L;                                                       //ѭ���ı�־
}

void DispLink(LinkNode* L)                                             //�������
{
	LinkNode* p;
	p = L->next; 
	while (p != L)                                                     //�����������Լ�
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

int Lenlist(LinkNode* L)                                            //�жϳ���
{
	int i = 0;
	LinkNode* k = L->next;
	while (k != L)
	{
		i++;
		k = k->next;
	}
	return(i);
}

bool ListEmpty(LinkNode* L)                                       //�ж��Ƿ�Ϊ��
{
	return(L->next == L);
}

void ListDisp(LinkNode* L, int n)                                
{
	LinkNode* p = L->next;
	int i = 1;
	while (i != n)
	{
		i++;
		p = p->next;
	}
	cout << p->data << endl;                                     //���������
}

void LocateElem(LinkNode* L, ElemType e)                         //��λԪ��
{
	int i = 1;
	LinkNode* k = L->next;
	while (k != L && k->data != e)
	{
		k = k->next;
		i++;
	}
	if (k == L)
		cout << "û���ҵ���Ԫ��" << endl;
	else
		cout << i << endl;
}

void ListInsert(LinkNode*& L, int i, ElemType e)              //����Ԫ��
{
	LinkNode* k = L, * s;
	int j = 1;
	while (j != i)
	{
		j++;
		k = k->next;
	}
	s = new LinkNode;
	s->data = e;
	s->next = k->next;
	k->next = s;
}

void ListDelete(LinkNode*& L, int i)                        //�����ɾ��
{
	int k = 1;
	LinkNode* p = L, * s;
	while (k != i)
	{
		k++;
		p = p->next;
	}
	s = p->next;
	p->next = s->next;
	free(s);
}

void DeleteList(LinkNode*& L)                            //������ͷ�
{
	LinkNode* p = L, * k = L->next, * r;
	r = k;
	while (k != p)                                      //������ͷź͵�������ͷ���Щ��Ĳ�һ��
	{
		k = k->next;                                    //����pָ��ͷ�ڵ㣨��ʵ��ҪҲ�У��ո������ÿ��㣩��k��ʼָ��������ݵĽڵ㣬����r����p
		delete(r);                                      //Ȼ��Ͱ�k��ǰŲһλ���ͷŵ�r
		r = k;
	}
	delete(p);
}

void main()
{
	LinkNode* L1;
	InitLink(L1);
	ElemType a[5] = { 'A','B','C','D','E' }, b, c;
	CreateLink(L1, a, 5);
	DispLink(L1);
	cout << "�ñ�ĳ���Ϊ��"; cout << Lenlist(L1) << endl;
	if (ListEmpty(L1) == 1)
		cout << "�ñ�Ϊ��" << endl;
	else
		cout << "�ñ�Ϊ��" << endl;

	int k;
	for (int i = 1; i <= 3; i++)                                 //ѭ������
	{
		cout << "������Ҫ���ҵ�λ�ã�";
		for (int i = 0;; i++)
		{
			cin >> k;
			int flag = 0;
			if (k < 1 || k>5)
				flag = 1;
			if (flag == 1)
				cout << "���������������������" << endl;             //�ж������Ƿ�����
			else
				break;
		}
		ListDisp(L1, k);
	}

	cout << "������Ҫ���ҵ�Ԫ�أ�"; cin >> b;
	LocateElem(L1, b);

	int n;
	for (int i = 1; i <= 3; i++)                                         //ѭ������
	{
		cout << "��Ҫ�����λ�ã�";
		for (int i = 0; ; i++)
		{
			cin >> n;
			int flag = 0;
			if (n < 1 || n>6)                                                //�ж������Ƿ�����
				flag = 1;
			if (flag == 1)
				cout << "���������������������" << endl;
			else
				break;
		}
		cout << "������Ҫ�����Ԫ�أ�"; cin >> c;
		ListInsert(L1, n, c);
		DispLink(L1);
	}

	int m;
	for (int i = 1; i <= 3; i++)
	{
		cout << "������Ҫɾ����λ�ã�"; 
		for (int i = 0; ; i++)
		{
			cin >> m;
			int flag = 0;
			int k = Lenlist(L1);
			if (m < 1 || m > k)                                                //�ж������Ƿ�����
				flag = 1;
			if (flag == 1)
				cout << "���������������������" << endl;                      //��ʵ�⼸��forѭ��Ҳ�ǿ��Թ���һ���Ӻ����ģ��е��鷳�����ˣ�
			else
				break;
		}
		ListDelete(L1, m);
		DispLink(L1);
	}

	DeleteList(L1);                                             
}