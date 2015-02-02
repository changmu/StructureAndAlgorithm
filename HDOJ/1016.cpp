////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-04-15 10:32:04
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1016
////Problem Title: 
////Run result: Accept
////Run time:312MS
////Run memory:208KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <math.h>

int n, store[21];
bool hasSelect[21];

bool checkPrime(int k){
	int t = sqrt(k);
	for(int i = 2; i <= t; ++i)
		if(k % i == 0) return 0;
	return 1;
}

void backTrack(int k){
	if(k == n + 1){
		if(checkPrime(store[1] + store[n])){
			printf("%d", store[1]);
			for(int i = 2; i <= n; ++i) printf(" %d", store[i]);
			printf("\n");
		}
		return;
	}
	for(int i = 2; i <= n; ++i){
		if(!hasSelect[i] && checkPrime(i + store[k - 1])){
			hasSelect[i] = 1;
			store[k] = i;
			backTrack(k + 1);
			hasSelect[i] = 0;
		}
	}
}

int main(){
	int i = 1;
	while(scanf("%d", &n) == 1){
		printf("Case %d:\n", i++);
		store[1] = 1;
		backTrack(2);
		printf("\n");
	}
	return 0;
}