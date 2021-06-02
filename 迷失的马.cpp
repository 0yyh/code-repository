#include<iostream>
using namespace std;

#define Max 100                                    //ȫ�ֶ������
#define N 6
#define M 36

typedef struct
{
	int i;
	int j;
	int di;
}Box;

typedef struct
{
	Box data[Max];
	int top;
}StType;                                               //ջ�Ķ���

void InitSt(StType*& s)                                  //ջ�ĳ�ʼ��
{
	s = new StType;
	s->top = -1;
}

void Push(StType*& s, Box e)                           //��ջ����
{
	s->top++;
	s->data[s->top].i = e.i;
	s->data[s->top].j = e.j;
	s->data[s->top].di = e.di;
}

bool StEmpty(StType* s)                                 //�ж�ջ�Ƿ�Ϊ��
{
	return(s->top == -1);
}
 
void GetSt(StType* s, Box &e)                            //ȡջԪ��
{
	e.i = s->data[s->top].i;
	e.j = s->data[s->top].j;
	e.di = s->data[s->top].di;
}

bool Pop(StType*& s, Box e)                               //��ջ����
{
	if (s->top < -1)
		return false;
	else
	{
		e = s->data[s->top];
		s->top--;
	}
	return true;
}

void Path(int xi, int yi)                             //��·��
{
	int b[N][N], count = 1;                         //����������̣�count��������λ��
	Box e;
	for (int i = 0; i < N; i++)
		for (int k = 0; k < N; k++)
			b[i][k] = 0;                               //���̵ĳ�ʼ��
	b[xi][yi] = count;                                //��������ֱ�Ӽ���
	int i, j, di;                                   //i�Ǻ����꣬jΪ�����꣬diΪ��λ
	int i1, j1;                                    //��һ����ĺ�������
	int n = 0, flag = 0;                          //n�ǽⷨ��flagΪ��־
	StType* s; InitSt(s);                               //����ջ
	e.i = xi; e.j = yi; e.di = -1;
	Push(s, e);                                         //�������Ԫ�ؽ�ջ
	bool find;
	while (!StEmpty(s))                                     //ջ��Ϊ��ʱ����
	{
		GetSt(s, e);                                         //ȡջ��Ԫ��
		i = e.i; j = e.j; di = e.di;
		if (count == M)                                             //�����������̵����λʱ����
		{
			if (pow((i - xi), 2) + pow((j - yi), 2) == 5)              //��ΪҪʹ�����һ�������ص�һ������ô���һ����λ�þ��ǹ̶����Һ�����λ�þ���̶�
			{
				n++;                                                  //����һ���ж����ֽⷨ
				if (flag == 0)                                       //flag�����þ���ֻ���һ�����̽��
				{
					for (int i = 0; i < N; i++)                       //������̵��߷�����
					{
						for (int k = 0; k < N; k++)
							cout << b[i][k] << "\t";
						cout << endl;
					}
					flag = 1;
				}
			}
		}
		find = false;
		while (di < 7 && !find)                                                 
		{
			di++;
			switch (di)                                                       //һ��λ�õ�8���߷�
			{
			case 0:i1 = i - 2; j1 = j + 1; break;
			case 1:i1 = i - 1; j1 = j + 2; break;
			case 2:i1 = i + 1; j1 = j + 2; break;
			case 3:i1 = i + 2; j1 = j + 1; break;
			case 4:i1 = i + 2; j1 = j - 1; break;
			case 5:i1 = i + 1; j1 = j - 2; break;
			case 6:i1 = i - 1; j1 = j - 2; break;
			case 7:i1 = i - 2; j1 = j - 1; break;
			}
			if (i1 >= 0 && i1 < N && j1 >= 0 && j1 < N && b[i1][j1] == 0)             //�ж���һ��λ���Ƿ���Ϲ���
			{
				find = true;
			}
		}
		if (find)                                       //�����Ϲ������һ��Ԫ�ؽ�ջ
		{
			count++;
			b[i1][j1] = count;
			s->data[s->top].di = di;
			e.i = i1; e.j = j1; e.di = -1;
			Push(s, e);
		}
		else                                         //����һ��Ԫ�ز����Ϲ�����ջ�����Ǹ�λ����Ϊ0
		{
			Pop(s, e);
			b[e.i][e.j] = 0;
			count--;
		}
	}
	cout << "\n" << "һ����" << n << "��·��";
}

int main()                                                            //��ջ�Ľ̫ⷨ��ʱ�ˣ�����ֻ��ʾ6*6�������߷�����Ϊ8*8�����Լ�Ҳû���������̫��ʱ�ˣ�
{
	int x, y;
	cout << "X:"; cin >> x; cout << endl;
	cout << "Y:"; cin >> y; cout << endl;
	Path(x-1, y-1);
}