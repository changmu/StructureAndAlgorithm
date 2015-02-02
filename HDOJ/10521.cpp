////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-05 11:01:06
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1052
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:216KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <algorithm>
#define maxn 1002
using std::sort;

int tian[maxn], king[maxn];

int main()
{
	int n, i, tl, tr, kl, kr, ans;
	while(scanf("%d", &n), n){
		for(i = 0; i < n; ++i)
			scanf("%d", tian + i);
		for(i = 0; i < n; ++i)
			scanf("%d", king + i);
		sort(tian, tian + n);
		sort(king, king + n);
		tl = kl = 0; tr = kr = n - 1;
		ans = 0;
		while(tl <= tr){
			if(tian[tl] > king[kl]){
				++ans; ++tl; ++kl;
			}else if(tian[tl] < king[kl]){
				--ans; ++tl; --kr;
			}else{
				if(tian[tr] > king[kr]){
					++ans; --tr; --kr;
				}else if(tian[tr] < king[kr]){
					--ans; ++tl; --kr;
				}else{
					if(tian[tl] < king[kr])
						--ans;
					++tl; --kr;
				}
			} 
		}
		printf("%d\n", ans * 200);
	}
}