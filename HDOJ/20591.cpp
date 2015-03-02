////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2015-01-27 14:35:39
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2059
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1092KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>

#define maxn 102

double dp[maxn]; // arrive time
double L, C, T, VR, VT1, VT2;
double pos[maxn];
int N;

double min(double a, double b) { return a < b ? a : b; }

int main() {
	// freopen("stdin.txt", "r", stdin);
	int i, j;
	double tmp;
	while (scanf("%lf", &L) == 1) {
		scanf("%d%lf%lf", &N, &C, &T);
		scanf("%lf%lf%lf", &VR, &VT1, &VT2);
		for (i = 0; i < N; ++i)
			scanf("%lf", &pos[i]);
		pos[N] = L;
		for (i = 0; i <= N; ++i) { // use none pos 
			if (pos[i] <= C) dp[i] = pos[i] / VT1;
			else dp[i] = C / VT1 + (pos[i] - C) / VT2;
		}
		for (i = 0; i < N; ++i) { // let it be the last pos
			for (j = i + 1; j <= N; ++j) {
				if (pos[j] - pos[i] <= C) tmp = (pos[j] - pos[i]) / VT1;
				else tmp = C / VT1 + (pos[j] - pos[i] - C) / VT2;
				dp[j] = min(dp[j], dp[i] + T + tmp);
			}
		}
		if (dp[N] < L / VR) printf("What a pity rabbit!\n");
		else puts("Good job,rabbit!");
	}
	return 0;
}
