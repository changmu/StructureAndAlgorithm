////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-13 19:04:39
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1203
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:272KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <algorithm>
#define maxn 10002
using namespace std;

struct Node{
	int w;
	double v, pos;
} arr[maxn];

bool cmp(Node a, Node b){
	return a.pos > b.pos;
}

int main()
{
	int n, m, i;
	double ans;
	while(scanf("%d%d", &n, &m), n || m){
		for(i = 0; i < m; ++i){
			scanf("%d%lf", &arr[i].w, &arr[i].v);
			arr[i].pos = arr[i].v / arr[i].w;
		}
		sort(arr, arr + m, cmp);
		ans = 1;
		for(i = 0; i < m; ++i){
			if(n >= arr[i].w){
				n -= arr[i].w;
				ans *= (1.0 - arr[i].v);
			}else break;
		}
		printf("%.1lf%%\n", 100.0 * (1 - ans));
	}
	return 0;
}
