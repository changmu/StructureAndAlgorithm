////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2015-01-26 22:28:37
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1210
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1056KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>

int main() {
	int n, cnt, pos;
	while (~scanf("%d", &n)) {
		pos = 1; cnt = 0;
		do {
			if (pos <= n) pos <<= 1;
			else pos -= 2 * n - pos + 1;
			++cnt;
		} while (pos != 1);
		printf("%d\n", cnt);
	}
	return 0;
}
