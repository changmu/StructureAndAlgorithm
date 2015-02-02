////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-07-26 23:31:48
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1060
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:208KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <math.h>

int main()
{
    int t, n;
    double ans;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        ans = n * log10(n);
        ans -= (__int64)ans;
        ans = pow(10, ans);
        printf("%d\n", (int)ans);
    }
    return 0;
}