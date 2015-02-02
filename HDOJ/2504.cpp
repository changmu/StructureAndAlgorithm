////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-07-23 20:43:14
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2504
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:200KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int gcd(int a, int b){
	return b ? gcd(b, a % b) : a;
}

int main()
{
	int n, a, b, c;
	scanf("%d", &n);
	while(n--){
		scanf("%d%d", &a, &b);
		for(c = b << 1; ; c += b){
			if(gcd(a, c) == b) break;
		}
		printf("%d\n", c);
	}
	return 0;
}
