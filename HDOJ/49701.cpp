////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-12-07 22:02:48
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4970
////Problem Title: 
////Run result: Accept
////Run time:546MS
////Run memory:1880KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef __int64 LL;

#define maxn 100005

LL D[maxn];
LL N, M, K, ans;

int main() {
    // freopen("stdin.txt", "r", stdin);
    LL u, v, w, i, hp, pos;
    while(scanf("%I64d", &N), N) {
        memset(D, 0, sizeof(LL) * (N + 2));
        scanf("%I64d", &M);
        while(M--) {
            scanf("%I64d%I64d%I64d", &u, &v, &w);
            D[v] += w; D[u-1] -= w;
        }
        LL tmp = D[N];
        for(i = N - 1; i; --i) {
            tmp += D[i];
            D[i] = tmp + D[i+1];
        }
        scanf("%I64d", &K);
        ans = 0;
        while(K--) {
            scanf("%I64d%I64d", &hp, &pos);
            if(D[pos] < hp) ++ans;
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
