////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2015-01-16 11:35:07
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2087
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1072KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>

#define maxn 1010

char buf[maxn], str[maxn], *p;

int main() {
	// freopen("stdin.txt", "r", stdin);
	int ans, i, len1, len2, tmp;
	while (scanf("%s%s", buf, str) == 2) {
		len1 = strlen(buf);
		len2 = strlen(str);
		ans = 0;
		for (i = 0; i < len1; i = p - buf + len2) {
			if (p = strstr(buf + i, str)) ++ans;
			else break;
		}
		printf("%d\n", ans);
	}
	return 0;
}
