#include <stdio.h>
#include <string.h>
#include <algorithm>
#define maxn 500002
using std::sort;

int tree[maxn], ori[maxn], hash[maxn];
long long ans;

int getHash(int val, int n)
{
	int left = 0, right = n - 1, mid;
	while(left <= right){
		mid = (left + right) >> 1;
		if(val < hash[mid]) right = mid - 1;
		else if(val > hash[mid]) left = mid + 1;
		else return mid + 1;
	}
}

int lowBit(int pos){ return pos & (-pos); }

int getSum(int pos)
{
	int sum = 0;
	while(pos > 0){
		sum += tree[pos];
		pos -= lowBit(pos);
	}
	return sum;
}

void update(int pos, int n)
{
	ans += (pos - 1 - getSum(pos - 1));
	while(pos <= n){
		++tree[pos];
		pos += lowBit(pos);
	}
}


int main()
{
	int n, i;
	while(scanf("%d", &n), n){
		for(i = 0; i < n; ++i){
			scanf("%d", ori + i);
			hash[i] = ori[i];
		}
		
		sort(hash, hash + n);		
		for(i = 0; i < n; ++i)
			ori[i] = getHash(ori[i], n);			
		memset(tree, 0, sizeof(tree));
		
		ans = 0;
		for(i = 0; i < n; ++i) update(ori[i], n);
		printf("%lld\n", ans);
	}
	
	return 0;
}