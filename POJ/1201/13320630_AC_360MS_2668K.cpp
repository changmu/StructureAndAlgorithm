#include <stdio.h>
#include <string.h>
#include <queue>
#define maxn 50002
#define inf 0x3f3f3f3f
using std::queue;

int head[maxn], id, left, right, dist[maxn];
struct Node{
    int to, w, next;
} E[maxn << 2];
bool vis[maxn];

void addEdge(int a, int b, int c)
{
    E[id].to = b; E[id].w = c;
    E[id].next = head[a]; head[a] = id++;
}

int SPFA()
{
    int i, u, v, tmp;
    for(i = left; i <= right + 1; ++i){
        vis[i] = 0; dist[i] = inf;
    }
    queue<int> Q; Q.push(right);
    dist[right] = 0; vis[right] = 1;
    while(!Q.empty()){
        u = Q.front(); Q.pop();
        vis[u] = 0;
        for(i = head[u]; i != -1; i = E[i].next){
            v = E[i].to;
            tmp = dist[u] + E[i].w;
            if(tmp < dist[v]){
                dist[v] = tmp;
                if(!vis[v]){
                    vis[v] = 1;
                    Q.push(v);
                }
            }
        }
    }
    return -dist[left];
}

int main()
{
    //freopen("stdin.txt", "r", stdin);
    int n, a, b, c, i;
    while(scanf("%d", &n) == 1){
        memset(head, -1, sizeof(head));
        left = maxn; right = 0;
        for(i = id = 0; i < n; ++i){
            scanf("%d%d%d", &a, &b, &c);
            addEdge(b+1, a, -c);
            if(a < left) left = a;
            if(b > right) right = b;
        }
        ++right;
        for(i = left; i < right; ++i){
            addEdge(i+1, i, 0);
            addEdge(i, i+1, 1);
        }
        printf("%d\n", SPFA());
    }
    return 0;
}