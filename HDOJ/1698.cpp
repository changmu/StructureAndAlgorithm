////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-07-08 19:56:46
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1698
////Problem Title: 
////Run result: Accept
////Run time:921MS
////Run memory:2264KB
//////////////////System Comment End//////////////////
//#define DEBUG
#include <stdio.h>
#define maxn 100002
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1

int tree[maxn << 2], lazy[maxn << 2];

void pushDown(int l, int r, int rt)
{	
	int mid = (l + r) >> 1;
	tree[rt << 1] = (mid - l + 1) * lazy[rt];
	tree[rt << 1 | 1] = (r - mid) * lazy[rt];
	
	lazy[rt << 1] = lazy[rt << 1 | 1] = lazy[rt];
	lazy[rt] = 0;
}

void build(int l, int r, int rt)
{
	lazy[rt] = 0;
	if(l == r){
		tree[rt] = 1; return;
	}
	
	int mid = (l + r) >> 1;
	build(lson);
	build(rson);
	
	tree[rt] = tree[rt << 1] + tree[rt << 1 | 1];
}

void update(int left, int right, int val, int l, int r, int rt)
{
	if(left == l && right == r){
		tree[rt] = val * (r - l + 1);
		lazy[rt] = val; return;
	} //include l == r
	
	if(lazy[rt]) pushDown(l, r, rt);
	
	int mid = (l + r) >> 1;
	if(right <= mid) update(left, right, val, lson);
	else if(left > mid) update(left, right, val, rson);
	else{
		update(left, mid, val, lson);
		update(mid + 1, right, val, rson);
	}
	
	tree[rt] = tree[rt << 1] + tree[rt << 1 | 1];
}

int main()
{
	#ifdef DEBUG
	freopen("../stdin.txt", "r", stdin);
	freopen("../stdout.txt", "w", stdout);
	#endif
	
	int t, n, q, cas, a, b, c;
	scanf("%d", &t);
	for(cas = 1; cas <= t; ++cas){
		scanf("%d%d", &n, &q);
		
		build(1, n, 1);
		
		while(q--){
			scanf("%d%d%d", &a, &b, &c);
			update(a, b, c, 1, n, 1);
		}
		
		printf("Case %d: The total value of the hook is %d.\n", cas, tree[1]);
	}
	return 0;
}