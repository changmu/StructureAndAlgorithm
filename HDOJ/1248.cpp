////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-07-22 23:00:53
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1248
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:308KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#define maxn 10002

int dp[maxn];
const int sample[] = {150, 200, 350};

int main()
{
    int t, n, i, j;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        memset(dp, 0, sizeof(dp));
        for(i = 0; i < 3; ++i){
            for(j = sample[i]; j <= n; ++j)
                if(dp[j] < dp[j - sample[i]] + sample[i])
                    dp[j] = dp[j - sample[i]] + sample[i];
        }
        printf("%d\n", n - dp[n]);
    }
    return 0;
}