#include <stdio.h>
#include <string.h>
#define maxn 100002
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1
typedef long long ll;

struct Node{
	ll lazy, sum;
} tree[maxn << 2];

void pushUp(int rt){
	tree[rt].sum = tree[rt << 1].sum + tree[rt << 1 | 1].sum;
}

void pushDown(int l, int r, int rt)
{
	int mid = (l + r) >> 1;
	tree[rt << 1].sum += (mid - l + 1) * tree[rt].lazy;
	tree[rt << 1 << 1].sum += (r - mid) * tree[rt].lazy;
	tree[rt << 1].lazy += tree[rt].lazy;
	tree[rt << 1 | 1].lazy += tree[rt].lazy;
	tree[rt].lazy = 0;
}

void build(int l, int r, int rt)
{
	tree[rt].lazy = 0;
	if(l == r){
		scanf("%lld", &tree[rt].sum);
		return;
	}
	int mid = (l + r) >> 1;
	build(lson); build(rson);
	pushUp(rt);
}

void update(int left, int right, ll val, int l, int r, int rt)
{
	if(left == l && right == r){
		tree[rt].sum += (r - l + 1) * val;
		tree[rt].lazy += val; return;
	}
	int mid = (l + r) >> 1;
	if(tree[rt].lazy) pushDown(l, r, rt);
	if(right <= mid) update(left, right, val, lson);
	else if(left > mid) update(left, right, val, rson);
	else {
		update(left, mid, val, lson);
		update(mid + 1, right, val, rson);
	}
	pushUp(rt);
}

ll query(int left, int right, int l, int r, int rt)
{
	if(left == l && right == r) return tree[rt].sum;
	int mid = (l + r) >> 1;
	if(tree[rt].lazy) pushDown(l, r, rt);
	if(right <= mid) return query(left, right, lson);
	else if(left > mid) return query(left, right, rson);
	return query(left, mid, lson) + query(mid + 1, right, rson);
}

int main()
{
	int n, m, i, a, b;
	char com[2];
	ll c;
	while(scanf("%d%d", &n, &m) == 2){
		build(1, n, 1);
		while(m--){
			scanf("%s%d%d", com, &a, &b);
			if(com[0] == 'Q') 
				printf("%lld\n", query(a, b, 1, n, 1));
			else{
				scanf("%lld", &c);
				update(a, b, c, 1, n, 1);
			}
		}
	}
	return 0;
}