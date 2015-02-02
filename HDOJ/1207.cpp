////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-07-27 09:33:22
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1207
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <math.h>

__int64 dp[66] = {0, 1, 3, 5}, pow2[66] = {1, 2, 4, 8, 16};

int main()
{
    int n, r, i;
    for(i = 5; i < 65; ++i)
        pow2[i] = pow2[i-1] << 1;
    for(n = 4; n < 65; ++n){
        r = (int)((sqrt(8 * n + 1) - 1) / 2);
        dp[n] = 2 * dp[n-r] + pow2[r] - 1;
    }
    while(scanf("%d", &n) != EOF){
        printf("%I64d\n", dp[n]);
    }
    return 0;
}