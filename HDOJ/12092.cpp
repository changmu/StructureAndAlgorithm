////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-05-16 10:19:40
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1209
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <math.h>
#include <algorithm>
using std::sort;
struct Node{
	int h, m;
	double val;
} a[5];

bool cmp(Node x, Node y){
	if(x.val < y.val) return 1;
	if(x.val == y.val && x.h < y.h) return 1;
	if(x.val == y.val && x.h == y.h && x.m < y.m) return 1;
	return 0;
}

int main(){
	int t, h, m;
	double val;
	scanf("%d", &t);
	while(t--){
		for(int i = 0; i < 5; ++i){
			scanf("%d:%d", &a[i].h, &a[i].m);
			h = a[i].h; m = a[i].m;
			if(h > 12) h -= 12;
			val = fabs((h + m / 60.0) * 30.0 - m * 6.0);
			if(val > 180) val = 360 - val;
			a[i].val = val;
		}
		sort(a, a + 5, cmp);
		printf("%02d:%02d\n", a[2].h, a[2].m);
	}
	return 0;
}