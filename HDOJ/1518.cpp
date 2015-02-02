////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-11-02 18:57:30
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1518
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:296KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>

#define maxn 22

int L[maxn], n, tar, times;
bool vis[maxn], ok;

bool DFS(int k, int leftLen) {
	if(!leftLen) {
		if(++times == 4) return true;
		for(int i = 1; i < n; ++i) {
			if(!vis[i]) {
				vis[i] = 1;
				if(DFS(i + 1, tar - L[i])) 
					return true;
				else {
					--times;
					vis[i] = 0;
					return false;
				}
			}
		}
	}

	int i;
	for(i = k; i < n; ++i) {
		if(!vis[i] && L[i] <= leftLen) {
			vis[i] = 1;
			if(L[i-1] == L[i] && !vis[i-1]) {
				vis[i] = 0;
				continue;
			}
			if(DFS(i+1, leftLen - L[i]))
				return true;
			vis[i] = 0;
		}
	}

	return false;
}

int main() {
	int t, i;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		tar = 0;
		for(i = 0; i < n; ++i) {
			scanf("%d", &L[i]);
			vis[i] = 0; tar += L[i];
		}

		if(tar % 4) {
			printf("no\n");
			continue;
		}
		tar /= 4;

		std::sort(L, L + n, std::greater<int>());
		if(L[0] > tar) {
			printf("no\n");
			continue;
		}

		times = 0; vis[0] = 1;
		DFS(1, tar - L[0]);

		printf(times == 4 ? "yes\n" : "no\n");
	}
	return 0;
}