////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-10-19 12:58:57
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1066
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:240KB
//////////////////System Comment End//////////////////
#include <string.h>
#include <stdio.h>
#define MAXN 10000
int a[MAXN];
char str[MAXN];
const int mod[20]={1,1,2,6,4,2,2,4,2,8,4,
					4,8,4,6,8,8,6,8,2};
int lastdigit(char *buf){
	int len = strlen(buf), i, c, ret = 1;
	if(len == 1) return mod[buf[0] - '0'];
	for(i = 0; i < len; ++i) a[i] = buf[len-1-i] - '0';
	for(; len; len -= !a[len-1]){
		ret = ret * mod[a[1]%2*10+a[0]] % 5;
		for(c = 0,i = len - 1;i >= 0; --i)
			c = c * 10 + a[i], a[i] = c / 5, c %= 5;
	}
	return ret + ret % 2 * 5;
}
int main(){
	while(scanf("%s", str) == 1){
		printf("%d\n", lastdigit(str));
	}
	return 0;
}