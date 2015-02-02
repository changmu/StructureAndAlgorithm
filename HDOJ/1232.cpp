////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: 长木
////Run ID: 
////Submit time: 2014-04-29 10:49:15
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1232
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:212KB
//////////////////System Comment End//////////////////
//并查集
#include <stdio.h>
int pre[1002];

int find(int k){
	int i = k;
	while(i != pre[i]) //找到该图的“元帅”
		i = pre[i]; 
	int j = k, t; //压缩路径，把遍历到的每个点的上级直接换成“元帅”
	while(j != i){
		t = pre[j];
		pre[j] = i;
		j = t;
	}
	return i; //"元帅"
}

int main(){
	int n, m, a, b, sum, x, y;
	while(scanf("%d", &n), n){
		scanf("%d", &m);
		sum = n - 1;
		for(int i = 1; i <= n; ++i) //每个城市都是独立的
			pre[i] = i;
		while(m--){
			scanf("%d%d", &a, &b);
			x = find(a);
			y = find(b);
			if(x != y){ //如果该两点不在同一个图里面的话就把这两张图连接起来
				pre[x] = y;
				--sum;
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}