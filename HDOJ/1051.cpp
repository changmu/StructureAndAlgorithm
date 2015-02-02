////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-05 09:27:33
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1051
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:252KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define maxn 5002
using std::sort;

struct Node{
	int l, w;
} arr[maxn];
bool vis[maxn];

bool cmp(Node a, Node b){
	if(a.l == b.l) return a.w < b.w;
	return a.l < b.l;
}

int main()
{
//	freopen("stdin.txt", "r", stdin);
	int t, n, i, j, ans;
	Node tmp;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(i = 0; i < n; ++i)
			scanf("%d%d", &arr[i].l, &arr[i].w);
		sort(arr, arr + n, cmp);
		memset(vis, 0, sizeof(vis));
		for(i = 0, ans = n; i < n; ++i){
			if(vis[i]) continue;
			vis[i] = 1; tmp = arr[i];
			for(j = i + 1; j < n; ++j){
				if(vis[j]) continue;
				if(tmp.l <= arr[j].l && tmp.w <= arr[j].w){
					vis[j] = 1;
					--ans; tmp = arr[j];
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}