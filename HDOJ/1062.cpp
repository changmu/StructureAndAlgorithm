////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-04-19 14:31:27
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1062
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:208KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>

char str[1005];

int main(){
	int t, len, i, j, k;
	scanf("%d\n", &t);
	while(t--){
		gets(str);
		len = strlen(str);
		for(i = 0; i < len; ++i){
			if(str[i] == ' ') putchar(' ');
			else{
				j = i + 1;
				while(str[j] != ' ' && str[j] != '\0') ++j;
				k = j;
				while(j > i) putchar(str[--j]);
				i = k - 1;
			}
		}
		putchar('\n');
	}
	return 0;
}