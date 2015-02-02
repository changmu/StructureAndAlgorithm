////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-01-27 17:04:35
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2036
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:244KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int main(){
	int n, ax, ay, bx, by, cx, cy;
	double s;
	while(scanf("%d", &n), n){
		scanf("%d%d%d%d%d%d", &ax, &ay, &bx, &by, &cx, &cy);
		n -= 3;
		s = (ax*by + ay*cx + bx*cy - ax*cy - ay*bx - cx*by) / 2.0;
		while(n--){
			bx = cx; by = cy;
			scanf("%d%d", &cx, &cy);
			s += (ax*by + ay*cx + bx*cy - ax*cy - ay*bx - cx*by) / 2.0;
		}
		printf("%.1lf\n", s);
	}
	return 0;
}