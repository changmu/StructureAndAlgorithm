////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-12-09 10:01:10
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1425
////Problem Title: 
////Run result: Accept
////Run time:358MS
////Run memory:5004KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long LL;

#define maxn 1000002
#define delta 500000

int hash[maxn], N, M, v;

int main() {
    // freopen("stdin.txt", "r", stdin);
    while(scanf("%d%d", &N, &M) == 2) {
        memset(hash, 0, sizeof(hash));
        while(N--) {
            scanf("%d", &v);
            ++hash[v+delta];
        }
        N = maxn - 2;
        while(!hash[N]) --N;
        printf("%d", N - delta);
        --hash[N]; -- M;
        for( ; N >= 0 && M; --N) {
            while(hash[N] && M) {
                printf(" %d", N - delta);
                --hash[N];
                --M;
            }
        }
        printf("\n");
    }
    return 0;
}