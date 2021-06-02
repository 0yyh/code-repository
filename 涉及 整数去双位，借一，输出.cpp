#include<stdio.h>
main()
{
    int h,m,depart,arrive;
    scanf("%d%d",&depart,&arrive);
    h=arrive/100-depart/100;            //4位整型取前2位(小时)
    m=arrive%100-depart%100;            //4位整型取余后2位(分钟)
    if(m<0)                  //depart，arrive都是在同一天,h一定大于0
    {
        m=60+m;                 //当m小于0，从h借来一小时，填补m的值
        h=h-1;
    }
    printf("%02d:%02d\n",h,m);
}
