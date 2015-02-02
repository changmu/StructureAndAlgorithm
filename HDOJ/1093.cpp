////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-02-08 00:44:32
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1093
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int main(){
	int t, a, b, s;
	scanf("%d", &t);
	while(t-- && scanf("%d", &a)){
		s = 0;
		while(a-- && scanf("%d", &b))
			s += b;
		printf("%d\n", s);
	}
	return 0;
}