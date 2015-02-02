////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-05-04 22:04:51
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3336
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:1968KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#define maxn 200000 + 5
char str[maxn];
int next[maxn], len, dp[maxn];

void getNext(){
	int i = 0, j = -1;
	next[0] = -1;
	while(i < len){
		if(j == -1 || str[i] == str[j]){
			++i; ++j;
			next[i] = j;			
		}else j = next[j];
	}
}

int main(){
	int t, sum;
	scanf("%d", &t);
	while(t--){
		scanf("%d%s", &len, str);
		getNext();
		for(int i = 1; i <= len; ++i)
			dp[i] = 1;
		sum = 0;
		for(int i = 1; i <= len; ++i){
			dp[i] = dp[next[i]] + 1;
			sum += dp[i] % 10007;
		}
		printf("%d\n", sum % 10007);
	}
	return 0;
}