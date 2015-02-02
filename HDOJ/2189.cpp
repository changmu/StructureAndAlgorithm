////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-09 15:36:54
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2189
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <math.h>
#define maxn 160

int c1[maxn], c2[maxn], prime[maxn];

bool isPrime(int n)
{
	int t = sqrt(n);
	for(int i = 2; i <= t; ++i)
		if(n % i == 0) return 0;
	return 1;
}

int main()
{
	int i, id = 0, j, k, t, n;
	for(i = 2; i < 156; ++i)
		if(isPrime(i)) prime[id++] = i;
	for(i = 0; i < maxn; i += 2)
		c1[i] = 1;
	for(i = 1; prime[i] <= 150; ++i){
		for(j = 0; j <= 150; ++j)
			for(k = 0; k + j <= 150; k += prime[i])
				c2[j+k] += c1[j];
		for(j = 0; j <= 150; ++j){
			c1[j] = c2[j]; c2[j] = 0;
		}
	}
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		printf("%d\n", c1[n]);
	}
	return 0;
}