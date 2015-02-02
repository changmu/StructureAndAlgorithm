////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-11-23 13:06:39
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1902
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:380KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <algorithm>

#define maxn 20010

int A[maxn], B[maxn], N, M;
__int64 ans;

int main() {
	int i, j;
	while(scanf("%d%d", &N, &M), N | M) {
		for(i = 0; i < N; ++i)
			scanf("%d", &A[i]);
		for(i = 0; i < M; ++i)
			scanf("%d", &B[i]);
		if(M < N) {
			printf("Loowater is doomed!\n");
			continue;
		}
		std::sort(A, A + N);
		std::sort(B, B + M);
		ans = 0;
		for(i = j = 0; i < N && j < M; ++i) {
			for( ; j < M; ++j)
				if(B[j] >= A[i]) {
					ans += B[j++];
					break;
				}
		}
		if(i != N) printf("Loowater is doomed!\n");
		else printf("%I64d\n", ans);
	}
	return 0;
}