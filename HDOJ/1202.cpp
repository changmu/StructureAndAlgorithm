////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-07-31 22:14:24
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1202
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:216KB
//////////////////System Comment End//////////////////
#include <stdio.h>

double f(double p)
{
    if(p >= 90) return 4;
    if(p >= 80) return 3;
    if(p >= 70) return 2;
    if(p >= 60) return 1;
    return 0;
}

int main()
{
    int n;
    double s, p, sums, sump;
    while(scanf("%d", &n) != EOF){
        sums = sump = 0;
        while(n--){
            scanf("%lf%lf", &s, &p);
            if(p < 0) continue;
            sums += s; sump += f(p) * s;
        }
        if(sump <= 0) printf("-1\n");
        else printf("%.2lf\n", sump / sums);
    }
    return 0;
}