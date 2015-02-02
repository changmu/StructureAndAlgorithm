////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-01-29 15:15:47
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2057
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int main(){
	__int64 a, b;
	while(scanf("%I64X %I64X", &a, &b) == 2){
		a += b;
		if(a < 0) a = -a, b = 1;
		else b = 0;
		if(b) putchar('-');
		printf("%I64X\n", a);
	}
	return 0;
}