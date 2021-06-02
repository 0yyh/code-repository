#include<iostream>
using namespace std;

#define Max 100                                    //全局定义变量
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
}StType;                                               //栈的定义

void InitSt(StType*& s)                                  //栈的初始化
{
	s = new StType;
	s->top = -1;
}

void Push(StType*& s, Box e)                           //进栈操作
{
	s->top++;
	s->data[s->top].i = e.i;
	s->data[s->top].j = e.j;
	s->data[s->top].di = e.di;
}

bool StEmpty(StType* s)                                 //判断栈是否为空
{
	return(s->top == -1);
}
 
void GetSt(StType* s, Box &e)                            //取栈元素
{
	e.i = s->data[s->top].i;
	e.j = s->data[s->top].j;
	e.di = s->data[s->top].di;
}

bool Pop(StType*& s, Box e)                               //出栈操作
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

void Path(int xi, int yi)                             //找路径
{
	int b[N][N], count = 1;                         //数组就是棋盘，count用来计算位数
	Box e;
	for (int i = 0; i < N; i++)
		for (int k = 0; k < N; k++)
			b[i][k] = 0;                               //棋盘的初始化
	b[xi][yi] = count;                                //在棋盘上直接计数
	int i, j, di;                                   //i是横坐标，j为纵坐标，di为方位
	int i1, j1;                                    //下一个点的横纵坐标
	int n = 0, flag = 0;                          //n是解法，flag为标志
	StType* s; InitSt(s);                               //定义栈
	e.i = xi; e.j = yi; e.di = -1;
	Push(s, e);                                         //将输入的元素进栈
	bool find;
	while (!StEmpty(s))                                     //栈不为空时继续
	{
		GetSt(s, e);                                         //取栈顶元素
		i = e.i; j = e.j; di = e.di;
		if (count == M)                                             //当计数到棋盘的最大位时继续
		{
			if (pow((i - xi), 2) + pow((j - yi), 2) == 5)              //因为要使得最后一步能跳回第一步，那么最后一步的位置就是固定的且和起点的位置距离固定
			{
				n++;                                                  //计算一共有多少种解法
				if (flag == 0)                                       //flag的作用就是只输出一次棋盘结果
				{
					for (int i = 0; i < N; i++)                       //输出棋盘的走法步骤
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
			switch (di)                                                       //一个位置的8种走法
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
			if (i1 >= 0 && i1 < N && j1 >= 0 && j1 < N && b[i1][j1] == 0)             //判断下一个位置是否符合规则
			{
				find = true;
			}
		}
		if (find)                                       //将符合规则的下一个元素进栈
		{
			count++;
			b[i1][j1] = count;
			s->data[s->top].di = di;
			e.i = i1; e.j = j1; e.di = -1;
			Push(s, e);
		}
		else                                         //若下一个元素不符合规则，退栈并将那个位置置为0
		{
			Pop(s, e);
			b[e.i][e.j] = 0;
			count--;
		}
	}
	cout << "\n" << "一共有" << n << "种路径";
}

int main()                                                            //用栈的解法太耗时了，这里只演示6*6的棋盘走法（因为8*8的我自己也没运算出来，太耗时了）
{
	int x, y;
	cout << "X:"; cin >> x; cout << endl;
	cout << "Y:"; cin >> y; cout << endl;
	Path(x-1, y-1);
}