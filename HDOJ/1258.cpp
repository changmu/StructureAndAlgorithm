////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-02 09:25:32
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1258
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:200KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int arr[12], vis[12];
int t, n, ok;

void PRINT(int id)
{
	for(int i = 0; i < id; ++i)
		if(i != id - 1) printf("%d+", vis[i]);
		else printf("%d\n", vis[i]);
	ok = 1;
}

void DFS(int index, int id, int sum)
{
	if(sum >= t){
		if(sum == t) PRINT(id);
		return;
	}
	for(int j = index; j < n; ++j){
		if(j == index || arr[j] != arr[j-1]){
			vis[id] = arr[j];
			DFS(j+1, id+1, sum+arr[j]);
		}
	}
}

int main()
{
	while(scanf("%d%d", &t, &n), n){
		for(int i = 0; i < n; ++i)
			scanf("%d", arr + i);
		printf("Sums of %d:\n", t);
		ok = 0; DFS(0, 0, 0);
		if(!ok) printf("NONE\n");
	}
	return 0;
}