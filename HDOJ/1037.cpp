////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-03-30 14:18:07
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1037
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:248KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int main(){
	int i = 3, t, ok = 1;
	while(i--){
		scanf("%d", &t);
		if(t <= 168){ ok = 0; break;}
	}
	if(!ok) printf("CRASH %d\n", t);
	else printf("NO CRASH\n");
	return 0;
}