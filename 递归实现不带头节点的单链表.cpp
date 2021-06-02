#include<iostream>
using namespace std;

typedef int ElemType;                               //��ʼ����
typedef struct LNode                                //������Ķ���
{
	ElemType data;
	struct LNode* next;
}LinkNode;

void Con(LinkNode*& L, int a[], int n)               //����
{
	if (n == 8)
		return;
	else
	{
		L = new LinkNode;
		L->data = a[n];
		L->next = NULL;
		n++;
		Con(L->next, a, n);                       //�ݹ鴴��
	}
}

void Out(LinkNode* L)                            //�������
{
	if (L->next == NULL)
		cout << L->data << " ";
	else
	{
		cout << L->data << " ";
		Out(L->next);                           //�ݹ���һ���ڵ�
	}
}

void Num(LinkNode* L,int& n)                      //�ڵ����
{
	if (L->next == NULL)
		return;
	else
	{
		n++;
		Num(L->next, n);                               //�ݹ���һ���ڵ㣬���Ӧ�û��������Ż�һ�µ�
	}
}

void InOut(LinkNode* L)                                          //�������
{
	if (L->next != NULL)
		InOut(L->next);                                          //����һ��û��ֹͣǰ�ǲ���ִ����һ���������
	cout << L->data << " ";
	return;                                                   //�ݹ�ʵ���������
}

void Dis(LinkNode* L,int n)                                          //���ָ�����ֵ
{
	int k; cout << "����Ҫ��ѯ��λ��Ϊ��"; cin >> k;
	if (k > n || k < 1)
	{
		cout << "����������" << endl;
		Dis(L, n);
	}
	else
	{
		int j = 1;
		LinkNode* p = L;
		while (j != k)
		{
			j++;
			p = p->next;
		}
		cout << "��λ�õ�ֵΪ��" << p->data << endl;
		return;
	}
}

void Inser(LinkNode*& L, int n)                                     //���뺯��
{
	int k; cout << "����Ҫ�����λ��"; cin >> k;
	if (k > n + 1 || k < 1)
	{
		cout << "������������������" << endl;
		Inser(L, n);
	}
	else
	{
		ElemType e; cout << "����Ҫ�����ֵΪ��"; cin >> e;
		if (k == 1)                                                  //��ΪҪ�󲻴�ͷ�ڵ㣬�����Ҿͷ����˵�һ���ڵ�����
		{
			LinkNode* k; k = new LinkNode;
			k->data = e;
			k->next = L;
			L = k; return;
		}
		int j = 1;
		LinkNode* J, * p = L;
		while (j != k - 1)                                       //�ǵ�һ���ڵ�����
		{
			j++;
			p = p->next;
		}
		J = new LinkNode;
		J->data = e;
		J->next = p->next;
		p->next = J;
		return;
	}
}

void Delete(LinkNode*& L, int n)                                     //ɾ��λ��
{
	int k; cout << "����Ҫɾ����λ��Ϊ��"; cin >> k;
	if (k > n || k < 1)
	{
		cout << "������������������" << endl;
		Delete(L,n);
	}
	else
	{
		int j = 1;
		LinkNode* J, * p = L;
		if (k == 1)                                              //��ΪҪ�󲻴�ͷ�ڵ㣬�����Ҿͷ����˵�һ���ڵ�����
		{
			J = p;
			p = J->next;
			L = p;
			delete(J);
			return;
		}
		while (j != k - 1)                                        //�ǵ�һ���ڵ�����
		{
			j++;
			p = p->next;
		}
		J = p->next;
		p->next = J->next;
		delete(J);
		return;
	}
}

void DeleteOne(LinkNode*& L, ElemType e)                 //ɾ��һ��Ԫ��
{
	LinkNode* p;
	if (L == NULL) 
		return;
	else if(L->data == e) 
	{
		p = L;
		L = L->next;
		delete(p); return;                               //�ݹ����ֹ����
	}
	else 
		DeleteOne(L->next, e);                          //�ݹ鲽��
}

void DeleteAll(LinkNode*& L, ElemType e)               //ɾ������Ԫ��
{
	LinkNode* p;
	if (L == NULL) 
		return;
	else if (L->data == e)
	{
		p = L;
		L = L->next;
		delete(p); 
		DeleteAll(L, e);
	}
	else
		DeleteAll(L->next, e);                          //�����ʵ�������һ��
}

void Seach(LinkNode* L,LinkNode* j ,ElemType e,int i)                           //����Ԫ��
{
	if (L->next == NULL)
	{
		ElemType k;
		cout << "�����в����ڸ�ֵ�����������룺"; cin >> k;
		L = j;
		Seach(L, j, k, 1);
	}
	else
	{
		if (L->data == e)
		{
			cout << "��ֵ��λ��Ϊ��" << i << endl; return;
		}
		else
		{
			i++;
			Seach(L->next, j, e, i);
		}
	}
}



int main()
{
	LinkNode* L;
	int n = 1;
	int a[8] = { 13,15,8,4,8,3,4,8 };
	Con(L, a, 0);                                                                  //��������
	cout << "�������Ϊ��"; Out(L);
	Num(L, n); cout << "\n" << "�����������ݽ�����Ϊ��" << n << endl;
	cout << "�������Ϊ��"; InOut(L);

	cout << endl;
	Dis(L,n);                                                              //���ָ���ڵ��ֵ

	cout << endl;
	Inser(L, n);                                                         //����һ���ڵ�
	cout << "��������Ϊ��"; Out(L); cout << endl;

	cout << endl;
	n = 1;                                                         //����n=1
	Num(L, n);                                                     //ͳ�ƽڵ����
	Delete(L, n);                                                   //ɾ���ڵ�
	cout << "ɾ�������������Ϊ��"; Out(L); 

	ElemType m;
	cout << "\n\n" << "������Ҫɾ����Ԫ��Ϊ��"; cin >> m;
	DeleteOne(L, m);                                                          //ɾ��һ���ڵ�
	cout << "��������Ϊ��"; Out(L); cout << endl;

	ElemType t;
	cout << "\n\n" << "������Ҫɾ�����е�Ԫ��Ϊ��"; cin >> t;
	DeleteAll(L, t);                                                         //ɾ�����нڵ�
	cout << "��������Ϊ��"; Out(L); cout << endl;

	cout << endl;
	LinkNode* j = L;
	ElemType e; cout << "����Ҫ���ҵ�ֵ��"; cin >> e;
	Seach(L, j, e, 1);                                                  //����Ԫ��

	delete(L);                                                    //��������
}