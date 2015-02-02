////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-27 23:21:50
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1164
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:304KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <math.h>
#define maxn 70000

bool dp[maxn] = {1, 1};

int main()
{
    int n, i, j;
    n = sqrt((double)maxn);
    for(i = 2; i <= n; ++i){
        if(dp[i]) continue;
        for(j = i * i; j < maxn; j += i)
            dp[j] = 1;
    }
    while(scanf("%d", &n) == 1){
        for(i = 2; i <= n;){
            if(!dp[i] && n % i == 0){
                n /= i;
                printf("%d", i);
                if(n != 1) printf("*");
                else{
                    printf("\n"); break;
                }
            }else ++i;
        }
    }
    return 0;
}