////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-04-22 14:02:55
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1015
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int len, target, ok;
char str[15], store[6];
bool hasSelect[15];

int cmp(const void *a, const void *b){
	return *(char *)b - *(char *)a;
}

void DFS(int k){
	if(k == 5){
	
		int v = store[0] - 'A' + 1, w = store[1] - 'A' + 1, x = store[2] - 'A' + 1, y = store[3] - 'A' + 1, z = store[4] - 'A' + 1;
		if(target == v - w*w + x*x*x - y*y*y*y + z*z*z*z*z)
			ok = 1;		
		return;
	}
	
	for(int i = 0; i < len; ++i){
		if(hasSelect[i] == 0){
			store[k] = str[i];
			hasSelect[i] = 1;
			DFS(k + 1);
			if(ok) return;
			hasSelect[i] = 0;
		}
	}
}

int main(){	
	store[5] = '\0';
	while(scanf("%d%s", &target, str), target){
		len = strlen(str);
		qsort(str, len, sizeof(char), cmp);
		ok = 0;
		DFS(0);
		if(ok) puts(store);
		else puts("no solution");
		memset(hasSelect, 0, 15);
	}
	return 0;
}