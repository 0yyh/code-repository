#include<iostream>
using namespace std;

typedef char ElemType;
typedef struct LNode
{
	ElemType data;
	struct LNode* next;
}LinkNode;

void InitLink(LinkNode*& L)                                             //初始节点 链表
{
	L = new LinkNode;
	L->next = NULL;                                                     //让这玩意为空主要就是好弄接下来的步骤
}

void CreateLink(LinkNode*& L, ElemType a[],int n)                      //创建链表
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
	r->next = L;                                                       //循环的标志
}

void DispLink(LinkNode* L)                                             //输出链表
{
	LinkNode* p;
	p = L->next; 
	while (p != L)                                                     //不让他等于自己
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

int Lenlist(LinkNode* L)                                            //判断长度
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

bool ListEmpty(LinkNode* L)                                       //判断是否为空
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
	cout << p->data << endl;                                     //输出数据域
}

void LocateElem(LinkNode* L, ElemType e)                         //定位元素
{
	int i = 1;
	LinkNode* k = L->next;
	while (k != L && k->data != e)
	{
		k = k->next;
		i++;
	}
	if (k == L)
		cout << "没有找到该元素" << endl;
	else
		cout << i << endl;
}

void ListInsert(LinkNode*& L, int i, ElemType e)              //插入元素
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

void ListDelete(LinkNode*& L, int i)                        //链表的删除
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

void DeleteList(LinkNode*& L)                            //链表的释放
{
	LinkNode* p = L, * k = L->next, * r;
	r = k;
	while (k != p)                                      //这个的释放和单链表的释放有些许的不一样
	{
		k = k->next;                                    //先令p指向头节点（其实不要也行，凑个奇数好看点），k开始指向带有数据的节点，再令r等于p
		delete(r);                                      //然后就把k往前挪一位，释放掉r
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
	cout << "该表的长度为："; cout << Lenlist(L1) << endl;
	if (ListEmpty(L1) == 1)
		cout << "该表为空" << endl;
	else
		cout << "该表不为空" << endl;

	int k;
	for (int i = 1; i <= 3; i++)                                 //循环三次
	{
		cout << "输入你要查找的位置：";
		for (int i = 0;; i++)
		{
			cin >> k;
			int flag = 0;
			if (k < 1 || k>5)
				flag = 1;
			if (flag == 1)
				cout << "你的输入有误，请重新输入" << endl;             //判断输入是否有误
			else
				break;
		}
		ListDisp(L1, k);
	}

	cout << "输入你要查找的元素："; cin >> b;
	LocateElem(L1, b);

	int n;
	for (int i = 1; i <= 3; i++)                                         //循环三次
	{
		cout << "你要插入的位置：";
		for (int i = 0; ; i++)
		{
			cin >> n;
			int flag = 0;
			if (n < 1 || n>6)                                                //判断输入是否有误
				flag = 1;
			if (flag == 1)
				cout << "你的输入有误，请重新输入" << endl;
			else
				break;
		}
		cout << "输入你要插入的元素："; cin >> c;
		ListInsert(L1, n, c);
		DispLink(L1);
	}

	int m;
	for (int i = 1; i <= 3; i++)
	{
		cout << "输入你要删除的位置："; 
		for (int i = 0; ; i++)
		{
			cin >> m;
			int flag = 0;
			int k = Lenlist(L1);
			if (m < 1 || m > k)                                                //判断输入是否有误
				flag = 1;
			if (flag == 1)
				cout << "你的输入有误，请重新输入" << endl;                      //其实这几个for循环也是可以构建一个子函数的（有点麻烦就算了）
			else
				break;
		}
		ListDelete(L1, m);
		DispLink(L1);
	}

	DeleteList(L1);                                             
}