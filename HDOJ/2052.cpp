////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-01-28 18:17:29
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2052
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int main(){
	int n, m;
	while(scanf("%d%d", &n, &m) == 2){
		for(int i = 0; i <= m + 1; ++i){
			for(int j = 0; j <= n + 1; ++j)
				if((i == 0 || i == m + 1) && (j == 0 || j == n + 1)) putchar('+');
				else if(i == 0 || i == m + 1) putchar('-');
				else if(j == 0 || j == n + 1) putchar('|');
				else putchar(' ');
			putchar('\n'); 
		}
		putchar('\n');
	}
	return 0;
}