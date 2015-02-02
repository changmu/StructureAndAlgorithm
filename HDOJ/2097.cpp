////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2015-01-15 19:23:41
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2097
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1084KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>

int f(int n, int num) {
	int sum = 0;
	while (n) {
		sum += n % num;
		n /= num;
	}
	return sum;
}

int main() {
	int n, ten, x, twelve;
	while (scanf("%d", &n), n) {
		ten = f(n, 10);
		x = f(n, 16);
		twelve = f(n, 12);
		if (ten == x && ten == twelve)
			printf("%d is a Sky Number.\n", n);
		else printf("%d is not a Sky Number.\n", n);
	}
	return 0;
}
