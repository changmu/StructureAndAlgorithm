////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: 长木
////Run ID: 
////Submit time: 2014-07-20 10:29:57
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1114
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:244KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>

int dp[10002];

int main()
{
    int totalWeight, weight, val, n, t, i, j;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &weight, &totalWeight);
        totalWeight -= weight;
        scanf("%d", &n);
        memset(dp + 1, -1, sizeof(int) * 10001); 
        //注意不能用memset(dp + 1, -1, sizeof(dp + 1));
        for(i = 1; i <= n; ++i){
            scanf("%d%d", &val, &weight);
            for(j = weight; j <= totalWeight; ++j){
                if(dp[j - weight] != -1){
                    if(dp[j] == -1 || dp[j] > dp[j - weight] + val)
                        dp[j] = dp[j - weight] + val;
                }
            }
        }
        if(dp[totalWeight] == -1) printf("This is impossible.\n");
        else printf("The minimum amount of money in the piggy-bank is %d.\n", dp[totalWeight]);
    }
    return 0;
}
