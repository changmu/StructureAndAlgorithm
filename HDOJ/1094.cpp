////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-02-08 00:46:38
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1094
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int main(){
	int a, b, s;
	while(scanf("%d", &a) == 1){
		s = 0;
		while(a-- && scanf("%d", &b))
			s += b;
		printf("%d\n", s);
	}
	return 0;
}