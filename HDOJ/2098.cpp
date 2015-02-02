////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-07-24 15:14:06
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2098
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:236KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <math.h>
#define maxn 10002

int prime[maxn] = {1, 1};

int main()
{
	int i, n, j, ans;
	n = sqrt(maxn);
	for(i = 2; i <= n; ++i){
		if(prime[i]) continue;
		for(j = i * i; j <= maxn; j += i)
			prime[j] = 1;
	}
	while(scanf("%d", &n), n){
		j = n >> 1; ans = 0;
		if((n & 1) == 0) --j;
		for(i = 2; i <= j; ++i)
			if(!prime[i] && !prime[n - i]) ++ans;
		printf("%d\n", ans);
	}
	return 0;
}