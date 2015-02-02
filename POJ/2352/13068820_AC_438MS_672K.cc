#include <stdio.h>
#define maxn 32002
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1

int tree[maxn << 2], level[maxn];

void pushUp(int rt)
{
	tree[rt] = tree[rt << 1] + tree[rt << 1 | 1];
}

void update(int pos, int l, int r, int rt)
{
	if(l == r){
		++tree[rt]; return;
	}
	
	int mid = (l + r) >> 1;
	if(pos <= mid) update(pos, lson);
	else update(pos, rson);
	
	pushUp(rt);
}

int query(int left, int right, int l, int r, int rt)
{
	if(l == left && r == right) return tree[rt];
	
	int mid = (l + r) >> 1;
	if(right <= mid) return query(left, right, lson);
	else if(left > mid) return query(left, right, rson);
	else return query(left, mid, lson) + query(mid + 1, right, rson);
}

int main()
{
	int n, x, y, i;
	scanf("%d", &n);
	
	for(i = 0; i < n; ++i){
		scanf("%d%d", &x, &y);
		++level[query(0, ++x, 0, maxn - 1, 1)];
		update(x, 0, maxn - 1, 1);
	}
	
	for(i = 0; i < n; ++i)
		printf("%d\n", level[i]);
	
	return 0;
}