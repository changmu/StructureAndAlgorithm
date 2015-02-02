////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-18 15:41:58
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3440
////Problem Title: 
////Run result: Accept
////Run time:531MS
////Run memory:336KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#define inf 0x7fffffff
#define maxn 1002
using namespace std;

int head[maxn], dist[maxn], id, out[maxn];
struct Node2{
    int v, num;
} V[maxn];
struct Node{
    int to, d, next;
} E[maxn * maxn];
bool vis[maxn];

bool cmp(Node2 a, Node2 b){
    return a.v < b.v;
}

void addEdge(int u, int v, int d)
{
    E[id].to = v; E[id].d = d;
    E[id].next = head[u]; head[u] = id++;
}

int SPFA(int s, int t, int n)
{
    int i, u, v, tmp;
    for(i = 0; i <= n; ++i){
        dist[i] = inf; vis[i] = 0;
        out[i] = 0;
    }
    u = s; dist[u] = 0; vis[u] = 1;
    queue<int> Q; Q.push(u);
    while(!Q.empty()){
        u = Q.front(); Q.pop(); vis[u] = 0;
        if(++out[u] > n) return -1;
        for(i = head[u]; i != -1; i = E[i].next){
            tmp = dist[u] + E[i].d; v = E[i].to;
            if(tmp < dist[v]){
                dist[v] = tmp;
                if(!vis[v]){
                    vis[v] = 1; Q.push(v);
                }
            }
        }
    }
    return dist[t];
}

int main()
{
    int t, n, m, i, cas = 1, u, v;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        memset(head, -1, sizeof(head));
        for(i = 1, id = 0; i <= n; ++i){
            scanf("%d", &V[i].v);
            V[i].num = i;
            if(i != n) addEdge(i + 1, i, -1);
        }
        sort(V + 1, V + n + 1, cmp);
        for(i = 1; i < n; ++i){
            u = V[i].num; v = V[i+1].num;
            if(u > v) swap(u, v);
            addEdge(u, v, m);
        }
        printf("Case %d: ", cas++);
        u = V[1].num; v = V[n].num;
        if(u > v) swap(u, v);
        printf("%d\n", SPFA(u, v, n));
    }
    return 0;
}