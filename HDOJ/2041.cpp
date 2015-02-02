////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-01-27 20:33:42
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2041
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int main(){
	int a[42] = {0, 0, 1, 2};
	int n, i;
	for(i = 4; i != 41; ++i)
		a[i] = a[i - 1] + a[i - 2];
	scanf("%d", &n);
	while(n-- && scanf("%d", &i))
		printf("%d\n", a[i]);
	return 0;
}