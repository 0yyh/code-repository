#include<iostream>
using namespace std;

typedef int ElemType;
typedef struct LNode
{
	ElemType data;
	struct LNode* next;
}LinkNode;

void InitLink(LinkNode*& L)                                    //��ʼ������
{
	L = new LinkNode;
	L->next = NULL;
}

void CreateLink(LinkNode*& L, ElemType N)                    //����ѭ������
{
	LinkNode* p, * r;
	r = L;
	r->data = 1;
	for (int i = 2; i <= N; i++)
	{
		InitLink(p);
		p->data = i;
		r->next = p;
		r = p;
	}
	r->next = L;                                               //ѭ������ı�־
}

void DispLink(LinkNode* L)                                   //��������
{
	LinkNode* p;
	p = L->next;
	cout << L->data << " ";
	while (p != L)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

void YSF(LinkNode* L,ElemType M,ElemType K)
{
	LinkNode* p, * r,* j;
	p = L; r = L; 
	for (int i = 1; i < M; i++)
	{
		p = p->next;
	} 
	j = p;                                                             //j �Ǻ� p �ҹ��ģ������ж�j �� p�ǲ�����һ��
	if (K != 1)                                                        //���ǵ��������ֲ�Ϊ1�����
	{
		while (p->next != j)                                           //���j p ����һ��˵�������������ݽڵ���������������
		{
			int i = 1;
			while (i != K - 1)                                        //�ҵ�Ҫ �� ���Ǹ�λ�õ�ǰһλ
			{
				i++;
				p = p->next;          
			}
			r = p; cout << r->next->data << " ";                     //�ȱ��Ҫ�����Ǹ�λ�ã��Ȱ�Ҫ����λ�õ��������
			r->next = p->next->next; p = r->next; j = p;             //Ȼ��ɾ�����������Ǹ��ڵ�
		}
		cout << p->data;
	}
	else                                                            //�����ǵ���������Ϊ 1 �����
	{
		while (p->next != j)
		{
			cout << p->data << " ";
			p = p->next;
		}
		cout << p->data;
	}
}

void main()                                                                            
{
	LinkNode* L1; InitLink(L1);
	ElemType N; cout << "��������������"; cin >> N;
	CreateLink(L1, N);
	DispLink(L1);

	ElemType M, K;
	cout << "�����뿪ʼ������λ�ã�"; cin >> M;
	cout << "�������������֣�"; cin >> K;
	cout << "����˳��Ϊ��"; YSF(L1, M, K);
	cout << endl;
}