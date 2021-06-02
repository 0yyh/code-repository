#include<iostream>
using namespace std;

typedef char ElemType;
typedef struct node                                    //定义二叉树
{
	ElemType data;
	struct node* LC;
	struct node* RC;
}BTNode;

void CreatBTree(BTNode*& b, char str[])                      //二叉树的建立
{
	BTNode* St[1000], * p = NULL;
	int top = -1, k, j = 0;
	char ch;
	b = NULL;
	ch = str[j];
	while (ch != '\0')                                        //当字符不为终止时继续
	{
		switch (ch)
		{
		case'(':top++; St[top] = p; k = 1; break;                //左括号进栈并改变K的值
		case')':top--; break;                                    //右括号出栈
		case',':k = 2; break;                                    //逗号说明有右节点，改变k的值
		default:p = new BTNode;                                  //建立一个新的节点并分配空间
			p->data = ch;
			p->LC = p->RC = NULL;                               //录入数据
			if (b == NULL)
				b = p;
			else
			{
				switch (k)
				{
				case 1:St[top]->LC = p; break;                  //左右节点的指向
				case 2:St[top]->RC = p; break;
				}
			}
		}
		j++;                                                    //下一个字符的判断
		ch = str[j];
	}
}

void Disp(BTNode* b)                                           //输出二叉树，带括号
{
	if (b != NULL)
	{
		cout << b->data;                                       //先输出头节点
		if (b->LC != NULL || b->RC != NULL)
		{
			cout << "(";
			Disp(b->LC);
			if (b->RC != NULL)
				cout << ",";
			Disp(b->RC);
			cout << ")";
		}
	}
}

BTNode* Find(BTNode* b, ElemType x)                         //查找特定值的节点
{
	BTNode* p;
	if (b == NULL)
		return NULL;
	else if (b->data == x)
		return b;
	else
	{
		p = Find(b->LC, x);                               //左节点的递归
		if (p != NULL)
			return p;
		else
			return Find(b->RC, x);                       //右节点的递归
	}
}

void Dis(BTNode* b)                                     //输出给定节点的左右孩子
{
	cout << b->LC->data;
	cout << b->RC->data;
}

int Height(BTNode* b)                                  //二叉树的高度
{

	int Lc, Rc;
	if (b == NULL)
		return 0;
	else
	{
		Lc = Height(b->LC);                           //递归左孩子
		Rc = Height(b->RC);                          //递归右节点
		return(Lc > Rc) ? (Lc + 1) : (Rc + 1);
	}
}

int n = 0;                                           //全局变量n为总结点的个数
void Count(BTNode* b)
{
	if (b != NULL)
	{
		n++;
		Count(b->LC);                              //递归左右孩子
		Count(b->RC);
	}
}

int i = 0;                                           //全局变量i为双节点的个数
void CountD(BTNode* b)
{
	if (b->LC && b->RC)                              //当左右孩子都存在的情况下
	{
		i++;
		CountD(b->LC);
		CountD(b->RC);
	}
	else if (b->LC)                                  //当左孩子存在时进行递归
	{
		CountD(b->LC);
	}
	else if (b->RC)                                   //当右孩子存在时进行递归
	{
		CountD(b->RC);
	}
	else if (b == NULL)
		return;
}

int t = 0;                                            //全局变量t为单节点的个数
void CountO(BTNode* b)
{
	if (b->LC && b->RC)                              //若左右孩子都存在则递归去到下一层
	{
		CountO(b->LC);
		CountO(b->RC);
	}
	if (b->LC && !b->RC )                           //仅有左孩子
	{
		t++;
		CountO(b->LC);
	}
	if (b->RC && !b->LC)                              //仅有右孩子
	{
		t++;
		CountO(b->RC);
	}
}

int m = 0;                                        //全局变量m为叶子节点的个数
void CountL(BTNode* b)
{
	if (b != NULL)
	{
		CountL(b->LC);                           //递归左右孩子
		CountL(b->RC);
		if (!b->LC && !b->RC)                    //访问并判断左右孩子是否符合条件
		{
			m++;
		}
	}
}

int a[100] = { 0 }, MAX = -1;                    //全局定义数组用来储存每一层的宽度，MAX为层数的最大值
void Width(BTNode* b,int k)
{
	if (b == NULL)
		return;
	else
		a[k]++;                                //层数的宽度加一
	if (MAX < a[k])
		MAX = a[k];                             //在这里进行比较就不用再循环求出最大值了
	Width(b->LC, k + 1);                        //左孩子递归到下一层
	Width(b->RC, k + 1);                        //右孩子递归到下一层
}

void Destroy(BTNode*& b)                       //销毁二叉树
{
	if (b != NULL)
	{
		Destroy(b->LC);
		Destroy(b->RC);
		delete(b);
	}
}

int main()
{
	BTNode* B;
	char a[] = { "A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))" };
	CreatBTree(B, a);
	Disp(B);

	cout << endl;
	BTNode* p;
	ElemType e; cin >> e;
	p = Find(B, e);
	while (p == NULL)
	{
		cout << "你的输入有误，请重新输入："; cin >> e;
		p = Find(B, e);
	}
	if (p)
	{
		if (p->LC == NULL && p->RC != NULL)
			cout << "NULL" << " " << p->RC->data;
		if (p->RC == NULL && p->LC != NULL)
			cout << p->LC->data << " " << "NULL";
		if (p->LC == NULL && p->RC == NULL)
			cout << "该节点为叶节点";
		if (p->LC != NULL && p->RC != NULL)
			cout << p->LC->data << " " << p->RC->data;
	}

	int h;
	h = Height(B);
	cout << endl << "该树的高度为：" << h;

	Count(B);
	cout << endl << "节点的个数为：" << n;

	CountD(B);
	cout << endl << "双分支节点个数为：" << i;

	CountO(B);
	cout << endl << "单分支节点个数为：" << t;

	CountL(B);
	cout << endl << "叶子节点个数为：" << m;

	Width(B, 0);
	cout << endl << "宽度为：" << MAX;

	Destroy(B);
}