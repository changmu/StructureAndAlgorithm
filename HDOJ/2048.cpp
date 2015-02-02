////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-01-28 20:08:59
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2048
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:248KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int main(){
	int n, i;
	__int64 d[21] = {0, 0, 1};
	for(i = 3; i != 21; ++i)
		d[i] = (i - 1) * (d[i-1] + d[i-2]);
	double s, a[21] = {1, 1, 2};
	for(i = 3; i != 21; ++i)
		a[i] = i * a[i-1];
	double c[21];
	for(i = 1; i != 21; ++i)
		c[i] = d[i] / a[i];
	scanf("%d", &n);
	while(n-- && scanf("%d", &i))
		printf("%.2lf%%\n", c[i] * 100);	
	return 0;
}