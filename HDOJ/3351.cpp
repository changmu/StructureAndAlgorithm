////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-10-18 19:51:21
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3351
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:200KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>

#define maxn 2010

char str[maxn];

int main() {
	int i, left, right, op, cas = 1;
	while(scanf("%s", str), str[0] != '-') {
		left = right = op = 0;
		for(i = 0; str[i]; ++i) {
			if(str[i] == '{') ++left;
			else if(0 == left) {
				++left; ++op;
			} else --left;
		}
		op += left / 2;
		printf("%d. %d\n", cas++, op);
	}
	return 0;
}