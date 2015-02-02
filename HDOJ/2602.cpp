////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-07-19 23:45:39
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2602
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#define maxn 1002

int dp[maxn], w[maxn], v[maxn];

int main()
{
    int t, n, val, i, j;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &val);
        for(i = 1; i <= n; ++i) scanf("%d", v + i);
        for(i = 1; i <= n; ++i) scanf("%d", w + i);
        memset(dp, 0, sizeof(dp));
        for(i = 1; i <= n; ++i){
            for(j = val; j >= w[i]; --j){
                if(dp[j] < dp[j-w[i]] + v[i]) 
                    dp[j] = dp[j-w[i]] + v[i];
            }
        }
        printf("%d\n", dp[val]);
    }
    return 0;
}
