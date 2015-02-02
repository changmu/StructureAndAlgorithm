#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long LL;

#define maxn 1002
#define maxm 200010
#define inf 0x3f3f3f3f

int N, M, id, pre[maxn];
struct Node {
    int u, v, w;
} E[maxm];

bool cmp(Node a, Node b) {
    return a.w > b.w;
}

int ufind(int k){
    int a = k, b;
    while(pre[k]) k = pre[k];
    while(a != k){
        b = pre[a];
        pre[a] = k;
        a = b;
    }
    return k;
}

bool unite(int a, int b) {
    a = ufind(a);
    b = ufind(b);
    if(a == b) return false;
    else {
        pre[a] = b;
        return true;
    }
}

void addEdge(int u, int v, int w) {
    E[id].u = u; 
    E[id].v = v;
    E[id].w = w;
}

void getMap() {
    int u, v, w, i, j; id = 0;
    while(M--) {
        scanf("%d%d%d", &u, &v, &w);
        addEdge(u, v, w); ++id;
        addEdge(v, u, w); ++id;
    }
}

void Kruskal() {
    int i, j, u = 1, v, w, sum = 0;
    sort(E, E + id, cmp);
    for(i = 0; i < id && N != 1; ++i) {
        if(unite(E[i].u, E[i].v)) {
            --N; sum += E[i].w;
        }
    }
    printf("%d\n", N == 1 ? sum : -1);
}

int main() {
    // freopen("stdin.txt", "r", stdin);
    scanf("%d%d", &N, &M);
    getMap();
    Kruskal();
    return 0;
}