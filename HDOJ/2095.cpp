////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-02-11 11:28:32
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2095
////Problem Title: 
////Run result: Accept
////Run time:562MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int main(){
	int t, a, b;
	while(scanf("%d", &t), t){
		a = 0;
		while(t-- && scanf("%d", &b))
			a ^= b;
		printf("%d\n", a);
	}
	return 0;
}