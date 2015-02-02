////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-26 11:37:54
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1056
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:272KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#define maxn 300

double len[maxn];

int bSearch(double a)
{
    int l = 1, r = maxn - 1, mid;
    while(l <= r){
        mid = (l + r) >> 1;
        if(len[mid] < a) l = mid + 1;
        else if(len[mid] > a) r = mid - 1;
        else return mid;
    }
    return l;
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