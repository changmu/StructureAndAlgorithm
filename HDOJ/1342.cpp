////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-06-02 17:42:09
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1342
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:200KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int arr[14], vis[14], n, store[6], id, blank;

void DFS(int k){
	if(id == 6){
		for(int i = 0; i < 6; ++i)
			if(i == 0) printf("%d", store[i]);
			else printf(" %d", store[i]);
		printf("\n"); return;		
	}
	for(int i = k; i < n; ++i){
		if(!vis[i]){
			store[id++] = arr[i];
			vis[i] = 1; DFS(i + 1);
			vis[i] = 0; --id;
		}
	}
}

int main(){
	while(scanf("%d", &n), n){
		for(int i = 0; i < n; ++i){
			scanf("%d", arr + i);
			vis[i] = 0;
		}
		if(blank) printf("\n");
		id = 0; DFS(0);
		++blank;
	}
	return 0;
}