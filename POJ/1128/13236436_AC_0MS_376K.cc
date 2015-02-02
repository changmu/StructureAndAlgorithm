#include <stdio.h>
#include <string.h>
#define maxn 32
#define maxm 28

char ori[maxn][maxn], ans[maxm];
int m, n, in[maxm], total;
bool map[maxm][maxm];
struct Node{
	int x, y;
} lt[maxm]; //leftButtom
struct Node2{
	int x, y;
} rb[maxm]; //rightTop

void getMap()
{
	int i, j, t, k, x, y;
	memset(map, 0, sizeof(map));
	memset(in, -1, sizeof(in));
	memset(lt, 0x3f, sizeof(lt));
	memset(rb, -1, sizeof(rb));
	for(i = total = 0; i < n; ++i)
		for(j = 0; j < m; ++j){
			if(ori[i][j] == '.') continue;
			t = ori[i][j] - 'A'; 
			if(in[t] == -1){
				in[t] = 0; //indicate t exist
				++total;
			}
			if(i < lt[t].x) lt[t].x = i;
			if(i > rb[t].x) rb[t].x = i;
			if(lt[t].y > j) lt[t].y = j;
			if(rb[t].y < j) rb[t].y = j;
		}
	for(i = 0; i < maxm; ++i){
		if(in[i] == -1) continue;
		for(x = lt[i].x; x <= rb[i].x; ++x)
			for(y = lt[i].y; y <= rb[i].y; ++y){
				if(x > lt[i].x && y > lt[i].y && x < rb[i].x && y < rb[i].y)
					continue;
				t = ori[x][y] - 'A';
				if(t != i && !map[i][t]){
					map[i][t] = true;
					++in[t];
				}
			}
	}
}

void DFS(int id) //fantastic!
{
	if(id == total){
		ans[id] = '\0';
		puts(ans); return;
	}
	for(int i = 0; i < maxm; ++i){
		if(in[i] == 0){
			ans[id] = 'A' + i;
			in[i] = -1;
			for(int j = 0; j < maxm; ++j)
				if(map[i][j]) --in[j];
			DFS(id + 1);
			in[i] = 0;
			for(int j = 0; j < maxm; ++j)
				if(map[i][j]) ++in[j];
		}
	}
}

int main()
{
	int i;
	while(scanf("%d%d", &n, &m) == 2){
		for(i = 0; i < n; ++i)
			scanf("%s", ori[i]);
		getMap();
		DFS(0);
	}
	return 0;
}