#include<iostream>
using namespace std;

typedef int ElemType;                               //初始定义
typedef struct LNode                                //单链表的定义
{
	ElemType data;
	struct LNode* next;
}LinkNode;

void Con(LinkNode*& L, int a[], int n)               //创建
{
	if (n == 8)
		return;
	else
	{
		L = new LinkNode;
		L->data = a[n];
		L->next = NULL;
		n++;
		Con(L->next, a, n);                       //递归创建
	}
}

void Out(LinkNode* L)                            //正向输出
{
	if (L->next == NULL)
		cout << L->data << " ";
	else
	{
		cout << L->data << " ";
		Out(L->next);                           //递归下一个节点
	}
}

void Num(LinkNode* L,int& n)                      //节点个数
{
	if (L->next == NULL)
		return;
	else
	{
		n++;
		Num(L->next, n);                               //递归下一个节点，这个应该还可以再优化一下的
	}
}

void InOut(LinkNode* L)                                          //逆向输出
{
	if (L->next != NULL)
		InOut(L->next);                                          //在这一步没有停止前是不会执行下一步的输出的
	cout << L->data << " ";
	return;                                                   //递归实现逆向输出
}

void Dis(LinkNode* L,int n)                                          //输出指定点的值
{
	int k; cout << "输入要查询的位置为："; cin >> k;
	if (k > n || k < 1)
	{
		cout << "请重新输入" << endl;
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
		cout << "该位置的值为：" << p->data << endl;
		return;
	}
}

void Inser(LinkNode*& L, int n)                                     //插入函数
{
	int k; cout << "输入要插入的位置"; cin >> k;
	if (k > n + 1 || k < 1)
	{
		cout << "输入有误，请重新输入" << endl;
		Inser(L, n);
	}
	else
	{
		ElemType e; cout << "输入要插入的值为："; cin >> e;
		if (k == 1)                                                  //因为要求不带头节点，所以我就分类了第一个节点的情况
		{
			LinkNode* k; k = new LinkNode;
			k->data = e;
			k->next = L;
			L = k; return;
		}
		int j = 1;
		LinkNode* J, * p = L;
		while (j != k - 1)                                       //非第一个节点的情况
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

void Delete(LinkNode*& L, int n)                                     //删除位置
{
	int k; cout << "输入要删除的位置为："; cin >> k;
	if (k > n || k < 1)
	{
		cout << "输入有误，请重新输入" << endl;
		Delete(L,n);
	}
	else
	{
		int j = 1;
		LinkNode* J, * p = L;
		if (k == 1)                                              //因为要求不带头节点，所以我就分类了第一个节点的情况
		{
			J = p;
			p = J->next;
			L = p;
			delete(J);
			return;
		}
		while (j != k - 1)                                        //非第一个节点的情况
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

void DeleteOne(LinkNode*& L, ElemType e)                 //删除一个元素
{
	LinkNode* p;
	if (L == NULL) 
		return;
	else if(L->data == e) 
	{
		p = L;
		L = L->next;
		delete(p); return;                               //递归的终止条件
	}
	else 
		DeleteOne(L->next, e);                          //递归步骤
}

void DeleteAll(LinkNode*& L, ElemType e)               //删除所有元素
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
		DeleteAll(L->next, e);                          //这个其实和上面的一样
}

void Seach(LinkNode* L,LinkNode* j ,ElemType e,int i)                           //查找元素
{
	if (L->next == NULL)
	{
		ElemType k;
		cout << "链表中不存在该值，请重新输入："; cin >> k;
		L = j;
		Seach(L, j, k, 1);
	}
	else
	{
		if (L->data == e)
		{
			cout << "该值的位置为：" << i << endl; return;
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
	Con(L, a, 0);                                                                  //创建链表
	cout << "正向输出为："; Out(L);
	Num(L, n); cout << "\n" << "单链表中数据结点个数为：" << n << endl;
	cout << "逆向输出为："; InOut(L);

	cout << endl;
	Dis(L,n);                                                              //输出指定节点的值

	cout << endl;
	Inser(L, n);                                                         //插入一个节点
	cout << "链表排序为："; Out(L); cout << endl;

	cout << endl;
	n = 1;                                                         //重置n=1
	Num(L, n);                                                     //统计节点个数
	Delete(L, n);                                                   //删除节点
	cout << "删除后的链表排序为："; Out(L); 

	ElemType m;
	cout << "\n\n" << "请输入要删除的元素为："; cin >> m;
	DeleteOne(L, m);                                                          //删除一个节点
	cout << "链表排序为："; Out(L); cout << endl;

	ElemType t;
	cout << "\n\n" << "请输入要删除所有的元素为："; cin >> t;
	DeleteAll(L, t);                                                         //删除所有节点
	cout << "链表排序为："; Out(L); cout << endl;

	cout << endl;
	LinkNode* j = L;
	ElemType e; cout << "输入要查找到值："; cin >> e;
	Seach(L, j, e, 1);                                                  //查找元素

	delete(L);                                                    //销毁链表
}