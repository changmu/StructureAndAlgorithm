//#define QQQ
#include <stdio.h>
#include <string.h>
#define maxn 500002
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1

int tree[maxn << 2], div[maxn], temp;
struct Node{
	char name[12];
	int mov;
} stu[maxn], ans;

void countDiv()
{
	int i, j, t = maxn / 2;
	for(i = 1; i <= t; ++i)
		for(j = i; j <= maxn; j += i)
			++div[j];
}

void build(int l, int r, int rt)
{
	tree[rt] = r - l + 1;
	if(l == r) return;
	
	int mid = (l + r) >> 1;
	build(lson);
	build(rson);
}

void update(int pos, int rank, int l, int r, int rt)
{
	--tree[rt];
	if(l == r){
		if(div[rank] > ans.mov){
			ans.mov = div[rank];
			strcpy(ans.name, stu[r].name);
		}
		temp = stu[r].mov;
		return;
	}
	
	int mid = (l + r) >> 1;
	if(tree[rt << 1] >= pos) update(pos, rank, lson);
	else update(pos - tree[rt << 1], rank, rson);
}

int getK(int k, int n)
{
	if(temp > 0) return (k + temp - 2) % n + 1;
	return ((k + temp - 1) % n + n) % n + 1;
}

int main()
{
	#ifdef QQQ
	freopen("..\\stdin.txt", "r", stdin);
	freopen("..\\stdout.txt", "w", stdout);
	#endif
	
	countDiv();
	int n, k, i, rank, num;
	
	while(scanf("%d%d", &n, &k) == 2){
		build(1, n, 1);
		
		for(i = 1; i <= n; ++i)
			scanf("%s%d", stu[i].name, &stu[i].mov);
			
		rank = 1; ans.mov = 0; num = n;
		
		update(k, rank++, 1, n, 1);
		while(rank <= n){
			k = getK(k, --num);
			update(k, rank++, 1, n, 1);			
		}
		
		printf("%s %d\n", ans.name, ans.mov);
	}
	return 0;
}