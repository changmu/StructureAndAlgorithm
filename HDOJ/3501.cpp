////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: 长木
////Run ID: 
////Submit time: 2014-11-08 14:25:29
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3501
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:244KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <math.h>

#define mod 1000000007
typedef __int64 LL;

int Euler(int x) {
    int i, res = x;
    for(i = 2; i <= (int)sqrt((double)x); ++i) {
        if(x % i == 0) {
            res = res / i * (i - 1);
            while(x % i == 0) x /= i; // 保证i一定是素数
        }
    }
    if(x > 1) res = res / x * (x - 1);
    return res;
}

int main() {
    int n, i;
    LL ans;
    while(scanf("%d", &n), n) {
        ans = (LL)n * (n - 1) / 2 - (LL)Euler(n) * n / 2;
        printf("%d\n", ans % mod);
    }
    return 0;
}
