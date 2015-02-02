////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-03-15 14:05:50
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1052
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:240KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <stdlib.h>
int a[1001], b[1001];

int cmp(const void *a, const void *b){
	return *(int *)a - *(int *)b;
}

int main(){
	int n, count, i;
	int ax, ay, bx, by;
	while(scanf("%d", &n), n){
		count = 0;
		for(i = 0; i != n; ++i)
			scanf("%d", &a[i]);
		for(i = 0; i != n; ++i)
			scanf("%d", &b[i]);
		qsort(a, n, sizeof(int), cmp);
		qsort(b, n, sizeof(int), cmp);
		
		ax = bx = count = 0;
		ay = by = n - 1;
		
		while(ax <= ay){
			if(a[ay] > b[by]){
				++count;
				--ay;
				--by;				
			}else if(a[ay] < b[by]){
				--count;
				++ax;
				--by;
			}else{
				if(a[ax] < b[bx]){
					--count;
					++ax;
					--by;
				}else if(a[ax] == b[bx]){
					if(a[ax] < b[by]) --count;
					++ax; --by;
				}else{
					++ax; ++bx;
					++count;
				}
			}
		}
		printf("%d\n", count * 200);
	}
	return 0;
}