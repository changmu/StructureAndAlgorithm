#include <stdio.h>
#include <math.h>
#include <string.h>

#define maxn 202
#define inf 0x3f3f3f3f

int n;
struct Node {
	int x, y;
} Stone[maxn];
double map[maxn][maxn], dis[maxn];
bool vis[maxn];

double min(double a, double b) {
	return a < b ? a : b;
}

double max(double a, double b) {
	return a > b ? a : b;
}

double calDis(int i, int j) {
	double x = Stone[i].x - Stone[j].x;
	double y = Stone[i].y - Stone[j].y;
	return sqrt(x * x + y * y);
}

int getNext() {
	int pos = -1, i;
	double val = inf;
	for(i = 0; i < n; ++i)
		if(!vis[i] && dis[i] < val) {
			val = dis[i]; pos = i; 
		}
	return pos;
}

void Dijkstra(int start, int end) {
	int u = start, v, i;
	for(i = 0; i < n; ++i) {
		vis[i] = 0; dis[i] = inf;
	}
	dis[u] = 0.0;
	while(u != -1) {
		vis[u] = 1;
		for(i = 0; i < n; ++i)
			dis[i] = min(dis[i], max(map[u][i], dis[u]));
		u = getNext();
		if(u == end) return;
	}
}

int main() {
	// freopen("stdin.txt", "r", stdin);
	int i, j, cas = 1;
	while(scanf("%d", &n), n) {
		for(i = 0; i < n; ++i) {
			scanf("%d%d", &Stone[i].x, &Stone[i].y);
			for(j = 0; j < i; ++j)
				map[i][j] = map[j][i] = calDis(i, j);
			map[i][i] = 0.0;
		}
		Dijkstra(0, 1);
		printf("Scenario #%d\nFrog Distance = %.3lf\n\n", cas++, dis[1]);
	}
	return 0;
}