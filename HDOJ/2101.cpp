////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-01-30 16:03:25
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2101
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int main(){
	int a, b;
	while(scanf("%d%d", &a, &b) == 2)
		if((a + b) % 86) printf("no\n");
		else printf("yes\n");
	return 0;
}