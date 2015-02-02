////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-06-18 21:24:49
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2105
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int main(){
	int t;
	double x1, y1, x2, y2, x3, y3;
	while(scanf("%d", &t), t){
		while(t--){
			scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3);
			printf("%.1lf %.1lf\n", (x1+x2+x3)/ 3, (y1+y2+y3) / 3);
		}
	}
	return 0;
}