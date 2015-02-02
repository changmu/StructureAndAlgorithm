////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-10-20 19:06:01
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1250
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:9240KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>

#define mod 1000000000

int arr[10001][230];

void Add(int i, int j) {
	for(int k = 0; k < 230; ++k) {
		arr[i][k] += arr[j][k];
		if(arr[i][k] >= mod) {
			arr[i][k] -= mod;
			++arr[i][k+1];
		}
	}
}

int main() {
	int i, j, n;
	for(i = 1; i < 5; ++i)
		arr[i][0] = 1;
	for(i = 5; i < 10001; ++i) {
		for(j = i - 4; j < i; ++j)
			Add(i, j);
	}
	while(scanf("%d", &n) == 1) {
		for(j = 229; ; --j)
			if(arr[n][j]) {
				printf("%d", arr[n][j]);
				break;
			}
		for(--j; j >= 0; --j)
			printf("%09d", arr[n][j]);
		printf("\n");
	}
	return 0;
}