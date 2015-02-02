////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-01-27 12:51:37
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2032
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#define MAX 31
int a[MAX][MAX];

int main(){
	//´ò±í
	int i, j, n;
	for(i = 1; i <= 30; ++i)
		for(j = 1; j <= i; ++j)
			if(i == 1 || i == j) a[i][j] = 1;
			else a[i][j] = a[i - 1][j - 1] + a[i - 1][j];	
	while(scanf("%d", &n) == 1){
		for(i = 1; i <= n; ++i){
			for(j = 1; j <= i; ++j){
				printf("%d", a[i][j]);
				if(i != j)
					putchar(' ');
			}
			putchar('\n');
		}
		putchar('\n');
	}
	return 0;
}