#include<iostream>
using namespace std;

typedef char ElemType;
typedef struct node                                    //���������
{
	ElemType data;
	struct node* LC;
	struct node* RC;
}BTNode;

void CreatBTree(BTNode*& b, char str[])                      //�������Ľ���
{
	BTNode* St[1000], * p = NULL;
	int top = -1, k, j = 0;
	char ch;
	b = NULL;
	ch = str[j];
	while (ch != '\0')                                        //���ַ���Ϊ��ֹʱ����
	{
		switch (ch)
		{
		case'(':top++; St[top] = p; k = 1; break;                //�����Ž�ջ���ı�K��ֵ
		case')':top--; break;                                    //�����ų�ջ
		case',':k = 2; break;                                    //����˵�����ҽڵ㣬�ı�k��ֵ
		default:p = new BTNode;                                  //����һ���µĽڵ㲢����ռ�
			p->data = ch;
			p->LC = p->RC = NULL;                               //¼������
			if (b == NULL)
				b = p;
			else
			{
				switch (k)
				{
				case 1:St[top]->LC = p; break;                  //���ҽڵ��ָ��
				case 2:St[top]->RC = p; break;
				}
			}
		}
		j++;                                                    //��һ���ַ����ж�
		ch = str[j];
	}
}

void Disp(BTNode* b)                                           //�����������������
{
	if (b != NULL)
	{
		cout << b->data;                                       //�����ͷ�ڵ�
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

BTNode* Find(BTNode* b, ElemType x)                         //�����ض�ֵ�Ľڵ�
{
	BTNode* p;
	if (b == NULL)
		return NULL;
	else if (b->data == x)
		return b;
	else
	{
		p = Find(b->LC, x);                               //��ڵ�ĵݹ�
		if (p != NULL)
			return p;
		else
			return Find(b->RC, x);                       //�ҽڵ�ĵݹ�
	}
}

void Dis(BTNode* b)                                     //��������ڵ�����Һ���
{
	cout << b->LC->data;
	cout << b->RC->data;
}

int Height(BTNode* b)                                  //�������ĸ߶�
{

	int Lc, Rc;
	if (b == NULL)
		return 0;
	else
	{
		Lc = Height(b->LC);                           //�ݹ�����
		Rc = Height(b->RC);                          //�ݹ��ҽڵ�
		return(Lc > Rc) ? (Lc + 1) : (Rc + 1);
	}
}

int n = 0;                                           //ȫ�ֱ���nΪ�ܽ��ĸ���
void Count(BTNode* b)
{
	if (b != NULL)
	{
		n++;
		Count(b->LC);                              //�ݹ����Һ���
		Count(b->RC);
	}
}

int i = 0;                                           //ȫ�ֱ���iΪ˫�ڵ�ĸ���
void CountD(BTNode* b)
{
	if (b->LC && b->RC)                              //�����Һ��Ӷ����ڵ������
	{
		i++;
		CountD(b->LC);
		CountD(b->RC);
	}
	else if (b->LC)                                  //�����Ӵ���ʱ���еݹ�
	{
		CountD(b->LC);
	}
	else if (b->RC)                                   //���Һ��Ӵ���ʱ���еݹ�
	{
		CountD(b->RC);
	}
	else if (b == NULL)
		return;
}

int t = 0;                                            //ȫ�ֱ���tΪ���ڵ�ĸ���
void CountO(BTNode* b)
{
	if (b->LC && b->RC)                              //�����Һ��Ӷ�������ݹ�ȥ����һ��
	{
		CountO(b->LC);
		CountO(b->RC);
	}
	if (b->LC && !b->RC )                           //��������
	{
		t++;
		CountO(b->LC);
	}
	if (b->RC && !b->LC)                              //�����Һ���
	{
		t++;
		CountO(b->RC);
	}
}

int m = 0;                                        //ȫ�ֱ���mΪҶ�ӽڵ�ĸ���
void CountL(BTNode* b)
{
	if (b != NULL)
	{
		CountL(b->LC);                           //�ݹ����Һ���
		CountL(b->RC);
		if (!b->LC && !b->RC)                    //���ʲ��ж����Һ����Ƿ��������
		{
			m++;
		}
	}
}

int a[100] = { 0 }, MAX = -1;                    //ȫ�ֶ���������������ÿһ��Ŀ�ȣ�MAXΪ���������ֵ
void Width(BTNode* b,int k)
{
	if (b == NULL)
		return;
	else
		a[k]++;                                //�����Ŀ�ȼ�һ
	if (MAX < a[k])
		MAX = a[k];                             //��������бȽϾͲ�����ѭ��������ֵ��
	Width(b->LC, k + 1);                        //���ӵݹ鵽��һ��
	Width(b->RC, k + 1);                        //�Һ��ӵݹ鵽��һ��
}

void Destroy(BTNode*& b)                       //���ٶ�����
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
		cout << "��������������������룺"; cin >> e;
		p = Find(B, e);
	}
	if (p)
	{
		if (p->LC == NULL && p->RC != NULL)
			cout << "NULL" << " " << p->RC->data;
		if (p->RC == NULL && p->LC != NULL)
			cout << p->LC->data << " " << "NULL";
		if (p->LC == NULL && p->RC == NULL)
			cout << "�ýڵ�ΪҶ�ڵ�";
		if (p->LC != NULL && p->RC != NULL)
			cout << p->LC->data << " " << p->RC->data;
	}

	int h;
	h = Height(B);
	cout << endl << "�����ĸ߶�Ϊ��" << h;

	Count(B);
	cout << endl << "�ڵ�ĸ���Ϊ��" << n;

	CountD(B);
	cout << endl << "˫��֧�ڵ����Ϊ��" << i;

	CountO(B);
	cout << endl << "����֧�ڵ����Ϊ��" << t;

	CountL(B);
	cout << endl << "Ҷ�ӽڵ����Ϊ��" << m;

	Width(B, 0);
	cout << endl << "���Ϊ��" << MAX;

	Destroy(B);
}