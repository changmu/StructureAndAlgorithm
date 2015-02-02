////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-01-29 17:52:52
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2037
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <stdlib.h>

struct Node{
	int begin;
	int end;
};

int cmp(const void *a, const void *b){
	return ((Node *)a)->end - ((Node *)b)->end;
}

int main(){
	int n, i, count;
	Node *p;
	while(scanf("%d", &n), n){
		p = (Node *)malloc(sizeof(Node) * n);
		i = n; count = 1;
		while(--n >= 0)
			scanf("%d%d", &p[n].begin, &p[n].end);
		qsort(p, i, sizeof(Node), cmp);
		int j = 0, k = 1;
		while(1){
			if(j == i || k == i) break;
			if(p[j].end <= p[k].begin){
				++count;
				j = k;
			}			
			++k;
		}
		printf("%d\n", count);
		free(p);
	}
	return 0;
}