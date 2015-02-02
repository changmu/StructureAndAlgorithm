////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-01 14:59:39
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2647
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:596KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#define maxn 10002

int ans, queue[maxn];
struct Node{
    int to, next, val;
} map[maxn << 1];
struct node{
    int first, money, indegree;
} head[maxn];

bool topoSort(int n)
{
    int i, front = 0, back = 0, u;
    for(i = 1; i <= n; ++i)
        if(!head[i].indegree) queue[back++] = i;
    while(front != back){
        u = queue[front++];
        ans += head[u].money;
        for(i = head[u].first; i != 0; i = map[i].next)
            if(!--head[map[i].to].indegree){
                head[map[i].to].money = head[u].money + 1;
                queue[back++] = map[i].to;
            }
    }
    return back == n;
}

int main()
{
    int n, m, a, b, i;
    while(scanf("%d%d", &n, &m) != EOF){
        memset(head, 0, sizeof(head));
        for(i = 1; i <= m; ++i){
            scanf("%d%d", &a, &b);
            map[i].to = a;
            map[i].next = head[b].first;
            ++head[a].indegree;
            head[b].first = i;
        }
        ans = 888 * n;
        if(!topoSort(n)) printf("-1\n");
        else printf("%d\n", ans);
    }
    return 0;
}



