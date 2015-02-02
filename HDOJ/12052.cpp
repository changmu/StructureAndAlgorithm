////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-03-11 20:47:21
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1205
////Problem Title: 
////Run result: Accept
////Run time:390MS
////Run memory:228KB
//////////////////System Comment End//////////////////
//2014-3-11 20:31:42
#include <stdio.h>

int main(){
	int t, n, max, a;
	__int64 s;
	scanf("%d", &t);
	while(t-- && scanf("%d", &n)){
		s = max = 0;
		for(int i = 0; i != n; ++i){
			scanf("%d", &a);
			if(a > max) max = a;
			s += a;
		}
		if(s - max >= max - 1) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}