////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-07-14 16:04:19
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1556
////Problem Title: 
////Run result: Accept
////Run time:703MS
////Run memory:596KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#define maxn 100002

int tree[maxn], n;

int lowBit(int x){ return x & (-x); }

void update(int pos, int val)
{
	while(pos > 0){
		tree[pos] += val;
		pos -= lowBit(pos);
	}
}

int getSum(int pos)
{
	int sum = 0;
	while(pos <= n){
		sum += tree[pos];
		pos += lowBit(pos);
	}
	return sum;
}

int main()
{
	int a, b, i;
	while(scanf("%d", &n), n){
		memset(tree, 0, sizeof(tree));
		for(i = 0; i < n; ++i){
			scanf("%d%d", &a, &b);
			update(a - 1, -1);
			update(b, 1);
		}
		
		for(i = 1; i <= n; ++i)
			if(i != n) printf("%d ", getSum(i));
			else printf("%d\n", getSum(i));
	}
	return 0;
}
