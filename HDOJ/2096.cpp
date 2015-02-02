////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-01-30 16:08:05
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2096
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int main(){
	int t, a, b;
	scanf("%d", &t);
	while(t-- && scanf("%d%d", &a, &b)){
		a %= 100; b %= 100;
		printf("%d\n", (a + b) % 100);
	}
	return 0;
}