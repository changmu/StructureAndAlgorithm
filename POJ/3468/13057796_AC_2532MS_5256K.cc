//#define DEBUG
#include <stdio.h>
#define maxn 100002
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1

long long tree[maxn << 2], arr[maxn], lazy[maxn << 2];

void pushUp(int rt)
{
	tree[rt] = tree[rt << 1] + tree[rt << 1 | 1];
}

void pushDown(int l, int r, int rt)
{
	int mid = (l + r) >> 1;
	
	tree[rt << 1] += (mid - l + 1) * lazy[rt];
	tree[rt << 1 | 1] += (r - mid) * lazy[rt];
	
	lazy[rt << 1] += lazy[rt];
	lazy[rt << 1 | 1] += lazy[rt];
	lazy[rt] = 0;
}

void build(int l, int r, int rt)
{
	lazy[rt] = 0;
	if(l == r){
		tree[rt] = arr[r]; return;
	}
	
	int mid = (l + r) >> 1;
	build(lson);
	build(rson);
	
	pushUp(rt);
}

void update(int left, int right, long long val, int l, int r, int rt)
{
	if(left == l && right == r){
		lazy[rt] += val; tree[rt] += val * (r - l + 1); return;
	} //include l == r
	
	if(lazy[rt]) pushDown(l, r, rt);
	
	int mid = (l + r) >> 1;
	if(right <= mid) update(left, right, val, lson);
	else if(left > mid) update(left, right, val, rson);
	else{
		update(left, mid, val, lson);
		update(mid + 1, right, val, rson);
	}
	
	pushUp(rt);
}

long long query(int left, int right, int l, int r, int rt)
{	
	if(left == l && right == r)
		return tree[rt];
		
	if(lazy[rt]) pushDown(l, r, rt);
	
	int mid = (l + r) >> 1;
	if(right <= mid){
		return query(left, right, lson);
	}else if(left > mid){
		return query(left, right, rson);
	}else{
		return query(left, mid, lson) + query(mid + 1, right, rson);
	}
}

int main()
{
	#ifdef DEBUG
	freopen("../stdin.txt", "r", stdin);
	freopen("../stdout.txt", "w", stdout);	
	#endif
	
	int n, q, i, a, b;
	long long c;
	char com[2];
	while(scanf("%d%d", &n, &q) == 2){
		for(i = 1; i <= n; ++i)
			scanf("%lld", arr + i);
		build(1, n, 1);
		
		while(q--){
			scanf("%s%d%d", com, &a, &b);
			if(com[0] == 'C'){
				scanf("%lld", &c);
				update(a, b, c, 1, n, 1);
			}else printf("%lld\n", query(a, b, 1, n, 1));
		}
	}
	return 0;
}