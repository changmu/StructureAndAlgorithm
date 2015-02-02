////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-07-28 12:43:36
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3631
////Problem Title: 
////Run result: Accept
////Run time:343MS
////Run memory:568KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#define INF -1
#define maxn 302

int map[maxn][maxn];
bool vis[maxn];

void Floyd(int k, int n)
{
    int j, i;
    for(i = 0; i < n; ++i)
        for(j = 0; j < n; ++j)
            if(map[i][k] != INF && map[k][j] != INF && (map[i][k] + map[k][j] < map[i][j] || map[i][j] == INF)){
                map[i][j] = map[i][k] + map[k][j];
            }
}

int main()
{
     //freopen("stdin.txt", "r", stdin);  
     //freopen("stdout.txt", "w", stdout);  

    int n, m, q, i, a, b, c, cas = 1;
    while(scanf("%d%d%d", &n, &m, &q), n || m || q){
        memset(map, INF, sizeof(map));
        memset(vis, 0, sizeof(vis));
        for(i = 0; i < n; ++i) map[i][i] = 0;
        for(i = 0; i < m; ++i){
            scanf("%d%d%d", &a, &b, &c);
            if(map[a][b] == -1 || c < map[a][b])
                map[a][b] = c;
        }
        if(cas != 1) printf("\n");;
        printf("Case %d:\n", cas++);
        while(q--){
            scanf("%d%d", &a, &b);
            if(a == 0){
                if(vis[b]) printf("ERROR! At point %d\n", b);
                else{
                	vis[b] = true;
                	Floyd(b, n);
                }
            }else{
                scanf("%d", &c);
                if(!vis[b] || !vis[c])
                    printf("ERROR! At path %d to %d\n", b, c);
                else if(map[b][c] == INF) printf("No such path\n");
                else printf("%d\n", map[b][c]);
            }
        }
    }
    return 0;
}


