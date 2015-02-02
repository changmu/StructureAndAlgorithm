////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-11-17 22:51:39
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1201
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
//wangerning's code
#include<stdio.h>
#include<stdlib.h>
int rn(int year)
{
    if((year%4==0&&year%100!=0)||(year%400==0))return 1;
    else return 0;
}
int main()
{
    int n,i,a,year,month,day,days,s;
    scanf("%d",&n);
    while(n--)
    {
        a=0;
        scanf("%d-%d-%d",&year,&month,&day);
        s=year+18;
        if((month==2&&day==29)&&!rn(s))printf("%d\n",-1);
        else
        {
            for(i=year+1;i<s;i++)
            {
                if(rn(i))a++;
            }
            days=17*365+a;
            if((month>2&&rn(s))||(month<=2&&rn(year)))days=days+366;
            else days=days+365; 
            printf("%d\n",days);
        }
    }
    //system("pause");
    return 0;
}
