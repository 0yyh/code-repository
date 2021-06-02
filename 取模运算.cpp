#include<stdio.h>
int main()
{
  int hh,mm,ss;
  scanf("%d:%d:%d",&hh,&mm,&ss);
  int n;
  scanf("%d",&n);
  ss=ss+n;
  mm+=(ss - ss%60)>0,ss=ss%60;
  hh+=(mm - mm%60)>0,mm=mm%60;
  hh=hh%24;
  printf("%02d:%02d:%02d",hh,mm,ss);
  return 0;
}
