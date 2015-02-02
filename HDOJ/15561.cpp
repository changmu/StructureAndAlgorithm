////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-07-13 21:31:02
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1556
////Problem Title: 
////Run result: Accept
////Run time:984MS
////Run memory:1772KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#define maxn 100002
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1

int tree[maxn << 2], n;

void pushDown(int rt)
{
	tree[rt << 1] += tree[rt];
	tree[rt << 1 | 1] += tree[rt];
	tree[rt] = 0;
}

void update(int left, int right, int l, int r, int rt)
{
	if(left == l && right == r){
		++tree[rt]; return;
	}
	
	int mid = (l + r) >> 1;
	if(right <= mid) update(left, right, lson);
	else if(left > mid) update(left, right, rson);
	else{
		update(left, mid, lson);
		update(mid + 1, right, rson);
	}
}

void query(int l, int r, int rt)
{
	if(l == r){
		if(l != n) printf("%d ", tree[rt]);
		else printf("%d\n", tree[rt]);
		return;
	}
	
	if(tree[rt]) pushDown(rt);
	
	int mid = (l + r) >> 1;
	query(lson);
	query(rson);
}

int main()
{
	int a, b, i;
	while(scanf("%d", &n), n){
		memset(tree, 0, sizeof(tree));
		
		for(i = 0; i < n; ++i){
			scanf("%d%d", &a, &b);
			update(a, b, 1, n, 1);
		}
		
		query(1, n, 1);
	}
	return 0;
}