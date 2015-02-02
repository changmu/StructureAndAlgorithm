////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2015-01-16 10:54:50
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2092
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1068KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <math.h>

int main() {
	// freopen("stdin.txt", "r", stdin);
	int a, b, delta, x;
	while (scanf("%d%d", &a, &b), a | b) {
		x = a * a - 4 * b;
		if (x < 0) {
			printf("No\n");
			continue;
		}
		delta = (int)sqrt(x);
		if (delta * delta == x && !(a + delta & 1)) {
			printf("Yes\n"); continue;
		} else printf("No\n");
	}
	return 0;
}
