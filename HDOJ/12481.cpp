////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-07-22 23:20:40
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1248
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:268KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int main()
{
    int t, n, ans, m;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        ans = n % 150;
        m = n / 150;
        while(ans >= 50 && m--)
            ans -= 50;
        printf("%d\n", ans);
    }
    return 0;
}