////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-17 13:15:57
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1875
////Problem Title: 
////Run result: Accept
////Run time:140MS
////Run memory:328KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#define maxn 102
#define maxm (maxn * maxn) >> 1
using std::sort;

int pre[maxn], count, id;
struct Node2{
    int x, y;
} V[maxn];
struct Node{
    int u, v;
    double d;
} E[maxm];
double ans;

int ufind(int k)
{
    int a = k, b;
    while(pre[k] != -1) k = pre[k];
    while(a != k){
        b = pre[a];
        pre[a] = k;
        a = b;
    }
    return k;
}

bool cmp(Node a, Node b){
    return a.d < b.d;
}

double calDist(int i, int j)
{
    double x = V[i].x - V[j].x;
    double y = V[i].y - V[j].y;
    return sqrt(x * x + y * y);
}

bool Kruskal(int n, int m)
{
    ans = 0;
    int i, u, v;
    for(i = 0; i < m; ++i){
        u = ufind(E[i].u);
        v = ufind(E[i].v);
        if(u != v && E[i].d >= 10 && E[i].d <= 1000){
            ans += E[i].d; pre[v] = u;
            if(--count == 1) return true;
        }
    }
    return 1 == count;
}

int main()
{
    int t, n, i, j;
    scanf("%d", &t);
    while(t--){
        memset(pre, -1, sizeof(pre));
        scanf("%d", &n);
        count = n;
        for(i = 1; i <= n; ++i)
            scanf("%d%d", &V[i].x, &V[i].y);
        for(i = 1, id = 0; i < n; ++i)
            for(j = i + 1; j <= n; ++j){
                E[id].u = i; E[id].v = j;
                E[id++].d = calDist(i, j);
            }
        sort(E, E + id, cmp);
        if(!Kruskal(n, id)) printf("oh!\n");
        else printf("%.1lf\n", ans * 100.0);
    }
}