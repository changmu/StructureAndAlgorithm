////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-17 08:32:13
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1384
////Problem Title: 
////Run result: Accept
////Run time:1593MS
////Run memory:2504KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <queue>
#include <string.h>
#define maxn 50010
#define inf 0x3f3f3f3f
using std::queue;

int head[maxn], id, dist[maxn];
int left, right;
struct Node{
    int to, w, next;
} E[maxn * 3];
bool vis[maxn];

void addEdge(int u, int v, int c)
{
    E[id].to = v; E[id].w = c;
    E[id].next = head[u]; head[u] = id++;
}

int SPFA()
{
    memset(dist, 0x3f, sizeof(dist));
    memset(vis, 0, sizeof(vis));
    int i, u, v, tmp;
    u = right; vis[u] = 1; dist[u] = 0;
    queue<int> Q; Q.push(u);
    while(!Q.empty()){
        u = Q.front(); Q.pop(); vis[u] = 0;
        for(i = head[u]; i != -1; i = E[i].next){
            tmp = dist[u] + E[i].w;
            v = E[i].to;
            if(tmp < dist[v]){
                dist[v] = tmp;
                if(!vis[v]){
                    vis[v] = true;
                    Q.push(v);
                }
            }
        }
    }
    return -dist[left];
}

int main()
{
    int n, a, b, c, i; 
    while(scanf("%d", &n) == 1){
        memset(head, -1, sizeof(head));
        left = inf; right = 0;
        for(i = id = 0; i < n; ++i){
            scanf("%d%d%d", &a, &b, &c);
            addEdge(b + 1, a, -c);
            if(left > a) left = a;
            if(right < b) right = b;
        }
        ++right;
        for(i = left; i < right; ++i){
            addEdge(i, i + 1, 1);
            addEdge(i + 1, i, 0);
        }
        printf("%d\n", SPFA());
    }
    return 0;
}
