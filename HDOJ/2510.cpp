////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-06-14 23:06:08
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2510
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:220KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int ans[] = {0, 0, 0, 4, 6, 0, 0, 12, 40, 0, 0, 171, 410, 0, 0, 
			1896, 5160, 0, 0, 32757, 59984, 0, 0, 431095, 822229};

int main(){
	int n;
	while(scanf("%d", &n), n)
		printf("%d %d\n", n, ans[n]);
	return 0;
}