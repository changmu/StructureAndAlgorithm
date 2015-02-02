////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-07-06 22:45:52
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1166
////Problem Title: 
////Run result: Accept
////Run time:343MS
////Run memory:1940KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#define maxn 50002

int arr[maxn];
struct Node{
	int left, right, sum;
} tree[maxn * 3];
char com[10];

void build(int left, int right, int rt)
{
	tree[rt].left = left; tree[rt].right = right;
	if(left == right){
		tree[rt].sum = arr[left]; return;
	}
	
	int mid = (left + right) >> 1;
	build(left, mid, rt << 1);
	build(mid + 1, right, rt << 1 | 1);
	
	tree[rt].sum = tree[rt<<1].sum + tree[rt<<1|1].sum;
}

void update(int pos, int val, int rt)
{
	if(tree[rt].left == tree[rt].right){
		tree[rt].sum += val; return;
	}
	
	int mid = (tree[rt].left + tree[rt].right) >> 1;
	if(pos <= mid) update(pos, val, rt << 1);
	else update(pos, val, rt << 1 | 1);
	
	tree[rt].sum = tree[rt<<1].sum + tree[rt<<1|1].sum;
}

int query(int left, int right, int rt)
{
	if(left == tree[rt].left && right == tree[rt].right)
		return tree[rt].sum;
		
	int mid = (tree[rt].left + tree[rt].right) >> 1;
	if(right <= mid) return query(left, right, rt << 1);
	else if(left > mid) return query(left, right, rt<<1|1);
	
	return query(left, mid, rt << 1) + 
		query(mid+1, right, rt<<1|1);
}

int main()
{
	int t, n, i, a, b;
	scanf("%d", &t);
	
	for(int cas = 1; cas <= t; ++cas){
		
		scanf("%d", &n);
		for(i = 1; i <= n; ++i)
			scanf("%d", arr + i);
		build(1, n, 1);
		printf("Case %d:\n", cas);
		
		while(scanf("%s", com)){
			if(com[0] == 'E') break;
			
			scanf("%d%d", &a, &b);
			if(com[0] == 'Q')				
				printf("%d\n", query(a, b, 1));
			else if(com[0] == 'A')
				update(a, b, 1);
			else update(a, -b, 1);			
		}
	}
	return 0;
}