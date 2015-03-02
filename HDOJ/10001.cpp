////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2015-02-10 19:25:59
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1000
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1056KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int Add(int num1, int num2)
{
	int sum, carry;
	do {
		sum = num1 ^ num2;
		carry = (num1 & num2) << 1;

		num1 = sum;
		num2 = carry;
	} while (num2);

	return num1;
}

int main()
{
	int a, b;
	while (~scanf("%d%d", &a, &b))
		printf("%d\n", Add(a, b));
	return 0;
}