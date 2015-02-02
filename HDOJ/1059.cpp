////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-11-26 14:33:37
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1059
////Problem Title: 
////Run result: Accept
////Run time:765MS
////Run memory:440KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>

#define maxn 120010
#define maxm 20010

int arr[7], V[maxn], W[maxm];
int TV[maxn];

int max(int a, int b) { return a > b ? a : b; }

int main() {
	// freopen("stdin.txt", "r", stdin);
	int i, j, cnt, k, cas = 1, tot;
	while(true) {
		tot = arr[0] = 0;
		for(i = 1; i < 7; ++i) {
			scanf("%d", &arr[i]);
			arr[0] += arr[i];
			tot += arr[i] * i;
		}
		if(arr[0] == 0) break;
		printf("Collection #%d:\n", cas++);
		if(tot & 1) {
			printf("Can't be divided.\n\n");
			continue;
		}
		for(i = 1, cnt = 0; i < 7; ++i) {
			for(j = 1; j <= arr[i]; j <<= 1) {
				V[cnt++] = j * i;
				arr[i] -= j;
			}
			if(arr[i] > 0) {
				V[cnt++] = arr[i] * i;
			}
		}
		tot >>= 1;
		memset(TV, 0, sizeof(int) * (tot + 1));
		for(i = 0; i < cnt; ++i) {
			for(j = tot; j >= V[i]; --j)
				TV[j] = max(TV[j], TV[j-V[i]] + V[i]);
		}

		if(TV[tot] != tot) printf("Can't be divided.\n\n");
		else printf("Can be divided.\n\n");
	}
	return 0;
}
