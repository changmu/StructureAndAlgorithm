////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-03-11 08:00:21
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1014
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int main(){
	int step, mod, t;
	while(scanf("%d%d", &step, &mod) == 2){
		printf("%10d%10d", step, mod);
		while(mod){
			t = step % mod;
			step = mod;
			mod = t;
		}
		printf("    %s\n\n", step == 1? "Good Choice": "Bad Choice");
	}
	return 0;
}