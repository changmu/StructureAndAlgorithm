////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-14 20:32:04
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1010
////Problem Title: 
////Run result: Accept
////Run time:156MS
////Run memory:292KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#define maxn 10
using namespace std;

char map[maxn][maxn];
int n, m, t, dx, dy;
const int mov[][2] = {-1, 0, 1, 0, 0, 1, 0, -1};

bool check(int x, int y){
    return x >= 0 && x < n && y >= 0 && 
    	y < m && map[x][y] != 'X';
}

bool DFS(int x, int y, int step)
{
    if(x == dx && y == dy && step == t)
        return 1;
    int i, a, b, tmp;
    tmp = t - step - abs(dx - x) - abs(dy - y);
    if(tmp < 0 || tmp & 1) return 0;
    for(i = 0; i < 4; ++i){
        a = x + mov[i][0];
        b = y + mov[i][1];
        if(check(a, b)){
            map[a][b] = 'X';
            if(DFS(a, b, step + 1)) return 1;
            map[a][b] = '.';
        }
    }
    return 0;
}

int main()
{
	//freopen("stdin.txt", "r", stdin);
    int i, j, sx, sy, wall;
    while(scanf("%d%d%d", &n, &m, &t), n || m || t){
        for(i = wall = 0; i < n; ++i){
            //getchar();
            for(j = 0; j < m; ++j){
                cin >> map[i][j];
                if(map[i][j] == 'S'){
                    sx = i; sy = j;
                }else if(map[i][j] == 'D'){
                    dx = i; dy = j;
                }else if(map[i][j] == 'X')
                    ++wall;
            }
        }
        if(m * n - wall <= t){ //cut1
            printf("NO\n"); continue;
        }
        map[sx][sy] = 'X';
        if(DFS(sx, sy, 0)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
