////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-07-23 21:42:46
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3257
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:200KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#define maxn 482

char map[8][maxn];
bool isPrint[8];

void getIsPrint(int n)
{
	for(int i = 0; i < 7; ++i){
		isPrint[i] = n & 1;
		n >>= 1;
	}
}

int main()
{
	//freopen("stdout.txt", "w", stdout);
	int t, n, arr[5], i, j, id, k, cas = 1;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(i = id = 0; i < n; ++i){
			for(j = 0; j < 5; ++j, ++id){
				scanf("%X", arr + j);
				getIsPrint(arr[j]);
				for(k = 0; k < 7; ++k)
					if(isPrint[k]) map[k][id] = '#';
					else map[k][id] = ' ';
			}
			if(i != n - 1){
				for(k = 0; k < 7; ++k)
					map[k][id] = ' ';
				++id;
			}
		}
		printf("Case %d:\n\n", cas++);
		for(k = 0; k < 7; ++k){
			map[k][id] = '\0';
			printf("%s\n", map[k]);
		}
		printf("\n");
	}
	return 0;
}
