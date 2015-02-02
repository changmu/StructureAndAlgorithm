////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2015-01-16 11:23:07
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2088
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1052KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int arr[52];

int main() {
	// freopen("stdin.txt", "r", stdin);
	int n, i, ans, cas = 0;
	while (scanf("%d", &n), n) {
		if (cas++) putchar('\n');
		for (arr[0] = 0, i = 1; i <= n; ++i) {
			scanf("%d", &arr[i]);
			arr[0] += arr[i];
		}
		arr[0] /= n;
		for (i = 1, ans = 0; i <= n; ++i) {
			if (arr[i] < arr[0]) ans += arr[0] - arr[i];
		}
		printf("%d\n", ans);
	}
	return 0;
}
