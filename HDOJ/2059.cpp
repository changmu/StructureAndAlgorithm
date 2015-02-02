////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: 长木
////Run ID: 
////Submit time: 2014-10-24 08:37:11
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2059
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:240KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>

#define maxn 105
#define inf 0x3f3f3f3f

struct Node {
	double goTime, toEnd;
} dp[maxn]; // dp[i]表示以第i个加油站作为最终加油站的用时
int arr[maxn], L, n, c, t, vr, vt1, vt2;

double min(double a, double b) {
	return a < b ? a : b;
}

double calTime(int dist) {
	if(dist <= c) return (double)dist / vt1;
	return (double)(dist-c) / vt2 + (double)c / vt1;
}

int main() {
	// freopen("stdin.txt", "r", stdin);
	double ans;
	while(~scanf("%d", &L)) {
		scanf("%d%d%d", &n, &c, &t);
		scanf("%d%d%d", &vr, &vt1, &vt2);
		for(int i = 1; i <= n; ++i)
			scanf("%d", &arr[i]);
		arr[0] = 0; arr[n+1] = L;
		dp[0].goTime = 0.0;
		ans = dp[0].toEnd = dp[0].goTime + calTime(arr[n+1] - arr[0]);
		for(int i = 1; i <= n; ++i) {
			dp[i].goTime = inf;
			for(int j = 0; j < i; ++j) {
				dp[i].goTime = min(dp[i].goTime, dp[j].goTime
				 	+ calTime(arr[i] - arr[j]));
			}
			dp[i].toEnd = (dp[i].goTime += t) + calTime(arr[n+1] - arr[i]);
			ans = min(ans, dp[i].toEnd);
		}
		if(ans < (double)L / vr) printf("What a pity rabbit!\n");
		else printf("Good job,rabbit!\n");
	}
	return 0;
}