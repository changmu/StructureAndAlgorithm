#include <stdio.h>
#include <string.h>
#include <math.h>

#define maxn 10002
#define esp 1e-9
#define lson l, mid, rt << 1
#define rson mid, r, rt << 1 | 1

const double PI = acos(-1.0);

struct Node {
	double x, y, lazy;
} T[maxn << 2];
int N, C;
double pre[maxn], degree[maxn];

void build(int l, int r, int rt) {
	T[rt].x = T[rt].lazy = 0.0;
	if(r - l == 1) {
		scanf("%lf", &T[rt].y);
		return;
	}
	int mid = l + r >> 1;
	build(lson);
	build(rson);
	T[rt].y = T[rt << 1].y + T[rt << 1 | 1].y;
}

void update(int L, int R, double rad, int l, int r, int rt) {
	double x, y;
	if(L == l && R == r) {
		x = T[rt].x * cos(rad) + T[rt].y * sin(rad);
		y = T[rt].y * cos(rad) - T[rt].x * sin(rad);
		T[rt].x = x; T[rt].y = y;
		T[rt].lazy += rad;
		return;
	}
	int mid = l + r >> 1;
	if(T[rt].lazy) {
		x = T[rt<<1].x * cos(T[rt].lazy) + T[rt<<1].y * sin(T[rt].lazy);
		y = T[rt<<1].y * cos(T[rt].lazy) - T[rt<<1].x * sin(T[rt].lazy);
		T[rt<<1].x = x; T[rt<<1].y = y;
		T[rt<<1].lazy += T[rt].lazy;
		x = T[rt<<1|1].x * cos(T[rt].lazy) + T[rt<<1|1].y * sin(T[rt].lazy);
		y = T[rt<<1|1].y * cos(T[rt].lazy) - T[rt<<1|1].x * sin(T[rt].lazy);
		T[rt<<1|1].x = x; T[rt<<1|1].y = y;
		T[rt<<1|1].lazy += T[rt].lazy;
		T[rt].lazy = 0.0;
	}
	if(R <= mid) update(L, R, rad, lson);
	else if(L >= mid) update(L, R, rad, rson);
	else {
		update(L, mid, rad, lson);
		update(mid, R, rad, rson);
	}
	T[rt].y = T[rt << 1].y + T[rt << 1 | 1].y;
	T[rt].x = T[rt << 1].x + T[rt << 1 | 1].x;
}

int main() {
	//freopen("stdin.txt", "r", stdin);
	int i, j, x, y, cas = 0;
	double rad, tmp;
	while(scanf("%d%d", &N, &C) == 2) {
		build(0, N, 1);
		if(cas++) printf("\n");
		for(i = 1; i <= N; ++i)
			pre[i] = PI; 
		
		while(C--) {
			scanf("%d%d", &x, &y);
			rad = y / 360.0 * 2 * PI;
			update(x, N, pre[x] - rad, 0, N, 1);
			pre[x] = rad;
			printf("%.2lf %.2lf\n", T[1].x, T[1].y);
		}
	}
	return 0;
}