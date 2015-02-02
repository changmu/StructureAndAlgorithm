////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-06-18 20:11:48
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1106
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxn 1000 + 2
char str[maxn];
int arr[maxn], id;

int cmp(const void *a, const void *b){
	return *(int *)a - *(int *)b;
}

int main(){
	while(scanf("%s", str) == 1){
		char *p = strtok(str, "5");
		id = 0;
		while(p != NULL){
			sscanf(p, "%d", &arr[id++]);
			p = strtok(NULL, "5");
		}
		qsort(arr, id, sizeof(int), cmp);
		for(int i = 0; i < id; ++i)
			if(i != id - 1) printf("%d ", arr[i]);
			else printf("%d\n", arr[i]);
	}
	return 0;
}