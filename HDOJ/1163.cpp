////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-27 23:03:25
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1163
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int main()
{
    int n, i, ans;
    while(scanf("%d", &n), n){
        ans = 1;
        for(i = 1; i <= n; ++i)
            ans = n * ans % 9;
        if(!ans) ans = 9;
        printf("%d\n", ans);
    }
    return 0;
}