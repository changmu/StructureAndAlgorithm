////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-12-14 20:22:48
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4135
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1092KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>

typedef __int64 LL;

int p[12], k, T, que[10000];

void getp(LL n) {
    k = 0;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            p[k++] = i;
            while (n % i == 0) n /= i;
        }
    }
    if (n > 1) p[k++] = n;
}

LL nop(LL m) {
    LL sum = 0;
    int back = 0, i, j, t;
    que[back++] = -1;
    for (i = 0; i < k; ++i) {
        t = back;
        for (j = 0; j < t; ++j) {
            que[back] = p[i] * que[j] * -1;
            sum += m / que[back++];
        }
    }
    return sum;
}

int main() {
    // freopen("stdin.txt", "r", stdin);
    LL u, v, n;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; ++cas) {
        printf("Case #%d: ", cas);
        scanf("%I64d%I64d%I64d", &u, &v, &n);
        getp(n);
        printf("%I64d\n", v - nop(v) - u + 1 + nop(u - 1));
    }
    return 0;
}