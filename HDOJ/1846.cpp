////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-10-27 16:12:13
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1846
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>

int main() {
	int n, m, t;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &n, &m);
		printf(n % ++m == 0 ? "second\n" : "first\n");
	}
	return 0;
}