////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-10-27 23:00:59
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1556
////Problem Title: 
////Run result: Accept
////Run time:656MS
////Run memory:2292KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>

#define maxn 100002
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1

struct Node {
	int val, lazy;
} T[maxn << 2];
int n, num;

void pushDown(int rt) {
	T[rt<<1].lazy += T[rt].lazy;
	T[rt<<1|1].lazy += T[rt].lazy;
	T[rt<<1].val += T[rt].lazy;
	T[rt<<1|1].val += T[rt].lazy;
	T[rt].lazy = 0;
}

void build(int l, int r, int rt) {
	T[rt].lazy = T[rt].val = 0;
	if(l == r) return;
	int mid = (l + r) >> 1;
	build(lson);
	build(rson);
}

void update(int L, int R, int l, int r, int rt) {
	if(L == l && R == r) {
		++T[rt].val;
		++T[rt].lazy;
		return;
	}
	if(T[rt].lazy) pushDown(rt);
	int mid = (l + r) >> 1;
	if(R <= mid) update(L, R, lson);
	else if(L > mid) update(L, R, rson);
	else {
		update(L, mid, lson);
		update(mid + 1, R, rson);
	}
}

void query(int l, int r, int rt) {
	if(l == r) {
		printf("%d", T[rt].val);
		putchar(++num == n ? '\n'  : ' ');
		return;
	}
	int mid = (l + r) >> 1;
	if(T[rt].lazy) pushDown(rt);
	query(lson);
	query(rson);
}

int main() {
	// freopen("stdin.txt", "r", stdin);
	int a, b, i;
	while(scanf("%d", &n), n) {
		build(1, n, 1);
		for(i = 0; i < n; ++i) {
			scanf("%d%d", &a, &b);
			update(a, b, 1, n, 1);
		}
		num = 0;
		query(1, n, 1);
	}
	return 0;
}