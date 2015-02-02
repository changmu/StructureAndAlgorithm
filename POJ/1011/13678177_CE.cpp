#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

int Len[66], tarLen, tarCnt, N, sum, cnt;
bool vis[66];

bool DFS(int k, int leftLen) {
	int i;
	if(leftLen == 0) {
		if(++cnt == tarCnt) return true;
		for(i = 0; i < N; ++i)
			if(!vis[i]) {
				vis[i] = 1;
				if(DFS(i + 1, tarLen - Len[i]))
					return true;
				else {
					vis[i] = 0;
					--cnt;
					return false;
				}
			}
	}
	for(i = k; i < N; ++i) {
		if(!vis[i] && Len[i] <= leftLen) {
			if(Len[i] == Len[i-1] && !vis[i-1])
				continue;
			vis[i] = 1;
			if(DFS(i + 1, leftLen - Len[i]))
				return true;
			vis[i] = 0;
		}
	}
	return false;
}

int main() {
	int i, j;
	while(scanf("%d", &N), N) {
		for(i = sum = 0; i < N; ++i) {
			scanf("%d", &Len[i]);
			sum += Len[i];
		}
		sort(Len, Len + N, greater<int>());
		for(tarLen = Len[0]; tarLen < sum; ++tarLen) {
			if(sum % tarLen) continue;
			tarCnt = sum / tarLen;
			memset(vis, 0, sizeof(vis));
			vis[0] = 1; cnt = 0;
			if(DFS(1, tarLen - Len[0])) break;
		}
		printf("%d\n", tarLen);
	}
	return 0;
}