////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-10-18 19:28:51
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2082
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:200KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>

#define maxn 30
#define maxc 52

int arr[maxn], c1[maxc], c2[maxc];

int main() {
	// freopen("stdin.txt", "r", stdin);
	int t, i, j, k;
	scanf("%d", &t);
	while(t--) {
		for(i = 1; i <= 26; ++i)
			scanf("%d", &arr[i]);
		for(i = 0; i <= 50; ++i)
			c1[i] = c2[i] = 0;
		for(i = 1; !arr[i]; ++i)
			;
		for(j = 0; j <= arr[i] * i; j += i)
			c1[j] = 1;
		for(++i; i <= 26; ++i) {
			if(!arr[i]) continue;
			for(j = 0; j <= 50; ++j)
				for(k = 0; k <= arr[i] * i && j + k <= 50; k += i)
					c2[k+j] += c1[j];
			for(j = 0; j <= 50; ++j) {
				c1[j] = c2[j]; c2[j] = 0;
			}
		}
		for(i = 2; i <= 50; ++i)
			c1[1] += c1[i];
		printf("%d\n", c1[1]);
	}
	return 0;
}