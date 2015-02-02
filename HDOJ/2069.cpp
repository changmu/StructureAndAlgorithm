////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-19 19:26:39
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2069
////Problem Title: 
////Run result: Accept
////Run time:703MS
////Run memory:256KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int main()
{
    int n, a, b, c, d, e, ans;
    while(scanf("%d", &n) == 1){
        ans = 0;
        for(a = 0; a <= n/50; ++a)
            for(b = 0; b <= n/25; ++b)
                for(c = 0; c <= n/10; ++c)
                    for(d = 0; d <= n/5; ++d)
                        for(e = 0; e <= n; ++e)
                            if(a*50 + b*25 + c*10 + d*5 + e == n && 
                                a+b+c+d+e <= 100) ++ans;
        printf("%d\n", ans);
    }
    return 0;
}