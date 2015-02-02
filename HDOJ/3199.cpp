////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-26 22:01:45
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3199
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:336KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#define maxn 10000

__int64 dp[maxn] = {1, 1};
__int64 a0, b0, c0, a, b, c;

__int64 min(__int64 u, __int64 v, __int64 x)
{
    __int64 tmp = u;
    if(tmp > v) tmp = v;
    if(tmp > x) tmp = x;

    if(tmp == u) ++a;
    if(tmp == v) ++b;
    if(tmp == x) ++c;
    
    return tmp;
}

int main()
{
    __int64 i, n;
    while(scanf("%I64d%I64d%I64d%I64d", &a0, &b0, &c0, &n) != EOF){
        a = b = c = 0; dp[0] = 1;
        for(i = 1; i <= n; ++i)
            dp[i] = min(dp[a]*a0, dp[b]*b0, dp[c]*c0);
        printf("%I64d\n", dp[n]);
    }
    return 0;
}
