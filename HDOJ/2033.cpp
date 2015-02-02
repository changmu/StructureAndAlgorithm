////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: 长木
////Run ID: 
////Submit time: 2014-01-27 13:48:35
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2033
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int main(){
	int n, ah, am, as, bh, bm, bs, sh, sm, ss, t;
	scanf("%d", &n);
	while(n--){
		scanf("%d%d%d%d%d%d", &ah, &am, &as, &bh, &bm, &bs);
		//全部转换成秒
		t = (ah + bh) * 60 * 60 + (am + bm) * 60 + (as + bs);
		ss = t % 60;
		t /= 60;
		sm = t % 60;
		sh = t / 60;
		printf("%d %d %d\n", sh, sm, ss);
	}
	return 0;
}