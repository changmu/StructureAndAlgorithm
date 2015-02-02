////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-06-01 10:36:18
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1283
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include <stdio.h>
char com[202];
int m1, m2, r1, r2, r3;

void perform(char ch){
	switch(ch){
		case 'A': r1 = m1; return;
		case 'B': r2 = m2; return;
		case 'C': m1 = r3; return;
		case 'D': m2 = r3; return;
		case 'E': r3 = r1 + r2; return;
		case 'F': r3 = r1 - r2;
	}
}

int main(){
	while(scanf("%d%d", &m1, &m2) != EOF){
		r1 = r2 = r3 = 0;
		scanf("%s", com);
		for(int i = 0; com[i]; ++i) perform(com[i]);
		printf("%d,%d\n", m1, m2);
	}
	return 0;
}