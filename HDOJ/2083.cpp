////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2015-01-16 23:09:01
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2083
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:1052KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <algorithm>

int arr[502];

int abs(int x) { return x < 0 ? -x : x; }

int main() {
	// freopen("stdin.txt", "r", stdin);
	int T, n, i, ans, p;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (i = 0; i < n; ++i)
			scanf("%d", &arr[i]);
		std::sort(arr, arr + n);
		ans = 0; p = arr[n>>1];
		for (i = 0; i < n; ++i)
			ans += abs(arr[i] - p);
		printf("%d\n", ans);
	}
	return 0;
}
