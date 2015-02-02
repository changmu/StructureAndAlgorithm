////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-07-31 08:55:52
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1999
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:4120KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#define maxn 1002

int arr[maxn], sum[1000002];

int main()
{
	int n, ok, t, i, addSum = 0, mulSum = 1, j;
	for(i = 1; i <= 500000; ++i){
		for(j = i + i; j <= 1000000; j += i)
			sum[j] += i;	
	}
	for(i = 1; i <= 1000000; ++i)
		if(sum[i] <= 1000) arr[sum[i]] = 1;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		if(arr[n]) printf("no\n");
		else printf("yes\n");
	}
	return 0;
}