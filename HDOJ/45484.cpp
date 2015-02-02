////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-05-31 23:59:17
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4548
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:5096KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <math.h>
#define maxn 1000000 + 2
bool prime[maxn] = {1, 1};
int arr[maxn];

int sum(int n){
	int ans = 0;
	while(n){
		ans += n % 10;
		n /= 10;
	}
	return ans;
}

int main(){
	int t = sqrt(maxn), left, right;
	for(int i = 2; i <= t; ++i){
		if(prime[i]) continue;
		for(int j = i * i; j < maxn; j += i)
			prime[j] = 1;
	}
	for(int i = 2; i < maxn; ++i){
		arr[i] = arr[i-1];
		if(!prime[i] && !prime[sum(i)]) ++arr[i];
	}
	
	scanf("%d", &t);
	for(int i = 1; i <= t; ++i){
		scanf("%d%d", &left, &right);
		printf("Case #%d: %d\n", i, arr[right] - arr[left-1]);
	}
	return 0;
}