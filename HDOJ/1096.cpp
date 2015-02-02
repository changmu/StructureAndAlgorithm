////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-01-30 16:18:14
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1096
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int main(){
	int t, n, a, s;
	scanf("%d", &t);
	while(t-- && scanf("%d", &n)){
		s = 0;
		while(n-- && scanf("%d", &a))
			s += a;
		printf("%d\n", s);
		if(t) printf("\n");
	}
	return 0;
}