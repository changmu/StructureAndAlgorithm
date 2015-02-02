////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-02-13 14:17:01
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3782
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int f(int n){
	if(n & 1)
		return (n * 3 + 1) / 2;
	return n / 2;	
}

int main(){
	int n, count;
	while(scanf("%d", &n), n){		
		count = 0;			
		while(n != 1){
			n = f(n);
			++count;
		}
		printf("%d\n", count);
	}
	return 0;
}