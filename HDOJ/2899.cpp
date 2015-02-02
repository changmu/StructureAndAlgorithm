////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-06-19 11:33:38
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2899
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:260KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <math.h>
double y, ans;

double f(double x){
	return 6 * pow(x, 7) + 8 * pow(x, 6) + 
		7 * pow(x, 3) + 5 * x * x - y * x;
}

double ff(double x){ //Çóµ¼
	return 42 * pow(x, 6) + 48 * pow(x, 5) 
		+ 21 * x * x + 10 * x - y;
}

int main(){
	int n;
	scanf("%d", &n);
	while(n--){
		scanf("%lf", &y);
		if(ff(0) >= 0) ans = f(0);
		else if(ff(100) <= 0) ans = f(100);
		else{
			double left = 0, right = 100, mid;
			while(left + 1e-8 < right){
				mid = (left + right) / 2;
				if(ff(mid) > 0) right = mid;
				else if(ff(mid) < 0) left = mid;
				else break;
			}
			ans = f(mid);
		}
		printf("%.4lf\n", ans);
	}
	return 0;
}