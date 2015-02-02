#include <stdio.h>
#define maxn 10002

int sum[maxn], arr[maxn];

int find(int k, int n)
{
	for(int i = k + 1; i <= n; ++i)
		if(sum[i] == sum[k]) return i;
	return -1;
}

int main()
{
	int n, i, tmp, temp, j;
	while(scanf("%d", &n) != EOF){
		tmp = 0;
		for(i = 1; i <= n; ++i){
			scanf("%d", &temp);
			arr[i] = temp;
			tmp += temp; tmp %= n;
			sum[i] = tmp;
		}
		for(i = 1; i < n; ++i) 
			if((j = find(i, n)) != -1) break;
		printf("%d\n", j - i);
		while(++i <= j) printf("%d\n", arr[i]);		
	}
	return 0;
}