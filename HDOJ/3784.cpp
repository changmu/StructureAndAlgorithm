////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-02-15 22:47:59
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3784
////Problem Title: 
////Run result: Accept
////Run time:875MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int a[501], b[501];

int main(){
	int n, i, t, j, k;
	while(scanf("%d", &n), n){
		for(i = 1; i <= n; ++i){
			scanf("%d", &a[i]);
			b[i] = 0;
		}
		for(j = 1; j <= n; ++j){
			t = a[j];
			//for(k = j + 1; k <= n; ++k)
			//	if(t == a[k]) b[k] = 1;			
			while(t != 1){
				if(t & 1) t = (t * 3 + 1) / 2;
				else t /= 2;
				for(k = 1; k <= n; ++k)
					if(k == j || b[k]) continue;
					else if(t == a[k]) b[k] = 1;		
			}
		}
		for(k = n, i = 1; k >= 1; --k){
			if(b[k]) continue;
			if(i) printf("%d", a[k]), i = 0;
			else printf(" %d", a[k]);
		}
		printf("\n");
	}
	return 0;
}