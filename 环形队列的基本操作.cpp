#include<iostream>
using namespace std;

#define Max 4                           //宏定义Max
typedef char ElemType;
typedef struct                          //队列的定义
{
	ElemType data[Max];
	int front, rear;
}SqQueue;

void InitSq(SqQueue*& S)                      //初始化队列
{
	S = new SqQueue;
	S->front = S->rear = 0;
}

bool SqEmpty(SqQueue* S)                         //判断队列是否为空
{
	return(S->front == S->rear);
}

void Put(SqQueue*& S, ElemType e)                    //进队操作
{
	if ((S->rear + 1) % Max == S->front)
		cout << "进队失败" << endl;
	else
	{
		S->rear = (S->rear + 1) % Max;               //尾指针的指向
		S->data[S->rear] = e;
	}
}

void Out(SqQueue*& S, ElemType &e)             //出队操作
{
	if (S->front == S->rear)
		cout << "队列为空";
	else
	{
		S->front = (S->front + 1) % Max;           //头指针的指向
		e = S->data[S->front];
	}
}

void Delete(SqQueue*& S)                            //销毁队列
{
	delete(S);
}

int main()
{
	SqQueue* q; InitSq(q);
	if (SqEmpty(q))
		cout << "队列为空" << endl;
	else
		cout << "队列不为空" << endl;
	ElemType e;
	cout << "依次进队元素为：";
	for (int i = 1; i <= 3; i++)                       //循环输入
	{
		cin >> e;
		Put(q, e);
	}
	Out(q, e);
	cout << "出队元素为：" << e << endl;
	cout << "依次进队元素为：";
	for (int i = 1; i <= 3; i++)
	{
		cin >> e;
		Put(q, e);
	}
	cout << "出队序列为：";
	while (!SqEmpty(q))                          //循环输出
	{
		Out(q, e);
		cout << e;
	}
	Delete(q);
}