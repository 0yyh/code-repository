#include<stdio.h>
#include<string.h>                       /*�ַ��ͺ�������*/ 
int main()
{
	char a[80],t;
	gets(a);
	printf("����ǰ˳��");
	puts(a);
	int n=strlen(a);
	for(int i=0;i<=n-1;i++)
	{
		for(int j=0;j<=n-2-i;j++)
		if(a[j]>a[j+1])
		{
			t=a[j],a[j]=a[j+1],a[j+1]=t;
		}                                     /*ð���Ǵ��ݣ��Ѵ�ķ��ں���*/ 
	}
	puts(a);
}
