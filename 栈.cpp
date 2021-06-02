#include<iostream>                                   
using namespace std;

#define Max 40                                                    //宏定义Max
typedef char ElemType;
typedef struct                                                    //栈的结构
{
	ElemType data[Max];
	int top;
}SqStack;

void InitSqlist(SqStack *&s)                                   //栈的初始化
{
	s=new SqStack;                                            //开辟空间
	s->top=-1;                                                //top指针指向底端
}

bool StackEmpty(SqStack *s)                                    //判断栈是否为空
{
	return(s->top == -1);
}

void Push(SqStack *&s,ElemType e[])                           //入栈操作
{
	if(s->top==Max-1)                                           //考虑栈的存储空间
		cout<<"入栈失败";
	for(int i=0;i<5;i++)
	{
		s->top++;
		s->data[s->top] = e[i];                               //数组元素输入
	}
}

void Pop(SqStack *&s)                                   //出栈操作
{
	ElemType e;
	if(s->top==-1)
		cout<<"出栈失败";                               
	for(int i=s->top;i>-1;i--)                             //用while也行
	{
		e=s->data[s->top];
		s->top--;	
		cout<<e<<" ";
	}
	cout<<endl;
}

void DestroyStack(SqStack *&s)                            //栈的销毁
{
	delete (s);
}

void ConStack(int a, int b)                               //进制的转换
{
	SqStack* s;
	InitSqlist(s);                                       //初始化栈
	int k;
	if (a == 0)
		cout << "0" << endl;
	else
	{
		while (a)
		{
			k = a % b;                                         //余数
			if (k >= 0 && k <= 9)
			{
				s->top++;
				s->data[s->top] = k + '0';                   //转换成字符的形式入栈（oj上有类似的处理方式）
			}
			else
			{
				s->top++;
				s->data[s->top] = k - 10 + 'A';
			}
			a = a / b;                                        //商
		}
	}
	while (s->top != -1)                                      //栈的输出
	{
		cout << s->data[s->top];
		s->top--;
	}
	DestroyStack(s);                                         //销毁
}

void main()
{
	SqStack *S;
	InitSqlist(S);
	if (StackEmpty(S))                                                         
		cout << "最开始的栈为空栈" << endl;
	else
		cout << "最开始的栈为实栈" << endl;

	ElemType e[5]={'A','B','C','D','E'};                               //当作数组进行入栈
	Push(S,e);
	if (StackEmpty(S))                     
		cout << "入栈后的栈为空栈" << endl;
	else
		cout << "入栈后的栈为实栈" << endl;
	Pop(S);
	if (StackEmpty(S))
		cout << "出栈后的栈为空栈" << endl;
	else
		cout << "出栈后的栈为实栈" << endl;
	DestroyStack(S);

	int a, b;
	for (int i = 1; i <= 2; i++)
	{
		cout << "输入要转化的十进制数:"; cin >> a;
		cout << "输入要转换成的进制:"; cin >> b;
		ConStack(a, b);
		cout << endl;
	}
}
