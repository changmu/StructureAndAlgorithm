////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-04-29 22:33:30
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1856
////Problem Title: 
////Run result: Accept
////Run time:375MS
////Run memory:78564KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <algorithm>
#include <string.h>
#define maxn 10000002
using std::max_element;
int pre[maxn], count[maxn];

int unionFind(int k){
	int i = k;
	while(pre[i])
		i = pre[i];
	int j = k, t;
	while(pre[j]){
		t = pre[j];
		pre[j] = i;
		j = t;
	}
	return i;
}

int main(){
	int n, a, b, x, y;
	while(scanf("%d", &n) == 1){
		if(n == 0){
			printf("1\n");
			continue;
		}
		while(n--){
			scanf("%d%d", &a, &b);
			x = unionFind(a);
			y = unionFind(b);
			if(x != y){
				pre[x] = y;
				count[y] = count[y] ? count[y] : 1;
				count[y] += (count[x] ? count[x] : 1);
			}
		}
		printf("%d\n", *max_element(count, count + maxn));
		memset(pre, 0, sizeof(pre));
		memset(count, 0, sizeof(count));
	}	
	return 0;
}