////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-26 11:31:28
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1056
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:272KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#define maxn 300

double len[maxn];

int bSearch(double a)
{
    for(int i = 1; i < maxn; ++i)
        if(len[i] >= a) return i;
}

int main()
{
    double a = 0.0;
    int i;
    for(i = 1; i < maxn; ++i){
        a += 1.0 / (i + 1.0);
        len[i] = a;
    }
    while(scanf("%lf", &a), a != 0.00){
        printf("%d card(s)\n", bSearch(a));
    }
    return 0;
}