////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: 长木
////Run ID: 
////Submit time: 2014-05-31 21:00:52
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2200
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:200KB
//////////////////System Comment End//////////////////
//从n个人里选m个人，分两组，相当于在这m个人之间插板，共有(m-1)中情况
#include <stdio.h>

__int64 cal(int n, int m){
	if(m > n / 2) m = n - m;
	__int64 ans = 1;
	for(int i = 0; i < m; ++i)
		ans = ans * (n - i) / (i + 1); //不可以写成 *=
	return ans;
}

int main(){
	int n;
	__int64 ans;
	while(scanf("%d", &n) == 1){
		ans = 0;
		for(int i = 2; i <= n; ++i)
			ans += (i - 1) * cal(n, i);
		printf("%I64d\n", ans);
	}
	return 0;
}