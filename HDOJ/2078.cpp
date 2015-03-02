////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2015-01-17 00:25:11
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2078
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1044KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>

int arr[102];

int main() {
	// freopen("stdin.txt", "r", stdin);
	int T, n, m, i, j, p, ans;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		for (i = 0; i < n; ++i)
			scanf("%d", &arr[i]);
		std::sort(arr, arr + n);
		ans = (100 - arr[0]) * (100 - arr[0]);
		printf("%d\n", ans);
	}
	return 0;
}
