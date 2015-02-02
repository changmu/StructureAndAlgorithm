////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-05-09 15:16:14
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4540
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:260KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
bool arr[21][502];
int dp[21][502];

int main(){
	int n, k, t, minlen;
	while(scanf("%d%d", &n, &k) == 2){
		memset(arr, 0, sizeof(arr));
		memset(dp, 0, sizeof(dp));
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= k; ++j){
				scanf("%d", &t);
				arr[i][t] = 1;
			}
			
		for(int i = 2; i <= n; ++i){
			for(int j = 1; j <= 501; ++j){
				if(i == 2 && arr[i][j]){
					for(int k = 0; k < 501; ++k){
						if(arr[i-1][k]){
							if(dp[i][j] == 0) dp[i][j] = dp[i-1][k] + abs(k - j);
							else if(dp[i-1][k] + abs(k - j) < dp[i][j]) 
								dp[i][j] = dp[i-1][k] + abs(k - j);
						}
					}
					continue;
				}
				if(arr[i][j]){
					for(int k = 0; k < 501; ++k){
						if(dp[i-1][k]){
							if(dp[i][j] == 0) dp[i][j] = dp[i-1][k] + abs(k - j);
							else if(dp[i-1][k] + abs(k - j) < dp[i][j]) 
								dp[i][j] = dp[i-1][k] + abs(k - j);
						}
					}
				}
			}
		}
		minlen = 0;
		for(int i = 1; i < 501; ++i)
			if(dp[n][i]){
				if(!minlen) minlen = dp[n][i];
				else if(dp[n][i] < minlen) minlen = dp[n][i];
			}
		printf("%d\n", minlen);
	}
	return 0;
}