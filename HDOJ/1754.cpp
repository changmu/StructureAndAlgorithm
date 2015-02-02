////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-07-07 11:20:55
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1754
////Problem Title: 
////Run result: Accept
////Run time:1109MS
////Run memory:7156KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#define maxn 200002

struct Node{
	int lson, rson;
	int max;
} tree[maxn << 2];
int stu[maxn];

int MAX(int a, int b)
{
	return a > b ? a : b;
}

void build(int left, int right, int rt)
{
	tree[rt].lson = left; tree[rt].rson = right;
	if(left == right){
		tree[rt].max = stu[left]; return;
	}
	
	int mid = (left + right) >> 1;
	build(left, mid, rt << 1);
	build(mid + 1, right, rt << 1 | 1);
	
	tree[rt].max = MAX(tree[rt<<1].max, tree[rt<<1|1].max);
}

void update(int pos, int val, int rt)
{
	if(tree[rt].lson == tree[rt].rson){
		tree[rt].max = val; return;
	}
	
	int mid = (tree[rt].lson + tree[rt].rson) >> 1;
	if(pos <= mid) update(pos, val, rt << 1);
	else update(pos, val, rt << 1 | 1);
	
	tree[rt].max = MAX(tree[rt<<1].max, tree[rt<<1|1].max);
}

int query(int left, int right, int rt)
{
	if(tree[rt].lson == left && right == tree[rt].rson){
		return tree[rt].max;
	}
	
	int mid = (tree[rt].lson + tree[rt].rson) >> 1;
	if(right <= mid) return query(left, right, rt << 1);
	else if(left > mid) 
		return query(left, right, rt << 1 | 1);
	return MAX(query(left, mid, rt << 1), query(mid+1, right, rt<<1|1));
}

int main()
{
	int N, M, i, m, n;
	char com[2];
	while(scanf("%d%d", &N, &M) == 2){
		for(i = 1; i <= N; ++i)
			scanf("%d", stu + i);
		build(1, N, 1);
		
		while(M--){
			scanf("%s%d%d", com, &m, &n);
			
			if(com[0] == 'U') update(m, n, 1);
			else printf("%d\n", query(m, n, 1));
		}
	}
	return 0;
}