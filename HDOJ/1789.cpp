////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-10-27 15:12:02
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1789
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:244KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <algorithm>

#define maxn 1010

struct Node {
	int days, penalty;
} arr[maxn];
bool vis[maxn];

bool cmp(Node a, Node b) {
	return a.penalty > b.penalty;
}

int main() {
	// freopen("stdin.txt", "r", stdin);
	int t, n, i, j, sum, sum2;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		sum = sum2 = 0;
		for(i = 0; i < n; ++i) 
			scanf("%d", &arr[i].days);
		for(i = 0; i < n; ++i) {
			scanf("%d", &arr[i].penalty);
			sum += arr[i].penalty;
		}
		std::sort(arr, arr + n, cmp);
		memset(vis, 0, sizeof(vis));
		for(j = 0; j < n; ++j)
			for(i = arr[j].days; i; --i)
				if(!vis[i]) {
					vis[i] = true;
					sum2 += arr[j].penalty;
					break;
				}
		printf("%d\n", sum - sum2);
	}
	return 0;
}