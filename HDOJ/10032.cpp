////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-05-18 21:04:05
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1003
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:200KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int main(){
	int t, n, maxLeft, maxRight, maxSum, temp;
	int thisLeft, thisSum;
	scanf("%d", &t);
	for(int id = 1; id <= t; ++id){
		scanf("%d", &n);
		scanf("%d", &maxSum);
		thisLeft = maxLeft = maxRight =  0;
		thisSum = maxSum;
		if(thisSum < 0){ thisSum = 0; thisLeft = 1; }
		for(int i = 1; i < n; ++i){
			scanf("%d", &temp);
			thisSum += temp;
			if(thisSum > maxSum){
				maxSum = thisSum;
				maxLeft = thisLeft;
				maxRight = i;
			}
			if(thisSum < 0){
				thisLeft = i + 1;
				thisSum = 0;
			}
		}
		printf("Case %d:\n%d %d %d\n", id, maxSum, maxLeft + 1, maxRight + 1);
		if(id != t) printf("\n");
	}
	return 0;
}