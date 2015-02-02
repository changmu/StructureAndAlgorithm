////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-02-13 13:53:15
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2520
////Problem Title: 
////Run result: Accept
////Run time:109MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int main(){
	int t, n, s, i, v;
	scanf("%d", &t);
	while(t-- && scanf("%d", &n)){
		s = 0; v = 1; i = 1;
		while(i <= n){
			s += v;
			++i;
			v += 2;
			if(s >= 10000)
				s %= 10000;
		}
		printf("%d\n", s);
	}	
	return 0;
}