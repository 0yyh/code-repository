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
		cout << "插入失败" << endl;
	i--;
	for (j = L->length; j > i; j--)
		L->date[j] = L->date[j - 1];
	L->date[i] = e;
	L->length++;
	cout << "插入成功" << endl;
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
		cout << "该线性表为空" << endl;
	else
		cout << "该线性表不为空" << endl;
}

void GetElem(SqList* L, int i, ElemType& e)
{
	e = L->date[i - 1];
	cout << "查找到的元素为：" << e << endl;
}

void LocateElem(SqList* L, ElemType e)
{
	int i = 0;
	while (i < L->length && L->date[i] != e)
		i++;
	if (i >= L->length)
		cout << "没有找到该元素" << endl;
	else
		cout << "所查找的元素位置为：" << i + 1 << endl;
}

void ListDelete(SqList*& L, int i, ElemType &e)
{
	if (i<1 || i>L->length)
		cout << "你的输入有误" << endl;
	i--;
	e = L->date[i];
	for (int j = i; j < L->length - 1; j++)
		L->date[j] = L->date[j + 1];
	L->length--;
	cout << "删除成功" << endl;
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
	InitList(L1);                                      //初始化线性表
	ElemType a[5] = { 'A','B','C','D','E' },b,c,d;           
	CreateList(L1,a,5);                                //建立线性表
	cout << "输出的线性表元素有：" << endl;
	DispList(L1);                                      //输出线性表
	cout << endl;

	cout << "线性表的长度为：" << ListLength(L1) << endl;       //输出线性表的长度

	ListEmpty(L1);                                      //判断线性表是否为空

	cout << "请输入要查询的元素的位置：" << endl;      //查找元素
	int k;
	for (int i = 0; ;i++)
	{
		cin >> k;
		int flag = 0;
		if (k<1 || k>L1->length)
			flag = 1;
		if (flag == 1)
			cout << "你的输入有误，请重新输入" << endl;
		else
			break;
	}
	GetElem(L1, k, b);

	cout << "请输入想要查询的元素：";                 //查找元素的位置
	cin >> c;
	LocateElem(L1, c);
	ListInsert(L1, 4, 'F');
	DispList(L1);

	cout << "\n请输入要删除元素的位置为：";           //删除元素
	int m;
	cin >> m;
	ListDelete(L1, m,d);

	cout << "所删除的元素为：" << d;
	DestroyList(L1);                                 //销毁线性表
}