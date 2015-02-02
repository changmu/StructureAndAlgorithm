////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: 长木
////Run ID: 
////Submit time: 2014-01-29 23:31:59
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2058
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:228KB
//////////////////System Comment End//////////////////
/*找一个子序列的和等于M，那么这个子序列可以看成a+1, a+2, ... , a+d 这时，
d就为这个序列的长度,起始数字就是a+1，而这个序列的和即M=a*d + (1 + d) * d /2;
得出d*d<2 * m，从而可以枚举d,计算出a*/
#include <stdio.h>
#include <math.h>
int main(){
	int n, m, d, x;
	while(scanf("%d%d", &n, &m), n || m){
		d = (int)sqrt(2.0 * m);
		while(d > 0){
			x = m - (1 + d) * d / 2;
			if(x % d == 0) printf("[%d,%d]\n", x / d + 1, x / d + d);
			--d;
		}
		printf("\n");
	}
	return 0;
}