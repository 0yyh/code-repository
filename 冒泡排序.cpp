#include<stdio.h>
#include<string.h>                       /*字符型函数调用*/ 
int main()
{
	char a[80],t;
	gets(a);
	printf("排序前顺序；");
	puts(a);
	int n=strlen(a);
	for(int i=0;i<=n-1;i++)
	{
		for(int j=0;j<=n-2-i;j++)
		if(a[j]>a[j+1])
		{
			t=a[j],a[j]=a[j+1],a[j+1]=t;
		}                                     /*冒的是大泡，把大的放在后面*/ 
	}
	puts(a);
}
