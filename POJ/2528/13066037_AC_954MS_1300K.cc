//#define DEBUG
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1
#define maxn 10002
using std::sort;

int hash[maxn << 2], vis[maxn << 2], visColor[maxn], ans;
int tree[maxn << 4], ori[maxn << 1], idHash, idVis, idOri;

int findHash(int n)
{
	for(int i = 0; i < idHash; ++i)
		if(hash[i] == n) return i;
}

void pushDown(int rt)
{
	tree[rt << 1] = tree[rt << 1 | 1] = tree[rt];
	tree[rt] = -1;
}

void build(int l, int r, int rt)
{
	tree[rt] = -1;
	if(r == l) return;
	
	int mid = (l + r) >> 1;
	build(lson);
	build(rson);
}

void update(int left, int right, int val, int l, int r, int rt)
{
	if(left == l && right == r){
		tree[rt] = val; return;
	}
	
	if(tree[rt] != -1) pushDown(rt);
	
	int mid = (l + r) >> 1;
	if(right <= mid) update(left, right, val, lson);
	else if(left > mid) update(left, right, val, rson);
	else{
		update(left, mid, val, lson);
		update(mid + 1, right, val, rson);
	}
}

void query(int l, int r, int rt)
{
	if(tree[rt] != -1){
		if(!visColor[tree[rt]]){
			++ans; visColor[tree[rt]] = 1;
		}
		return;
	} //最后延迟段必定覆盖所有ori区间点，因为映射的每个点都被用到
	
	if(l == r) return;
	
	int mid = (l + r) >> 1;
	query(lson);
	query(rson);
}

int main()
{
	#ifdef DEBUG
		freopen("stdin.txt", "r", stdin);
		freopen("stdout.txt", "w", stdout);
	#endif
	
	int cas, n, a, b, i, temp;
	scanf("%d", &cas);
	
	while(cas--){
		scanf("%d", &n);
		for(i = idVis = idOri = 0; i < n; ++i){
			scanf("%d%d", &a, &b);
			ori[idOri++] = a; ori[idOri++] = b;
			vis[idVis++] = a; vis[idVis++] = b;			
		}
		
		sort(vis, vis + idVis); //temporary
		
		for(temp = idVis, i = 1; i < temp; ++i)
			if(vis[i] - vis[i - 1] > 1) vis[idVis++] = vis[i] - 1;
			
		sort(vis, vis + idVis);
		
		hash[0] = vis[0];
		for(i = idHash = 1; i < idVis; ++i)
			if(vis[i] != vis[i - 1]) hash[idHash++] = vis[i];
						
		for(i = 0; i < idOri; ++i)
			ori[i] = findHash(ori[i]);
			
		build(0, idHash - 1, 1); //映射区间
		memset(visColor, 0, sizeof(visColor));
		
		for(i = 0; i < n; ++i){
			update(ori[i << 1], ori[i << 1 | 1], i, 0, idHash - 1, 1);
		}
		
		ans = 0; query(0, idHash - 1, 1);
		printf("%d\n", ans);
	}
	return 0;
}