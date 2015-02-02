////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: 长木
////Run ID: 
////Submit time: 2014-01-28 18:18:12
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2053
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:228KB
//////////////////System Comment End//////////////////
/*Sample Input
1
5
Sample Output
1
0
*/
//其实就是求n的因子个数，奇1偶0
#include <stdio.h>

int main(){
	int n, i, sign;
	while(scanf("%d", &n) == 1){
		for(sign = 1, i = 1; i <= n / 2; ++i)
			if(n % i == 0) sign = !sign;
		printf("%d\n", sign);
	}
	return 0;
}