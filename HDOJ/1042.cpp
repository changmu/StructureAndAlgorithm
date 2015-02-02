////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: 长木
////Run ID: 
////Submit time: 2014-02-14 11:12:09
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1042
////Problem Title: 
////Run result: Accept
////Run time:1718MS
////Run memory:388KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#define MAX 40000
int A[MAX];

int find(){
	int i = MAX;
	while(!A[--i])
		;
	return i;
}

int main(){
	int n, i, j, k, m;
	while(scanf("%d", &n) == 1){
		if(n < 2){
			printf("1\n");
			continue;
		}		
		memset(A, 0, sizeof(A));
		A[0] = 1;  //A[0]是最低位
		for(i = 2; i <= n; ++i){
			k = find();
			for(j = 0; j <= k; ++j){
				A[j] *= i;
				//在完成一轮乘法后再进位		
			}
			//处理进位
			for(m = 0; m <= k || A[m] > 9; ++m)
				if(A[m] > 9)
					A[m + 1] += A[m] / 10, A[m] %= 10;
		}
		k = find();
		for(i = k; i >= 0; --i)
			printf("%d", A[i]);
		printf("\n");
	}
	return 0;
}