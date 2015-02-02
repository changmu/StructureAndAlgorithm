////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-02-14 16:54:48
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1029
////Problem Title: 
////Run result: Accept
////Run time:312MS
////Run memory:1404KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b){
	return *(int *)a - *(int *)b;
}

int main(){
	int n, *a, i;
	while(scanf("%d", &n) == 1){
		i = n;
		a = (int *)malloc(sizeof(int) *n);
		while(i--)
			scanf("%d", &a[i]);
		qsort(a, n, sizeof(int), cmp);
		printf("%d\n", a[n / 2]);
		free(a);
	}
	return 0;
}