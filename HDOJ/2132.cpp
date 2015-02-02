////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-11-06 20:39:07
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2132
////Problem Title: 
////Run result: Accept
////Run time:93MS
////Run memory:1008KB
//////////////////System Comment End//////////////////
#include <stdio.h>

#define maxn 100005
typedef __int64 LL;

LL arr[maxn];

int main() {
    int n, i;
    for(i = 1; i <= 100000; ++i)
        if(i % 3) arr[i] = arr[i-1] + i;
        else arr[i] = arr[i-1] + (LL)i * i * i;
    while(scanf("%d", &n), n >= 0)
        printf("%I64d\n", arr[n]);
}