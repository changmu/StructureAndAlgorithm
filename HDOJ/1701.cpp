////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-06-02 20:27:07
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1701
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int main(){
	int n, m; double a, b;
	scanf("%d", &n);
	while(n--){
		scanf("%lf%lf", &a, &b);
		m = 1;
		while((int)(m * a / 100) >= (int)(m * b / 100)) ++m;
		printf("%d\n", m);
	}
	return 0;
}