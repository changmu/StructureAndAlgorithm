////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: 长木
////Run ID: 
////Submit time: 2014-10-27 15:59:26
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1042
////Problem Title: 
////Run result: Accept
////Run time:2000MS
////Run memory:384KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>

#define maxn 40000

int arr[maxn] = {1}, id;

void cal(int a[], int k) { // 将k乘到数组里
	int i;
	for(i = 0; i <= id; ++i)
		a[i] *= k;
	for(i = 0; i <= id; ++i)
		if(a[i] > 9) {
			a[i+1] += a[i] / 10;
			a[i] %= 10;
		}
	while(a[id+1]) {
		++id;
		a[id+1] += a[id] / 10;
		a[id] %= 10;
	}
}

void Initial() {
	memset(arr, 0, sizeof(arr));
	arr[0] = 1; id = 0;
}

int main() {
	int i, n;
	while(~scanf("%d", &n)) {
		Initial();
		for(i = 1; i <= n; ++i)
			cal(arr, i);
		while(id >= 0) printf("%d", arr[id--]);
		printf("\n");
	}
	return 0;
}