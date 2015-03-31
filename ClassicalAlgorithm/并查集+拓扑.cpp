/************************************************************* 
 * 缩点+拓扑排序：
 * 有N个人M组关系：
 *      a < b
 *      a = b
 *      a > b
 * 分别表示a的得分小于b，等于和大于b
 * 问：比赛结果，共三种: "能", "信息冲突", "不确定"
 *************************************************************/ 
#include <stdio.h>
#include <string.h>

const int maxn = 10010;
int in[maxn], layer[maxn];
int head[maxn], pre[maxn], N, M, id;
struct ListNode {
    int u, v, next;
} E[maxn<<1];

int max(int a, int b) { return a > b ? a : b; }

int uFind(int k) {
    return pre[k] == -1 ? k : pre[k] = uFind(pre[k]);
}

void unite(int x, int y) {
    x = uFind(x);
    y = uFind(y);

    if (x != y) 
        pre[x] = y;
}

int toHash(int k) {
    int *hash = layer;
    k = uFind(k);
    return hash[k] ? hash[k] : hash[k] = ++N;
}

void getMap() {
    int i, u, v;
    char ch[2];

    for (i = id = 0; i <= N; ++i) {
        layer[i] = in[i] = 0;
        head[i] = pre[i] = -1;
    }

    while (M--) {       // raw data
        scanf("%d%s%d", &u, ch, &v);

        if (*ch == '=') unite(u, v);
        else if (*ch == '>') {
            E[id].u = u;
            E[id++].v = v;
        } else {
            E[id].u = v;
            E[id++].v = u;
        }
    }

    for (i = 0, u = N, N = 0; i < u; ++i)
        toHash(i);

    for (i = 0; i < id; ++i) {
        E[i].u = toHash(E[i].u);
        E[i].v = toHash(E[i].v);
        E[i].next = head[E[i].u];
        head[E[i].u] = i;
        ++in[E[i].v];
    }
}

int topo() {
    memset(layer, 0, sizeof(int) * (N + 1));

    int *que = pre, u, v, i;
    int front = 0, back = 0;
    int maxLayer = 0;

    for (i = 1; i <= N; ++i)
        if (in[i] == 0) que[back++] = i;

    while (front != back) {
        u = que[front++];
        for (i = head[u]; i != -1; i = E[i].next)
            if (!--in[E[i].v]) {
                que[back++] = E[i].v;
                layer[E[i].v] = layer[u] + 1;
            }
        maxLayer = max(maxLayer, layer[u]);
    }

    if (back == N) {
        if (maxLayer >= N - 1) // attemtion! if N == 0
            return 0;
        else return 2;
    } else return 1;
}

int main() {
    const char *sam[] = {"OK", "CONFLICT", "UNCERTAIN"};

    while (scanf("%d%d", &N, &M) == 2) {
        getMap();
        puts(sam[topo()]);
    }

    return 0;
}
