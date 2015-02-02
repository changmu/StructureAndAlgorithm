////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-05-31 17:05:41
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1847
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:200KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int main(){
	int n;	
	while(scanf("%d", &n) == 1)
		printf(n % 3 ? "Kiki\n" : "Cici\n");	
	return 0;
}