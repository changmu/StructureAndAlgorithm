////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: 长木
////Run ID: 
////Submit time: 2014-06-01 23:02:58
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1735
////Problem Title: 
////Run result: Accept
////Run time:375MS
////Run memory:4248KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <algorithm>
using std::sort;
int N, L, M, arr[10002][102], ans, id;
struct Node{
	int num, pre;
} pra[10002];

int getPre(int i){
	if(--i == 0) return 0;
	int j = L;
	while(arr[i][j] == 0) --j;
	return L - j;
}

void addPre(int i){
	if(--i == 0) return;
	int j = L;
	while(arr[i][j] == 0){
		++ans;
		arr[i][j] = 1;
		--j;
	}
}

bool cmp(Node a, Node b){
	return a.pre < b.pre;
}

int main(){
	int left, right;
	while(scanf("%d%d%d", &N, &L, &M) == 3){
		id = ans = 0; --M;
		for(int i = 1; i <= N; ++i){
			left = L; right = 1;
			for(int j = 1; j <= L; ++j){
				scanf("%d", &arr[i][j]);
				if(arr[i][j]){
					if(j < left) left = j;
					if(j > right) right = j;
				}
			}
			if(left > 2){
				for(int j = 3; j <= right; ++j){
					if(arr[i][j] == 0) ++ans, arr[i][j] = 1;					
				}
				if(i != 1){
					pra[id].num = i;
					pra[id++].pre = getPre(i);
				}
			}else{
				addPre(i);
				for(int j = 1; j <= right; ++j){
					if(arr[i][j] == 0) ++ans, arr[i][j] = 1;					
				}
			}
		}
		
		sort(pra, pra + id, cmp);
		id = id - M; //需要合并的段落数
		for(int i = 0; i < id; ++i)
			ans += pra[i].pre + 2;
		printf("%d\n", ans);
	}
	return 0;
}