#include <stdio.h>
#include <string.h>

#define maxn 16
#define inf 0x3f3f3f3f

int cow[maxn][maxn], M, N; // 原始数据 M rows
int flip[maxn][maxn]; // 保存中间结果
int opt[maxn][maxn]; // 保存最优结果
const int mov[][2] = {0, 0, 0, -1, 0, 1, -1, 0}; // 中左右上

void getMap() {
    int i, j;
    for(i = 0; i < M; ++i)
        for(j = 0; j < N; ++j)
            scanf("%d", &cow[i][j]);
}

int getColo(int x, int y) {
    int c = cow[x][y], xa, ya, i;
    for(i = 0; i < 4; ++i) {
        xa = x + mov[i][0];
        ya = y + mov[i][1];
        if(xa >= 0 && xa < M && ya >= 0 && ya < N) {
            c += flip[xa][ya];
        }
    }
    return c & 1;
}

int DFS(int k) {
    int i, j, sum;
    if(k == M - 1) { // 最后一行不再翻转，判断是否都0
        for(i = 0; i < N; ++i)
            if(getColo(k, i)) break;
        if(i != N) return -1;
        // 统计翻转次数
        for(i = sum = 0; i < M; ++i)
            for(j = 0; j < N; ++j)
                if(flip[i][j] & 1) ++sum;
        return sum;
    }
    for(j = 0; j < N; ++j)
        if(getColo(k, j)) flip[k + 1][j] = 1;
    return DFS(k + 1);
}

void solve() {
    int i, j, maxCase = 1 << N, ret = inf, num, tmp;
    for(i = 0; i < maxCase; ++i) {
        memset(flip, 0, sizeof(flip));
        for(j = N - 1, tmp = i; j >= 0; --j, tmp >>= 1) {
            flip[0][j] = tmp & 1;
        }
        num = DFS(0);
        if(num != -1 && num < ret) {
            ret = num;
            memcpy(opt, flip, sizeof(flip));
        }
    }

    if(ret == inf) printf("IMPOSSIBLE\n");
    else {
        for(i = 0; i < M; ++i)
            for(j = 0; j < N; ++j)
                if(j == N - 1) printf("%d\n", opt[i][j]);
                else printf("%d ", opt[i][j]);
    }
}

int main() {
    // freopen("stdin.txt", "r", stdin);
    while(scanf("%d%d", &M, &N) == 2) {
        getMap();
        solve();
    }
    return 0;
}