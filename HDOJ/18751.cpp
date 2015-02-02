////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-07-29 15:35:49
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1875
////Problem Title: 
////Run result: Accept
////Run time:328MS
////Run memory:296KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <math.h>
#define maxn 102

double map[maxn][maxn];
bool vis[maxn];
struct Node{
    int x, y;
} arr[maxn];

double cal(Node a, Node b)
{
    double x = a.x - b.x, y = a.y - b.y;
    return sqrt(x * x + y * y);
}

void Prim(int n)
{
    int u, i, j, count = 0;
    double len = 0, tmp;
    vis[0] = 1;
    while(count < n - 1){
        for(i = 0, tmp = -1; i < n; ++i){
            if(!vis[i]) continue;
            for(j = 0; j < n; ++j){
                if(map[i][j] != 0 && !vis[j] && (map[i][j] < tmp || tmp < 0)){
                    tmp = map[i][j]; u = j;
                }
            }
        }
        if(tmp > 0){
            ++count; vis[u] = 1;
            len += tmp * 100;
        }else break;
    }
    if(count == n - 1) printf("%.1lf\n", len);
    else printf("oh!\n");
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t, n, a, b, i, j;
    double len;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        memset(map, 0, sizeof(map));
        memset(vis, 0, sizeof(vis));
        for(i = 0; i < n; ++i){
            scanf("%d%d", &arr[i].x, &arr[i].y);
            for(j = 0; j < i; ++j){
                len = cal(arr[i], arr[j]);
                if(len >= 10 && len <= 1000){
                    if(map[i][j] == 0 || len < map[i][j])
                        map[i][j] = map[j][i] = len;
                }
            }
        }
        Prim(n);
    }
    return 0;
}
