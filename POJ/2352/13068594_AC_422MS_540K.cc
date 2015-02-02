//#define DEBUG
#include <stdio.h>
#define maxn 32002

int tree[maxn], level[maxn], n;

int lowBit(int x)
{ 
	return x & (-x); 
}

void update(int pos)
{
	while(pos < maxn){
		++tree[pos];
		pos += lowBit(pos);
	}
}

int getSum(int pos)
{
	int sum = 0;
	while(pos > 0){
		sum += tree[pos];
		pos -= lowBit(pos);
	}
	return sum;
}

int main()
{
	#ifdef DEBUG
		freopen("stdin.txt", "r", stdin);
		freopen("stdout.txt", "w", stdout);
	#endif

	int x, y, i;
	scanf("%d", &n);
	
	for(i = 0; i < n; ++i){
		scanf("%d%d", &x, &y);
		++level[getSum(++x)];
		update(x);
	}
	
	for(i = 0; i < n; ++i)
		printf("%d\n", level[i]);
	
	return 0;
}