////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: 长木
////Run ID: 
////Submit time: 2014-02-16 12:14:03
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1005
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int f[100];  //最多49一循环,关键是找到循环起点和循环次数，循环起点不一定为1

int main(){
	int a, b, n, i, j, cir;
	while(scanf("%d%d%d", &a, &b, &n), a || b || n){
		f[1] = f[2] = 1; cir = 0;
		for(i = 3; i != 100; ++i){
			f[i] = (a * f[i - 1] + b * f[i - 2]) % 7;
			for(j = 2; j != i; ++j)
				if(f[j - 1] == f[i - 1] && f[j] == f[i]){
					cir = i - j;
					break;
				}
			if(cir) break;
		}
		printf("%d\n", f[(n - j) % cir + j]);
	}
	return 0;
}