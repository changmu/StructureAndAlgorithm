////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-12-14 22:05:53
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2841
////Problem Title: 
////Run result: Accept
////Run time:187MS
////Run memory:1096KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>

#define maxn 100002
typedef __int64 LL;

int p[20], k, id, que[maxn];

void getp(int n) {
    int i, j, t; k = 0;
    for (i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            p[k++] = i;
            while (n % i == 0) 
                n /= i;
        }
    }
    if (n > 1) p[k++] = n;
    id = 0;
    que[id++] = -1;
    for (i = 0; i < k; ++i) {
        t = id;
        for (j = 0; j < t; ++j)
            que[id++] = p[i] * que[j] * -1;
    }
}

LL nop(int n) {
    LL sum = 0;
    for (int i = 1; i < id; ++i)
        sum += n / que[i];
    return sum;
}

int main() {
    // freopen("stdin.txt", "r", stdin);
    int T, N, M, i;
    LL sum;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &N, &M);
        sum = N;
        for (i = 2; i <= M; ++i) {
            getp(i);
            sum += N - nop(N);
        }
        printf("%I64d\n", sum);
    }
    return 0;
}