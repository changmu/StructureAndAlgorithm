#include <stdio.h>
#define maxn 200002
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1

struct Node{
	int min, max;
} tree[maxn << 2];
int maxAns, minAns;

int maxVal(int a, int b)
{
	return a > b ? a : b;
}

int minVal(int a, int b)
{
	return a < b ? a : b;
}

void build(int l, int r, int rt)
{
	if(l == r){
		scanf("%d", &tree[rt].min);
		tree[rt].max = tree[rt].min;
		return;
	}
	
	int mid = (l + r) >> 1;
	build(lson);
	build(rson);
	
	tree[rt].max = maxVal(tree[rt << 1].max, tree[rt << 1 | 1].max);
	tree[rt].min = minVal(tree[rt << 1].min, tree[rt << 1 | 1].min);
}

void query(int left, int right, int l, int r, int rt)
{
	if(left == l && right == r){
		if(tree[rt].max > maxAns) maxAns = tree[rt].max;
		if(minAns > tree[rt].min) minAns = tree[rt].min;
		return;
	}
	
	int mid = (l + r) >> 1;
	if(right <= mid) query(left, right, lson);
	else if(left > mid) query(left, right, rson);
	else{
		query(left, mid, lson);
		query(mid + 1, right, rson);
	}
}

int main()
{
	int n, q, i, a, b;
	scanf("%d%d", &n, &q);
	
	build(1, n, 1);
	
	while(q--){
		scanf("%d%d", &a, &b);
		maxAns = 1; minAns = 1000000;
		query(a, b, 1, n, 1);
		printf("%d\n", maxAns - minAns);
	}
	
	return 0;
}