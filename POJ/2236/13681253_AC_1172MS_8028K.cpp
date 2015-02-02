#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long LL;

#define maxn 1002
#define inf 0x3f3f3f3f

double G[maxn][maxn];
int N, D, pre[maxn];
struct Node {
    int x, y;
} node[maxn];
bool opd[maxn];

int ufind(int k) {
    int a = k, b;
    while(pre[k]) k = pre[k];
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

bool unite(int a, int b) {
    a = ufind(a);
    b = ufind(b);
    if(a == b) return false;
    pre[a] = b;
    return true;
}

double calDist(int i, int j) {
    double x = node[i].x - node[j].x;
    double y = node[i].y - node[j].y;
    return sqrt(x * x + y * y);
}

int main() {
    // freopen("stdin.txt", "r", stdin);
    int x, y, i, j;
    char ch[2];
    scanf("%d%d", &N, &D);
    for(i = 1; i <= N; ++i) {
        for(j = 1; j <= N; ++j)
            G[i][j] = inf;
        if(i == j) G[i][j] = 0.0;
    }
    for(i = 1; i <= N; ++i) {
        scanf("%d%d", &x, &y);
        node[i].x = x;
        node[i].y = y;
        for(j = 1; j < i; ++j) {
            G[i][j] = G[j][i] = calDist(i, j);
        }
    }
    while(scanf("%s%d", ch, &x) != EOF) {
        if(*ch == 'O') {
            opd[x] = true;
            for(i = 1; i <= N; ++i)
                if(opd[i] && G[x][i] <= D) unite(x, i);
        }
        else {
            scanf("%d", &y);
            if(same(x, y)) printf("SUCCESS\n");
            else printf("FAIL\n");
        }
    }
    return 0;
}