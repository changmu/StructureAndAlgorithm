////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-03-11 09:13:01
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1019
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
//2014-3-11 09:03:09
#include <stdio.h>

int gcd(int a, int b){
	int t;
	while(b){
		t = a % b;
		a = b;
		b = t;
	}
	return a;
}

int main(){
	int t, n, a, s;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		s = 1;
		while(n--){
			scanf("%d", &a);
			s = s / gcd(s, a) * a;
		}
		printf("%d\n", s);
	}
	return 0;
}