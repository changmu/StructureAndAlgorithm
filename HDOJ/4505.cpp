////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-03-31 22:10:52
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4505
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:248KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int a[101];
int main(){
	int t, n, temp, sum, max;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		max = 0;
		while(n--){
			scanf("%d", &temp);
			if(temp > max) max = temp;
			++a[temp];
		}
		sum = max * 10;
		for(int i = 1; i <= max; ++i){
			if(a[i]){
				sum += 5 + a[i];
				a[i] = 0;
			}
		}
		printf("%d\n", sum);
	}
	
	return 0;
}