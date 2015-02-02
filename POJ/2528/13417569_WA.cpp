#include <stdio.h>
#include <string.h>
#include <algorithm>
#define inf 10000002
#define maxn 10002
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1
using namespace std;

bool tree[maxn << 5];
struct Node{
	int l, r;
} post[maxn];
int hash[inf], tmp[maxn << 1];

bool update(int left, int right, int l, int r, int rt)
{
	if(tree[rt]) return false;
	if(left == l && right == r){
		return tree[rt] = true;
	}
	bool rst, a, b;
	int mid = (l + r) >> 1;
	if(right <= mid) rst = update(left, right, lson);
	else if(left > mid) rst = update(left, right, rson);
	else {
		a = update(left, mid, lson);
		b = update(mid + 1, right, rson);
		rst = a || b;
	}
	tree[rt] = tree[rt << 1] && tree[rt << 1 | 1];
	return rst;
}

int main()
{
	int t, n, i, id, num, count, ans;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(i = id = 0; i < n; ++i){
			scanf("%d%d", &post[i].l, &post[i].r);
			tmp[id++] = post[i].l;
			tmp[id++] = post[i].r;
		}
		sort(tmp, tmp + id);
		num = unique(tmp, tmp + id) - tmp;
		for(i = count = 0; i < num; ++i){
			hash[tmp[i]] = count;
			if(i < num - 1) count += 2;
			
		}
		memset(tree, 0, sizeof(tree));
		for(i = n - 1, ans = 0; i >= 0; --i){
			if(update(hash[post[i].l], hash[post[i].r], 0, count, 1))
				++ans;
		}
		printf("%d\n", ans);
	}
	return 0;
}