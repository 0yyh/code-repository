#include<stdio.h>
int main()
{
	int a,b,m,n,t;
	scanf("%d %d",&a,&b);
	m=a;
	n=b;
	while(n!=0)
	{
		t=m%n;
		m=n;
		n=t;
	}
	printf("%d %d\n",m,a*b/m);
}
