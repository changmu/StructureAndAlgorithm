////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-07-20 14:14:06
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4508
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:596KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>

int dp[100002], w[102], v[102];

int main()
{
    int n, i, j, totalWeight;
    while(scanf("%d", &n) == 1){
        for(i = 1; i <= n; ++i)
            scanf("%d%d", &v[i], &w[i]);            
        scanf("%d", &totalWeight);
        memset(dp, 0, sizeof(dp));
        for(i = 1; i <= n; ++i){
            for(j = w[i]; j <= totalWeight; ++j){
                if(dp[j] < dp[j - w[i]] + v[i])
                    dp[j] = dp[j - w[i]] + v[i];
            }
        }
        printf("%d\n", dp[totalWeight]);
    }
    return 0;
}