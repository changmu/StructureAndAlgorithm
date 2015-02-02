////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-02-10 12:33:48
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1003
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:616KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int a[100001];

void subcross(int arr[], int *low, int *mid, int *high, int *sum){
	int s = 0, maxl = -1000 - 1, maxr = -1000 - 1, l, r;
	for(int i = *mid; i >= *low; --i){
		s += arr[i];
		if(s >= maxl){
			l = i; maxl = s;
		}
	}	
	for(int i = *mid + 1, s = 0; i <= *high; ++i){
		s += arr[i];
		if(s > maxr){
			r = i; maxr = s;
		}
	}
	*sum = maxl + maxr;
	*low = l;
	*high = r;
}

void subarr(int arr[], int *low, int *high, int *sum){
	if(*low == *high){
		*sum = arr[*low];
		return;
	}
	int l = *low, r = *high, s1, s2, s;
	int m = (l + r) / 2;
	int l1 = l, l2 = m + 1, r1 = m, r2 = r; 
	subarr(arr, &l1, &r1, &s1);
	subarr(arr, &l2, &r2, &s2);
	subcross(arr, &l, &m, &r, &s);
	if(s1 >= s2 && s1 >= s){
		*low = l1; *high = r1; *sum = s1;
	}
	else if(s >= s1 && s >= s2){
		*low = l; *high = r; *sum = s;
	}
	else{
		*low = l2; *high = r2; *sum = s2;
	}	
}

int main(){
	int t, n, low, sum, high, i, j = 1;
	scanf("%d", &t);
	while(t-- && scanf("%d", &n)){
		i = 1;
		while(n--)
			scanf("%d", &a[i++]);
		low = 1;
		high = i - 1;
		subarr(a, &low, &high, &sum);
		printf("Case %d:\n%d %d %d\n", j++, sum, low, high);
		if(t) putchar('\n');
	}
	return 0;
}