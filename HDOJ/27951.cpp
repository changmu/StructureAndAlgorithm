////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-07-07 18:21:17
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2795
////Problem Title: 
////Run result: Accept
////Run time:3531MS
////Run memory:2260KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#define maxn 200002
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1

int tree[maxn << 2];
int h, w, n, temp;

int max(int a, int b)
{
	return a > b ? a : b;
}

void build(int l, int r, int rt)
{
	if(l == r){
		tree[rt] = w; return;
	}
	
	int mid = (l + r) >> 1;
	build(lson);
	build(rson);
	tree[rt] = w;
}

void query(int val, int l, int r, int rt)
{
	if(tree[rt] < val){
		printf("-1\n"); return;
	}
	
	if(l == r){
		tree[rt] -= val;
		printf("%d\n", r);
		return;
	}
	
	int mid = (l + r) >> 1;
	if(tree[rt << 1] >= val) query(val, lson);	
	else query(val, rson);
	
	tree[rt] = max(tree[rt << 1], tree[rt << 1 | 1]);		
}

int main()
{	
	int t;
	while(scanf("%d%d%d", &h, &w, &n) == 3){		
		build(1, t = h < n ? h : n, 1);
		while(n--){
			scanf("%d", &temp);
			query(temp, 1, t, 1);
		}
	}
	return 0;
}