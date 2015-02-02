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
	//printf("%d %d: %.2lf %.2lf\n", l, r, T[rt].x, T[rt].y);
}

void update(int L, int R, double rad, int l, int r, int rt) {
	double x, y;
	if(L == l && R == r) {
		//printf("00 %.2lf: %.2lf %.2lf\n", rad, T[rt].x, T[rt].y);
		x = T[rt].x * cos(rad) + T[rt].y * sin(rad);
		y = T[rt].y * cos(rad) - T[rt].x * sin(rad);
		T[rt].x = x; T[rt].y = y;
		T[rt].lazy += rad;
		//printf("01 %.2lf: %.2lf %.2lf\n", rad, T[rt].x, T[rt].y);
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
	double rad;
	while(scanf("%d%d", &N, &C) == 2) {
		build(0, N, 1);
		if(cas++) printf("\n");
		while(C--) {
			scanf("%d%d", &x, &y);
			// ½Ç¶È×ª»¡¶È 
			rad = y / 360.0 * 2 * PI;
			update(x, N, rad, 0, N, 1);
			printf("%.2lf %.2lf\n", T[1].x + esp, T[1].y + esp);
		}
	}
	return 0;
}
/*
Sample Output

5.00 10.00

-10.00 5.00
-5.00 10.00
*/