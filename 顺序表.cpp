#include<iostream>
using namespace std;

#define MaxSize 100
typedef char ElemType;
typedef struct
{
	ElemType date[MaxSize];
	int length;
}SqList;

void InitList(SqList*& L)
{
	L = new SqList;
}

void ListInsert(SqList*& L, int i, ElemType e)
{
	int j;
	if (i<1 || i>L->length + 1 || L->length == MaxSize)
		cout << "����ʧ��" << endl;
	i--;
	for (j = L->length; j > i; j--)
		L->date[j] = L->date[j - 1];
	L->date[i] = e;
	L->length++;
	cout << "����ɹ�" << endl;
}

void DispList(SqList* L)
{
	for (int i = 0; i < L->length; i++)
		cout << L->date[i] << " ";
}

int ListLength(SqList* L)
{
	return (L->length);
}

void ListEmpty(SqList* L)
{
	if (L->length == 0)
		cout << "�����Ա�Ϊ��" << endl;
	else
		cout << "�����Ա�Ϊ��" << endl;
}

void GetElem(SqList* L, int i, ElemType& e)
{
	e = L->date[i - 1];
	cout << "���ҵ���Ԫ��Ϊ��" << e << endl;
}

void LocateElem(SqList* L, ElemType e)
{
	int i = 0;
	while (i < L->length && L->date[i] != e)
		i++;
	if (i >= L->length)
		cout << "û���ҵ���Ԫ��" << endl;
	else
		cout << "�����ҵ�Ԫ��λ��Ϊ��" << i + 1 << endl;
}

void ListDelete(SqList*& L, int i, ElemType &e)
{
	if (i<1 || i>L->length)
		cout << "�����������" << endl;
	i--;
	e = L->date[i];
	for (int j = i; j < L->length - 1; j++)
		L->date[j] = L->date[j + 1];
	L->length--;
	cout << "ɾ���ɹ�" << endl;
}

void DestroyList(SqList*& L)
{
	delete(L);
}

void CreateList(SqList*& L, ElemType a[], int n)
{
	for (int i = 0; i < n; i++)
		L->date[i] = a[i];
	L->length = n;
}

void main()
{
	SqList* L1;
	InitList(L1);                                      //��ʼ�����Ա�
	ElemType a[5] = { 'A','B','C','D','E' },b,c,d;           
	CreateList(L1,a,5);                                //�������Ա�
	cout << "��������Ա�Ԫ���У�" << endl;
	DispList(L1);                                      //������Ա�
	cout << endl;

	cout << "���Ա�ĳ���Ϊ��" << ListLength(L1) << endl;       //������Ա�ĳ���

	ListEmpty(L1);                                      //�ж����Ա��Ƿ�Ϊ��

	cout << "������Ҫ��ѯ��Ԫ�ص�λ�ã�" << endl;      //����Ԫ��
	int k;
	for (int i = 0; ;i++)
	{
		cin >> k;
		int flag = 0;
		if (k<1 || k>L1->length)
			flag = 1;
		if (flag == 1)
			cout << "���������������������" << endl;
		else
			break;
	}
	GetElem(L1, k, b);

	cout << "��������Ҫ��ѯ��Ԫ�أ�";                 //����Ԫ�ص�λ��
	cin >> c;
	LocateElem(L1, c);
	ListInsert(L1, 4, 'F');
	DispList(L1);

	cout << "\n������Ҫɾ��Ԫ�ص�λ��Ϊ��";           //ɾ��Ԫ��
	int m;
	cin >> m;
	ListDelete(L1, m,d);

	cout << "��ɾ����Ԫ��Ϊ��" << d;
	DestroyList(L1);                                 //�������Ա�
}