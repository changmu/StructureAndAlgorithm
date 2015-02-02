#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long LL;

#define maxn 302
#define inf 0x3f3f3f3f

int G[maxn][maxn], N, M;
int sta[maxn];

void Floyd(){
    int i, j, k;
    for(k = 1; k <= N; ++k)
        for(i = 1; i <= N; ++i)
            for(j = 1; j <= N; ++j)
                if(G[i][k] + G[k][j] < G[i][j])
                    G[i][j] = G[i][k] + G[k][j];  
}

int main() {
    // freopen("stdin.txt", "r", stdin);
    int i, j, num, ans = inf;
    memset(G, 0x3f, sizeof(G));
    scanf("%d%d", &N, &M);
    for(i = 1; i <= N; ++i)
        G[i][0] = G[i][i] = 0;
    while(M--) {
        scanf("%d", &num);
        for(i = 0; i < num; ++i) {
            scanf("%d", sta + i);
            for(j = 0; j < i; ++j)
                G[sta[i]][sta[j]] = G[sta[j]][sta[i]] = 1;
        }
    }
    Floyd();
    for(i = 1; i <= N; ++i) {
        for(j = 1; j <= N; ++j)
            G[i][0] += G[i][j];
        if(ans > G[i][0]) ans = G[i][0]; 
    }
    printf("%d\n", ans * 100 / (N - 1));
    return 0;
}