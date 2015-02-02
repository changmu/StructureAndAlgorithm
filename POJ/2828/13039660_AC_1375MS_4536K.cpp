#include <stdio.h>
#define maxn 200002
#define lson l, mid, rt << 1
#define rson mid, r, rt << 1 | 1

struct Node{
	int pos, val;
} arr[maxn];
int tree[maxn << 2], ans[maxn];

void build(int l, int r, int rt)
{
	tree[rt] = r - l;
	if(tree[rt] == 1) return;
	
	int mid = (l + r) >> 1;
	build(lson);
	build(rson);
}

void update(int pos, int val, int l, int r, int rt)
{
	--tree[rt];
	if(r - l == 1){
		ans[l] = val; return;
	}
	
	int mid = (l + r) >> 1;
	if(tree[rt << 1] > pos) update(pos, val, lson);
	else update(pos - tree[rt << 1], val, rson);
}

int main()
{
	int n, pos, val, i;
	while(scanf("%d", &n) == 1){
		for(i = 0; i < n; ++i)
			scanf("%d%d", &arr[i].pos, &arr[i].val);
			
		build(0, n, 1); //注意右端点，线段树存储的是线段信息
		
		for(i = n - 1; i >= 0; --i)
			update(arr[i].pos, arr[i].val, 0, n, 1);
			
		for(i = 0; i < n; ++i)
			printf("%d%c", ans[i], i != (n - 1) ? ' ' : '\n');
		
	}
	return 0;
}