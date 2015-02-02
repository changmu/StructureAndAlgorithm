////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: 长木
////Run ID: 
////Submit time: 2014-03-11 19:18:05
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2035
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
//二分法2014-3-11 19:10:15
#include <stdio.h>

int f(int a, int b){
	if(b == 1) return a;	
	int s = f(a, b / 2);
	if(b & 1) return s * s * a % 1000;
	else return s * s % 1000;
}

int main(){
	int a, b;
	while(scanf("%d%d", &a, &b), a || b){
		a %= 1000;
		printf("%d\n", f(a, b));
	}
	return 0;
}