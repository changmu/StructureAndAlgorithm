////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-10-27 16:40:22
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1051
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:272KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <algorithm>

#define maxn 5010

struct Node {
	int x, y;
} arr[maxn];
bool vis[maxn];

bool cmp(Node a, Node b) {
	return a.x < b.x;
}

int main() {
	int t, n, i, j, k, ans;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		for(i = 0; i < n; ++i)
			scanf("%d%d", &arr[i].x, &arr[i].y);
		std::sort(arr, arr + n, cmp);
		memset(vis, 0, sizeof(bool) * n);
		ans = 0;
		for(i = 0; i < n; ++i) {
			if(vis[i]) continue;
			++ans; k = i; vis[i] = 1;
			for(j = i + 1; j < n; ++j) {
				if(vis[j]) continue;
				if(arr[j].x >= arr[k].x && arr[j].y >= arr[k].y)
					vis[k = j] = 1;
			} 
		}
		printf("%d\n", ans);
	}
}