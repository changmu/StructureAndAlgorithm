////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-01-30 10:21:06
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2060
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int main(){
	int t, ball, ph, op, i;
	scanf("%d", &t);
	while(t-- && scanf("%d%d%d", &ball, &ph, &op)){		
		while(ball > 6){
			ph += 8;
			--ball;
		}
		i = 7;
		while(ball && ball <= 6){
			ph += i--;
			--ball;
		}
		if(ph >= op) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}