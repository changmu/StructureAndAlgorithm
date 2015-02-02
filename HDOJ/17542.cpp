////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-01 23:41:48
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1754
////Problem Title: 
////Run result: Accept
////Run time:1109MS
////Run memory:2260KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#define maxn 200002
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1

int tree[maxn << 2];

int max(int a, int b){
	return a > b ? a : b;
}

void pushUp(int rt){
	tree[rt] = max(tree[rt << 1], tree[rt << 1 | 1]);
}

void build(int l, int r, int rt)
{
	if(l == r){
		scanf("%d", &tree[rt]);
		return;
	}
	int mid = (l + r) >> 1;
	build(lson);
	build(rson);
	pushUp(rt);
}

void update(int pos, int val, int l, int r, int rt)
{
	if(l == r){
		tree[rt] = val; return;
	}
	int mid = (l + r) >> 1;
	if(pos <= mid) update(pos, val, lson);
	else update(pos, val, rson);
	pushUp(rt);
}

int query(int left, int right, int l, int r, int rt)
{
	if(left == l && right == r) return tree[rt];
	int mid = (l + r) >> 1;
	if(right <= mid) return query(left, right, lson);
	else if(left > mid) return query(left, right, rson);
	else return max(query(left, mid, lson), query(mid + 1, right, rson));
}

int main()
{
	int n, m, a, b;
	char com[2];
	while(scanf("%d%d", &n, &m) != EOF){
		build(1, n, 1);
		while(m--){
			scanf("%s%d%d", com, &a, &b);
			if(com[0] == 'Q') 
				printf("%d\n", query(a, b, 1, n, 1));
			else update(a, b, 1, n, 1);
		}
	}
	return 0;
}