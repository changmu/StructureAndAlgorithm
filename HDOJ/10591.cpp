////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-11-26 16:16:37
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1059
////Problem Title: 
////Run result: Accept
////Run time:187MS
////Run memory:324KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>

#define maxn 120010
#define maxm 20010

int arr[7];
bool dp[maxn];

void zeroOnePack(int v, int TV) {
	for(int i = TV; i >= v; --i)
		if(dp[i-v]) dp[i] = true;
}

int main() {
	// freopen("stdin.txt", "r", stdin);
	int i, j, cnt, k, cas = 1, tot, v;
	while(true) {
		tot = 0;
		for(i = 1; i < 7; ++i) {
			scanf("%d", &arr[i]);
			tot += arr[i] * i;
		}
		if(tot == 0) break;
		printf("Collection #%d:\n", cas++);
		if(tot & 1) {
			printf("Can't be divided.\n\n");
			continue;
		}
		tot >>= 1;
		memset(dp, 0, sizeof(bool) * (tot + 1));
		dp[0] = true;
		for(i = 1, cnt = 0; i < 7; ++i) {
			for(j = 1; j <= arr[i]; j <<= 1) {
				v = j * i;
				zeroOnePack(v, tot);
				arr[i] -= j;
			}
			if(arr[i] > 0) {
				v = arr[i] * i;
				zeroOnePack(v, tot);
			}
		}

		if(dp[tot] == false) printf("Can't be divided.\n\n");
		else printf("Can be divided.\n\n");
	}
	return 0;
}
