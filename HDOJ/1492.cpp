////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-12-03 23:13:51
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1492
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:252KB
//////////////////System Comment End//////////////////
#include <stdio.h>
typedef __int64 LL;

const int div[] = {2, 3, 5, 7};

int main() {
    LL n;
    while(scanf("%I64d", &n), n) {
        int ans[] = {1, 1, 1, 1};
        for(int i = 0; i < 4; ++i)
            while(n % div[i] == 0) {
                ++ans[i]; n /= div[i];
            }
        printf("%d\n", ans[0] * ans[1] * ans[2] * ans[3]);
    }
    return 0;
}