////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-05-18 22:11:51
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2035
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:200KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int pow(int n, int t){
	if(t == 0) return 1;
	if(t == 1) return n % 1000;
	if(t & 1) return pow(n * n % 1000, t / 2) * n % 1000;
	else return pow(n * n % 1000, t / 2) % 1000;
}

int main(){
	int a, b;
	while(scanf("%d%d", &a, &b), a || b){
		printf("%d\n", pow(a, b));
	}
	return 0;
}