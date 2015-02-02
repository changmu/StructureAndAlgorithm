////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-03-11 20:39:48
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1205
////Problem Title: 
////Run result: Accept
////Run time:390MS
////Run memory:4148KB
//////////////////System Comment End//////////////////
//2014-3-11 20:31:42
#include <stdio.h>
#include <stdlib.h>

int main(){
	int t, n, *a, max;
	__int64 s;
	scanf("%d", &t);
	while(t-- && scanf("%d", &n)){
		a = (int *)malloc(sizeof(int) * n);
		s = max = 0;
		for(int i = 0; i != n; ++i){
			scanf("%d", &a[i]);
			if(a[i] > max) max = a[i];
			s += a[i];
		}
		if(s - max >= max - 1) printf("Yes\n");
		else printf("No\n");		
		free(a);
	}
	return 0;
}