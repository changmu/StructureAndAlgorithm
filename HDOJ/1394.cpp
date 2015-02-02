////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: 长木
////Run ID: 
////Submit time: 2014-07-07 16:23:33
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1394
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1
#define maxn 5002

int tree[maxn << 2];
int arr[maxn];

void build(int l, int r, int rt)
{
	tree[rt] = 0;
	if(l == r) return;
	
	int mid = (l + r) >> 1;
	build(lson);
	build(rson);
}

void update(int pos, int l, int r, int rt)
{
	if(l == r){
		tree[rt] = 1; return; //tree[rt] = 1;
	}
	
	int mid = (l + r) >> 1;
	if(pos <= mid) update(pos, lson);
	else update(pos, rson);
	
	tree[rt] = tree[rt << 1] + tree[rt << 1 | 1];
}

//询问区间[left, right]中目前的数字个数
int query(int left, int right, int l, int r, int rt)
{
	if(left == l && right == r) return tree[rt];
	
	int mid = (l + r) >> 1;
	if(right <= mid) return query(left, right, lson);
	else if(left > mid) return query(left, right, rson);
	
	return query(left, mid, lson) + query(mid + 1, right, rson);
}

int main()
{
	int n, i, ans, sum;
	while(scanf("%d", &n) == 1){
		build(0, n - 1, 1);
		sum = 0; //求原始数列的逆序数
		
		for(i = 0; i < n; ++i){
			scanf("%d", arr + i);
			//查询当前比arr[i]大的数有多少个
			sum += query(arr[i], n - 1, 0, n - 1, 1);
			update(arr[i], 0, n - 1, 1);
		}
		
		ans = sum;
		for(i = 0; i < n; ++i){
			sum = sum - 2 * arr[i] + n - 1;
			if(sum < ans) ans = sum;
		}
		
		printf("%d\n", ans);
	}
	return 0;
}