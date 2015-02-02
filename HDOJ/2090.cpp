////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2015-01-16 11:00:44
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2090
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1096KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int main() {
	// freopen("stdin.txt", "r", stdin);
	double sum = 0.0, price, amount;
	while (scanf("%*s%lf%lf", &amount, &price) == 2) {
		sum += amount * price;
	} 
	printf("%.1lf\n", sum);
	return 0;
}
