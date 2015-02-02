#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long LL;

#define maxn 4010
#define maxm 1000010

int pre[maxn];

int ufind(int k) {
    int a = k, b;
    while(pre[k] != -1) k = pre[k];
    while(a != k) {
        b = pre[a];
        pre[a] = k;
        a = b;
    }
    return k;
}

bool same(int a, int b) {
    return ufind(a) == ufind(b);
}

void unite(int a, int b) {
    a = ufind(a);
    b = ufind(b);
    if(a != b) pre[a] = b;
}

int main() {
    // freopen("stdin.txt", "r", stdin);
    int T, cas, i, j, N, M, a, b, ok;
    scanf("%d", &T);
    for(cas = 1; cas <= T; ++cas) {
        printf("Scenario #%d:\n", cas);
        scanf("%d%d", &N, &M);
        memset(pre, -1, sizeof(int) * (2 * N + 1));
        ok = 0;
        while(M--) {
            scanf("%d%d", &a, &b);
            if(ok) continue;
            if(same(a, b))
                ok = 1;
            else {
                unite(a, b + N);
                unite(a + N, b);
            }
        }
        printf(ok ? "Suspicious bugs found!" : "No suspicious bugs found!");
        printf("\n\n");
    }
    return 0;
}
