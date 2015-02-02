////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-07-30 21:33:34
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1395
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int main()
{
	int n, i, a, m;
	while(scanf("%d", &n) != EOF){

		if(n % 2 == 0 || n < 2) printf("2^? mod %d = 1\n", n);
		else{
			m = 1;
			for(a = 2; a % n != 1; a <<= 1) a %= n, ++m;
			printf("2^%d mod %d = 1\n", m, n);
		}
	}
	return 0;
}