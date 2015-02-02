////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-11-02 21:35:43
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5018
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>

int main() {
	int a, b, c, d, i, t;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d%d", &a, &b, &c);
		if(a == c || b == c) {
			printf("Yes\n");
			continue;
		}
		while(b < c) {
			d = a + b;
			a = b; b = d;
		}
		if(b == c) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
