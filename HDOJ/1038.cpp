////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-05-10 12:41:24
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1038
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:224KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#define inchToMile (12 * 5280)
#define PI 3.1415927

int main(){
	int count = 1;
	double diameter, time, speed, distence;
	int revolution;
	while(scanf("%lf%d%lf", &diameter, &revolution, &time), revolution){
		printf("Trip #%d: ", count++);
		distence = diameter * PI * revolution / inchToMile;
		speed = distence / time * 3600;
		printf("%.2lf %.2lf\n", distence, speed);
	}
	return 0;
}