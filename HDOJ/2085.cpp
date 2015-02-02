////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2015-01-16 22:33:25
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2085
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1056KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>

typedef __int64 LL;
LL fa[35] = {1}, fb[35];

int main() {
	// freopen("stdin.txt", "r", stdin);
	int i, n;
	for (i = 1; i <= 33; ++i) {
		fa[i] = 3 * fa[i-1] + 2 * fb[i-1];
		fb[i] = fa[i-1] + fb[i-1];
	}
	while (scanf("%d", &n), n != -1) {
		printf("%I64d, %I64d\n", fa[n], fb[n]);
	}
	return 0;
}
