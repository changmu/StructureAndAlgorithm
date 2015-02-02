////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-03-11 18:54:09
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1061
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
//ÕÒ¹æÂÉ2014-3-11 18:40:19
#include <stdio.h>
#include <string.h>
char *sam[] = {"0", "1", "2486", "3971", "46", "5", "6", "7931", "8426", "91"};

int main(){
	int t, n, time;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		time = n;
		n %= 10;
		printf("%d\n", sam[n][(time - 1) % strlen(sam[n])] - '0');
	}
	return 0;
}