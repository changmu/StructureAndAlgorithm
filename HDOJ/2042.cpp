////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-01-27 20:47:49
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2042
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int main(){
	int n, a, s;
	scanf("%d", &n);
	while(n-- && scanf("%d", &a)){
		s = 3;
		while(a--)
			s = (s - 1) * 2;
		printf("%d\n", s);
	}
	return 0;
}