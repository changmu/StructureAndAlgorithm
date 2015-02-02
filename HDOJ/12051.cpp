////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-03-11 20:44:45
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1205
////Problem Title: 
////Run result: Accept
////Run time:406MS
////Run memory:4144KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#define MAX 1000000 + 2
int a[MAX];

int main(){
	int t, n, max;
	__int64 s;
	scanf("%d", &t);
	while(t-- && scanf("%d", &n)){
		s = max = 0;
		for(int i = 0; i != n; ++i){
			scanf("%d", &a[i]);
			if(a[i] > max) max = a[i];
			s += a[i];
		}
		if(s - max >= max - 1) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}