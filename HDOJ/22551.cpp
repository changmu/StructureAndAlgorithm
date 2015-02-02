////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-10-11 10:11:08
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2255
////Problem Title: 
////Run result: Accept
////Run time:390MS
////Run memory:596KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>

#define maxn 305
#define inf 0x3f3f3f3f

int G[maxn][maxn];
int Lx[maxn], Ly[maxn];
int match[maxn];
bool visx[maxn], visy[maxn];
int slack[maxn], n;

bool DFS(int cur) {
    int t, y;
    visx[cur] = true;
    for(y = 1; y <= n; ++y) {
        if(visy[y]) continue;
        t = Lx[cur] + Ly[y] - G[cur][y];
        if(t == 0) {
            visy[y] = true;
            if(match[y] == -1 || DFS(match[y])) {
                match[y] = cur; return true;
            }
        } else if(slack[y] > t) slack[y] = t; 
    }
    return false;
}

int KM() {
    int i, j, x, d, ret;
    memset(match, -1, sizeof(int) * (n + 1));
    memset(Ly, 0, sizeof(int) * (n + 1));
    for(i = 1; i <= n; ++i) {
        Lx[i] = -inf;
        for(j = 1; j <= n; ++j)
            if(G[i][j] > Lx[i]) Lx[i] = G[i][j];
    }
    for(x = 1; x <= n; ++x) {
        memset(slack, 0x3f, sizeof(int) * (n + 1));
        while(true) {
            memset(visx, 0, sizeof(bool) * (n + 1));
            memset(visy, 0, sizeof(bool) * (n + 1));
            if(DFS(x)) break;
            d = inf;
            for(i = 1; i <= n; ++i)
                if(!visy[i] && d > slack[i]) 
                    d = slack[i];
            for(i = 1; i <= n; ++i)
                if(visx[i]) Lx[i] -= d;
            for(i = 1; i <= n; ++i)
                if(visy[i]) Ly[i] += d;
                else slack[i] -= d;
        }
    }
    ret = 0;
    for(i = 1; i <= n; ++i)
        if(match[i] > -1) ret += G[match[i]][i];
    return ret;
}

int main() {
    // freopen("stdin.txt", "r", stdin);
    int i, j;
    while(scanf("%d", &n) == 1) {
        for(i = 1; i <= n; ++i)
            for(j = 1; j <= n; ++j)
                scanf("%d", &G[i][j]);
        printf("%d\n", KM());
    }
    return 0;
}
