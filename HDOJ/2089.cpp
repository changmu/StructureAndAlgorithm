////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-18 11:36:58
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2089
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:4168KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#define maxn 1000002

int dp[maxn];

int main()
{
    int i, a, b;
    for(i = 1; i < maxn; ++i){
        a = i; dp[i] = dp[i-1];
        while(a){
            if(a % 10 == 4 || a % 100 == 62) break;
            a /= 10;
        }
        if(!a) ++dp[i];
    }
    while(scanf("%d%d", &a, &b), a || b)
        printf("%d\n", dp[b] - dp[a-1]);    
    return 0;
}