////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-01-30 16:14:03
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1092
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int main(){
	int a, n, s;
	while(scanf("%d", &n), n){
		s = 0;
		while(n-- && scanf("%d", &a))
			s += a;
		printf("%d\n", s);
	}
	return 0;
}