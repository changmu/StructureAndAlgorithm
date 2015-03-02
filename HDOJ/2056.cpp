////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2015-01-19 10:22:34
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2056
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1100KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <math.h>

struct Node {
	double x1, y1, x2, y2;
} p1, p2;

double min(double a, double b) { return a < b ? a : b; }
double max(double a, double b) { return a > b ? a : b; }
void swap(double& a, double& b) { double t = a; a = b; b = t; }

int main() {
	// freopen("stdin.txt", "r", stdin);
	double x1, y1, x2, y2;
	while (scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &p1.x1, &p1.y1, &p1.x2, &p1.y2, &p2.x1, &p2.y1, &p2.x2, &p2.y2) != EOF) {
		x1 = min(p1.x1, p1.x2);
		x2 = max(p1.x1, p1.x2);
		y1 = min(p1.y1, p1.y2);
		y2 = max(p1.y1, p1.y2);
		p1.x1 = x1;
		p1.y1 = y1;
		p1.x2 = x2;
		p1.y2 = y2;

		x1 = min(p2.x1, p2.x2);
		x2 = max(p2.x1, p2.x2);
		y1 = min(p2.y1, p2.y2);
		y2 = max(p2.y1, p2.y2);
		p2.x1 = x1;
		p2.y1 = y1;
		p2.x2 = x2;
		p2.y2 = y2;

		x1 = max(p1.x1, p2.x1);	
		y1 = max(p1.y1, p2.y1);	
		x2 = min(p1.x2, p2.x2);	
		y2 = min(p1.y2, p2.y2);	

		printf("%.2lf\n", x1 >= x2 || y1 >= y2 ? 0.0 : (x2 - x1) * (y2 - y1));
	}
	return 0;
}
