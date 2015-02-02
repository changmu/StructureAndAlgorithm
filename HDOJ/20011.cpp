////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-05-05 22:11:43
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2001
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<math.h>
#define abs(x) x > 0 ? x : -(x)
int main()
{
	double x1,y1,x2,y2;
	while(scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2)!=EOF)
	{
		printf("%.2lf\n",hypot(abs(x2-x1),abs(y2-y1)));
	}
	return 0;
}
