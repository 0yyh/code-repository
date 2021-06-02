#include<iostream>
using namespace std;

#define Max 4                           //�궨��Max
typedef char ElemType;
typedef struct                          //���еĶ���
{
	ElemType data[Max];
	int front, rear;
}SqQueue;

void InitSq(SqQueue*& S)                      //��ʼ������
{
	S = new SqQueue;
	S->front = S->rear = 0;
}

bool SqEmpty(SqQueue* S)                         //�ж϶����Ƿ�Ϊ��
{
	return(S->front == S->rear);
}

void Put(SqQueue*& S, ElemType e)                    //���Ӳ���
{
	if ((S->rear + 1) % Max == S->front)
		cout << "����ʧ��" << endl;
	else
	{
		S->rear = (S->rear + 1) % Max;               //βָ���ָ��
		S->data[S->rear] = e;
	}
}

void Out(SqQueue*& S, ElemType &e)             //���Ӳ���
{
	if (S->front == S->rear)
		cout << "����Ϊ��";
	else
	{
		S->front = (S->front + 1) % Max;           //ͷָ���ָ��
		e = S->data[S->front];
	}
}

void Delete(SqQueue*& S)                            //���ٶ���
{
	delete(S);
}

int main()
{
	SqQueue* q; InitSq(q);
	if (SqEmpty(q))
		cout << "����Ϊ��" << endl;
	else
		cout << "���в�Ϊ��" << endl;
	ElemType e;
	cout << "���ν���Ԫ��Ϊ��";
	for (int i = 1; i <= 3; i++)                       //ѭ������
	{
		cin >> e;
		Put(q, e);
	}
	Out(q, e);
	cout << "����Ԫ��Ϊ��" << e << endl;
	cout << "���ν���Ԫ��Ϊ��";
	for (int i = 1; i <= 3; i++)
	{
		cin >> e;
		Put(q, e);
	}
	cout << "��������Ϊ��";
	while (!SqEmpty(q))                          //ѭ�����
	{
		Out(q, e);
		cout << e;
	}
	Delete(q);
}