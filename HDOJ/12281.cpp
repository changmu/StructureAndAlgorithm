////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-10-27 23:23:11
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1228
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>

#define maxn 100

const char *sam[] = {"zero", "one", "two", "three", "four",
					"five", "six", "seven", "eight", "nine"};
char buf[maxn];

int calVal(char str[]) {
	for(int i = 0; i < 10; ++i)
		if(!strcmp(buf, sam[i]))
			return i;
}

int main() {
	int mode = 0, a[2];
	a[0] = a[1] = 0;
	while(scanf("%s", buf) == 1) {
		if(!strcmp(buf, "+")) {
			++mode; continue;
		} else if(!strcmp(buf, "=")) {
			if(a[0] + a[1] == 0) break;
			printf("%d\n", a[0] + a[1]);
			mode = a[0] = a[1] = 0;
			continue;
		}
		a[mode] = a[mode] * 10 + calVal(buf);
	}
	return 0;
}