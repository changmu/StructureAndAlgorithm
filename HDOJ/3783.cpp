////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-02-13 14:38:31
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3783
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#define MAX 101
char BUF[MAX];

int main(){
	int z, o, j, len, lens;
	while(scanf("%s", BUF), BUF[0] != 'E'){
		z = o = j = 0;
		lens = len = strlen(BUF);
		while(len--){
			switch(BUF[len]){
				case 'Z': ++z; break;
				case 'O': ++o; break;
				case 'J': ++j; break;
			}
		}
		while(lens--){
			if(z) putchar('Z'), --z;
			if(o) putchar('O'), --o;
			if(j) putchar('J'), --j;
		}
		puts("");
	}
	return 0;
}