#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long LL;

#define maxn 100005

int pre[maxn << 1];

int ufind(int k) {
    if (!pre[k]) return k;
    return pre[k] = ufind(pre[k]);
}

bool same(int a, int b) {
    return ufind(a) == ufind(b);
}

bool unite(int a, int b) {
    a = ufind(a);
    b = ufind(b);
    if(a == b) return false;
    pre[a] = b;
    return true;
}

int main() {
    // freopen("stdin.txt", "r", stdin);
    int T, N, M, i, a, b;
    char ch[2];
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &N, &M);
        memset(pre, 0, sizeof(int) * (2 * N + 1));
        while(M--) {
            scanf("%s%d%d", ch, &a, &b);
            if(*ch == 'D') {
                unite(a, b + N);
                unite(a + N, b);
            } else {
                if(same(a, b + N))
                    printf("In different gangs.\n");
                else if(same(a, b)) 
                    printf("In the same gang.\n");
                else printf("Not sure yet.\n");
            }
        }
    }
    return 0;
}