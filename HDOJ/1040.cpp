////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-02-14 17:42:05
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1040
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:236KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b){
	return *(int *)a - *(int *)b;
}

int main(){
	int n, *a, i, t;
	scanf("%d", &t);
	while(t-- && scanf("%d", &n)){
		i = n;
		a = (int *)malloc(sizeof(int) *n);
		while(i--)
			scanf("%d", &a[i]);
		qsort(a, n, sizeof(int), cmp);
		for(i = 0; i != n - 1; ++i)
			printf("%d ", a[i]);
		printf("%d\n", a[i]);
		free(a);
	}
	return 0;
}