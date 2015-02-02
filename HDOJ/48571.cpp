////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-07-31 23:32:31
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4857
////Problem Title: 
////Run result: Accept
////Run time:375MS
////Run memory:1984KB
//////////////////System Comment End//////////////////
#include <cstdio>
#include <cstring>
#include <queue>
#define maxn 100002
using namespace std;

int head[maxn], indegree[maxn], ans[maxn];
struct Node{
    int to, next;
} map[maxn];

void topoSort(int n)
{
    priority_queue<int> Q;
    int i, u, id = 1;
    for(i = 1; i <= n; ++i)
        if(!indegree[i]) Q.push(i);
    while(!Q.empty()){
        ans[id++] = u = Q.top(); Q.pop();
        for(i = head[u]; i != -1; i = map[i].next)
            if(!--indegree[map[i].to]) Q.push(map[i].to);        
    }    
    for(i = n; i >= 1; --i)
        if(i != 1) printf("%d ", ans[i]);
        else printf("%d\n", ans[i]);
}

int main()
{
    int t, n, m, a, b, i;
    scanf("%d", &t);
    while(t--){
        memset(indegree, 0, sizeof(indegree));
        memset(head, -1, sizeof(head));
        scanf("%d%d", &n, &m);
        for(i = 0; i < m; ++i){
            scanf("%d%d", &a, &b);
            map[i].to = a;
            map[i].next = head[b];
            head[b] = i;
            ++indegree[a];
        }
        topoSort(n);
    }
    return 0;
}

