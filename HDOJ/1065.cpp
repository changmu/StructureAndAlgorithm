////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-07-23 10:38:08
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1065
////Problem Title: 
////Run result: Accept
////Run time:93MS
////Run memory:248KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int main()
{
    int t;
    double x, y;
    scanf("%d", &t);
    for(int i = 1; i <= t; ++i){
        scanf("%lf%lf", &x, &y);
        printf("Property %d: This property will begin eroding in year %d.\n",
            i, int((x*x + y*y) * 3.1415926 / 100 + 1));
    }
    printf("END OF OUTPUT.\n");
    return 0;
}