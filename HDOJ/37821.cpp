////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-05-29 17:04:50
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3782
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int main(){
	int n, ans;
	while(scanf("%d", &n), n){
		ans = 0;
		while(n != 1){
			if(n & 1) n = n * 3 + 1;
			n >>= 1;
			++ans;
		}
		printf("%d\n", ans);
	}
	return 0;
}