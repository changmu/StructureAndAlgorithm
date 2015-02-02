////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-01-27 20:06:47
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2040
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int f(int n){
	int s = 0;
	for(int i = 1; i <= n / 2; ++i)
		if(n % i == 0) s += i;
	return s;
}

int main(){
	int a, b, n;
	scanf("%d", &n);
	while(n-- && scanf("%d%d", &a, &b)){
		if(f(a) == b && a == f(b)){
			printf("YES\n");
			continue;
		}
		printf("NO\n");
	}
	return 0;
}