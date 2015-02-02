////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-05-31 11:24:37
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1076
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:200KB
//////////////////System Comment End//////////////////
#include <stdio.h>

bool leap(int y){
	if(y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
		return true;
	return false;
}

int cal(int y, int n){
	while(!leap(y)) ++y;
	--n;
	while(n){
		y += 4;
		if(leap(y)) --n;
	}
	return y;
}

int main(){
	int t, y, n;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &y, &n);
		printf("%d\n", cal(y, n));
	}
	return 0;
}