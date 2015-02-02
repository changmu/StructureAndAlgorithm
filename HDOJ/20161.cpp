////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-05-10 22:58:17
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2016
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:208KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <algorithm>
using namespace std;
int a[101];
int main(){
	int n, *p, t;
	while(scanf("%d", &n), n){
		for(int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		p = min_element(a,  a + n);
		t = *p; *p = a[0]; a[0] = t;
		for(int i = 0; i < n; ++i)
			if(i == 0) printf("%d", a[i]);
			else printf(" %d", a[i]);
		printf("\n");
	}
	return 0;
}