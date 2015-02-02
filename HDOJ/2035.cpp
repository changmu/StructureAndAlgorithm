////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-01-27 15:20:22
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2035
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int main(){
	int a, b, s;
	while(scanf("%d%d", &a, &b), a || b){
		s = a = a % 1000;
		while(--b){
			s *= a;
			s %= 1000;
		}
		printf("%d\n", s);
	}
	return 0;
}