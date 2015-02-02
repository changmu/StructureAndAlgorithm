////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-02 00:03:35
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1196
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:200KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int main()
{
	int n;
	while(scanf("%d", &n), n){
		printf("%d\n", n & (-n));
	}
	return 0;
}