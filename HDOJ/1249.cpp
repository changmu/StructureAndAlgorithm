////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-28 11:36:44
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1249
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:268KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int dp[10002] = {1, 2, 8, 20};

int main()
{
    int i, n;
    for(i = 4; i < 10001; ++i)
        dp[i] = dp[i-1] + 6 * (i - 1);
    scanf("%d", &n);
    while(n--){
        scanf("%d", &i);
        printf("%d\n", dp[i]);
    }
    return 0;
}