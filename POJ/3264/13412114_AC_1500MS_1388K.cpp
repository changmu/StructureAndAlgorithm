#include <stdio.h>
#include <algorithm>
#define inf 0x7fffffff
#define maxn 50002
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1
using namespace std;

struct Node{
	int maxv, minv;
} tree[maxn << 2];
int arr[maxn], minv, maxv;

void pushUp(int rt){
	tree[rt].maxv = max(tree[rt << 1].maxv, tree[rt << 1 | 1].maxv);
	tree[rt].minv = min(tree[rt << 1].minv, tree[rt << 1 | 1].minv);
}

void build(int l, int r, int rt)
{
	if(l == r){
		tree[rt].maxv = tree[rt].minv = arr[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(lson); build(rson);
	pushUp(rt);
}

void query(int left, int right, int l, int r, int rt)
{
	if(left == l && right == r){
		maxv = max(maxv, tree[rt].maxv);
		minv = min(minv, tree[rt].minv);
		return;
	}
	int mid = (l + r) >> 1;
	if(right <= mid) return query(left, right, lson);
	else if(left > mid) return query(left, right, rson);
	query(left, mid, lson); query(mid + 1, right, rson);
}

int main()
{
	int n, m, i, a, b;
	while(scanf("%d%d", &n, &m) == 2){
		for(i = 1; i <= n; ++i)
			scanf("%d", &arr[i]);
		build(1, n, 1);
		while(m--){
			scanf("%d%d", &a, &b);
			minv = inf; maxv = 0;
			query(a, b, 1, n, 1);
			printf("%d\n", maxv - minv);
		}
	}
	return 0;
}