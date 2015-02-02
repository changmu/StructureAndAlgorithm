////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-05-09 14:01:55
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1176
////Problem Title: 
////Run result: Accept
////Run time:93MS
////Run memory:9608KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
int dp[100002][12];
int arr[100002][12];

int max3(int a, int b, int c){
	if(b < a) b = a;
	return c > b ? c : b;
}

int max2(int a, int b){
	return a > b ? a : b;
}

int main(){
	int n, m, t, id, maxt, maxm;
	while(scanf("%d", &n), n){
		memset(dp, 0, sizeof(dp));
		memset(arr, 0, sizeof(arr));
		maxt = 1;
		for(int i = 0; i < n; ++i){
			scanf("%d%d", &m, &t);
			++arr[t][m];
			if(t > maxt) maxt = t;
		}
		id = 5;
		for(int i = 1; i <= maxt; ++i){
			for(int j = (id - i > 0 ? id-i : 0); j <= (id + i < 10 ? id+i : 10); ++j){
				if(j == 0) dp[i][0] = max2(dp[i-1][0], dp[i-1][1]) + arr[i][0];
				else dp[i][j] = max3(dp[i-1][j], dp[i-1][j-1], dp[i-1][j+1]) + arr[i][j];
			}
		}
		maxm = 0;
		for(int i = 0; i < 11; ++i)
			if(dp[maxt][i] > maxm) maxm = dp[maxt][i];
		printf("%d\n", maxm);
	}
	return 0;
}