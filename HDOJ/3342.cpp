////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-01 09:49:08
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3342
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:216KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#define maxn 102

int queue[maxn], indegree[maxn];
bool map[maxn][maxn];

bool topoSort(int n)
{
    int front = 0, back = 0, i, u;
    for(i = 0; i < n; ++i)
        if(!indegree[i]) queue[back++] = i;
    while(front != back){
        u = queue[front++];
        for(i = 0; i < n; ++i)
            if(map[u][i] && !--indegree[i]) queue[back++] = i;
    }
    return back == n;
}

int main()
{
    int n, m, a, b;
    while(scanf("%d%d", &n, &m), n){
        memset(indegree, 0, sizeof(indegree));
        memset(map, 0, sizeof(map));
        while(m--){
            scanf("%d%d", &a, &b);
            if(!map[a][b]){
                map[a][b] = 1;
                ++indegree[b];
            }
        }
        if(topoSort(n))printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}