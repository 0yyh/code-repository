#include<iostream>                                   
using namespace std;

#define Max 40                                                    //�궨��Max
typedef char ElemType;
typedef struct                                                    //ջ�Ľṹ
{
	ElemType data[Max];
	int top;
}SqStack;

void InitSqlist(SqStack *&s)                                   //ջ�ĳ�ʼ��
{
	s=new SqStack;                                            //���ٿռ�
	s->top=-1;                                                //topָ��ָ��׶�
}

bool StackEmpty(SqStack *s)                                    //�ж�ջ�Ƿ�Ϊ��
{
	return(s->top == -1);
}

void Push(SqStack *&s,ElemType e[])                           //��ջ����
{
	if(s->top==Max-1)                                           //����ջ�Ĵ洢�ռ�
		cout<<"��ջʧ��";
	for(int i=0;i<5;i++)
	{
		s->top++;
		s->data[s->top] = e[i];                               //����Ԫ������
	}
}

void Pop(SqStack *&s)                                   //��ջ����
{
	ElemType e;
	if(s->top==-1)
		cout<<"��ջʧ��";                               
	for(int i=s->top;i>-1;i--)                             //��whileҲ��
	{
		e=s->data[s->top];
		s->top--;	
		cout<<e<<" ";
	}
	cout<<endl;
}

void DestroyStack(SqStack *&s)                            //ջ������
{
	delete (s);
}

void ConStack(int a, int b)                               //���Ƶ�ת��
{
	SqStack* s;
	InitSqlist(s);                                       //��ʼ��ջ
	int k;
	if (a == 0)
		cout << "0" << endl;
	else
	{
		while (a)
		{
			k = a % b;                                         //����
			if (k >= 0 && k <= 9)
			{
				s->top++;
				s->data[s->top] = k + '0';                   //ת�����ַ�����ʽ��ջ��oj�������ƵĴ���ʽ��
			}
			else
			{
				s->top++;
				s->data[s->top] = k - 10 + 'A';
			}
			a = a / b;                                        //��
		}
	}
	while (s->top != -1)                                      //ջ�����
	{
		cout << s->data[s->top];
		s->top--;
	}
	DestroyStack(s);                                         //����
}

void main()
{
	SqStack *S;
	InitSqlist(S);
	if (StackEmpty(S))                                                         
		cout << "�ʼ��ջΪ��ջ" << endl;
	else
		cout << "�ʼ��ջΪʵջ" << endl;

	ElemType e[5]={'A','B','C','D','E'};                               //�������������ջ
	Push(S,e);
	if (StackEmpty(S))                     
		cout << "��ջ���ջΪ��ջ" << endl;
	else
		cout << "��ջ���ջΪʵջ" << endl;
	Pop(S);
	if (StackEmpty(S))
		cout << "��ջ���ջΪ��ջ" << endl;
	else
		cout << "��ջ���ջΪʵջ" << endl;
	DestroyStack(S);

	int a, b;
	for (int i = 1; i <= 2; i++)
	{
		cout << "����Ҫת����ʮ������:"; cin >> a;
		cout << "����Ҫת���ɵĽ���:"; cin >> b;
		ConStack(a, b);
		cout << endl;
	}
}
