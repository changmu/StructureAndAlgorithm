////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: 长木
////Run ID: 
////Submit time: 2014-09-22 18:06:08
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5023
////Problem Title: 
////Run result: Accept
////Run time:750MS
////Run memory:21288KB
//////////////////System Comment End//////////////////
/*************************************************************************
  > File Name: hdu5023.cpp
  > Author: Bslin
  > Mail: Baoshenglin1994@gmail.com
  > Created Time: 2014年09月20日 星期六 21时24分19秒
 ************************************************************************/

#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
const int N = 200010;
const int M = 100010;

struct node {
	int l, r;
	int cnt;
	bool flag;
	int num[70];
} tree[N << 2];
int ans[70], tot;
int Hash[N], a[M], b[M], c[M];
char op[M];

void pushup(int p) {
	int i, cnt;
	memset(tree[p].num, 0, sizeof(tree[p].num));
	for(i = 0; i < tree[p << 1].cnt; i ++) {
		tree[p].num[i] = tree[p << 1].num[i];
	}
	int len = tree[p << 1].cnt;
	for(i = 0; i < tree[p << 1 | 1].cnt; i ++) {
		tree[p].num[len + i] = tree[p << 1 | 1].num[i];
	}
	cnt = tree[p << 1].cnt + tree[p << 1 | 1].cnt;
	sort(tree[p].num, tree[p].num + cnt);
	tree[p].cnt = unique(tree[p].num, tree[p].num + cnt) - tree[p].num;
}

void pushdown(int p) {
	if(tree[p].flag) {
		tree[p << 1].flag = tree[p << 1 | 1].flag = 1;
		tree[p].flag = 0;
		memset(tree[p << 1].num, 0, sizeof(tree[p << 1].num));
		memset(tree[p << 1 | 1].num, 0, sizeof(tree[p << 1 | 1].num));
		tree[p << 1].cnt = 1;
		tree[p << 1 | 1].cnt = 1;
		tree[p << 1].num[0] = tree[p].num[0];
		tree[p << 1 | 1].num[0] = tree[p].num[0];
	}
}

void build(int l, int r, int p) {
	tree[p].l = l;
	tree[p].r = r;
	tree[p].flag = 0;
	tree[p].cnt = 1;
	memset(tree[p].num, 0, sizeof(tree[p].num));
	tree[p].num[0] = 2;
	if(l == r) {
		return ;
	}
	int mid = (l + r) >> 1;
	build(l, mid, p << 1);
	build(mid + 1, r, p << 1 | 1);
}

void update(int l, int r, int val, int p) {
	if(tree[p].l == l && tree[p].r == r) {
		memset(tree[p].num, 0, sizeof(tree[p].num));
		tree[p].cnt = 1;
		tree[p].num[0] = val;
		tree[p].flag = 1;
		return ;
	}
	pushdown(p);
	int mid = (tree[p].l + tree[p].r) >> 1;
	if(r <= mid) update(l, r, val, p << 1);
	else if(l > mid) update(l,r,val,p << 1 | 1);
	else {
		update(l, mid, val, p << 1);
		update(mid + 1, r, val, p << 1 | 1);
	}
	pushup(p);
}

void query(int l, int r, int p) {
	if(tree[p].l == l && tree[p].r == r) {
		int i;
		for(i = 0; i < tree[p].cnt; i ++) {
			ans[tot++] = tree[p].num[i];
		}
		sort(ans, ans + tot);
		tot = unique(ans, ans + tot) - ans;
		return ;
	}
	pushdown(p);
	int mid = (tree[p].l + tree[p].r) >> 1;
	if(mid >= r) query(l, r, p << 1);
	else if(l > mid) query(l, r, p << 1 | 1);
	else {
		query(l, mid, p << 1);
		query(mid + 1, r, p << 1 | 1);
	}
}

int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	int n, m, i, j;
	int hh;
	while(scanf("%d%d", &n, &m) != EOF) {
		if(n == 0 && m == 0) break;
		hh = 0;
		getchar();
		for(i = 0; i < m; i ++) {
			scanf("%c", &op[i]);
			if(op[i] == 'P') {
				scanf("%d%d%d", &a[i], &b[i], &c[i]);
				Hash[hh++] = a[i];
				Hash[hh++] = b[i];
			} else {
				scanf("%d%d", &a[i], &b[i]);
				Hash[hh++] = a[i];
				Hash[hh++] = b[i];
			}
			getchar();
		}
		sort(Hash, Hash + hh);
		hh = unique(Hash, Hash + hh) - Hash;
		build(1, hh, 1);
		for(i = 0; i < m; i ++) {
			a[i] = lower_bound(Hash, Hash + hh, a[i] ) - Hash + 1;
			b[i] = lower_bound(Hash, Hash + hh, b[i] ) - Hash + 1;
		}
		for(i = 0; i < m; i++) {
			if(op[i] == 'P') {
				update(a[i], b[i], c[i], 1);
			} else {
				memset(ans, 0, sizeof(ans));
				tot = 0;
				query(a[i], b[i], 1);
				for(j = 0; j < tot; j ++) {
					if(j == 0) printf("%d", ans[0]);
					else printf(" %d", ans[j]);
				}
				printf("\n");
			}
		}
	}
}
