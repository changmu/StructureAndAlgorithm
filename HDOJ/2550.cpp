////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-07-31 09:16:22
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2550
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:208KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <algorithm>
using std::sort;

struct Node{
	int a, b;
} arr[52];

bool cmp(Node a, Node b)
{
	return a.a < b.a;
}

int main()
{
	int t, n, a, b, i, j;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(i = 0; i < n; ++i)
			scanf("%d%d", &arr[i].a, &arr[i].b);
		sort(arr, arr + n, cmp);
		for(i = 0; i < n; ++i){
			while(arr[i].b--){
				printf(">+");
				for(j = 0; j < arr[i].a - 2; ++j)
					printf("-");
				printf("+>\n");
			}
			printf("\n");
		}
	}
	return 0;
}
