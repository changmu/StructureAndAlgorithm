////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-03-11 09:33:13
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1021
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
//2014-3-11 09:29:47
#include <stdio.h>

int main(){
	int n;
	while(scanf("%d", &n) == 1)
		printf(n % 4 == 2 ? "yes\n" : "no\n");
	return 0;
}