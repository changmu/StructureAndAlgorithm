////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-01-30 15:44:56
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2075
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int main(){
	int a, b, t;
	scanf("%d", &t);
	while(t-- && scanf("%d%d", &a, &b))
		if(a % b) printf("NO\n");
		else printf("YES\n");	
	return 0;
}