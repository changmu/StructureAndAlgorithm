////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: 长木
////Run ID: 
////Submit time: 2014-03-11 22:34:37
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1050
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>

struct Node{
	int begin, end;
};

Node a[201];
int p[401];

int main(){
	int t, n, i, temp, count, j;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(i = 0; i != n; ++i){
			scanf("%d%d", &a[i].begin, &a[i].end);		
			
			if(a[i].begin > a[i].end){
				temp = a[i].begin;
				a[i].begin = a[i].end;
				a[i].end = temp;
			}
			
			if(a[i].begin & 1 == 0) --a[i].begin; //调整门口占用
			if(a[i].end & 1) ++a[i].end;
		}
		for(i = 0; i != n; ++i)
			for(j = a[i].begin; j <= a[i].end; ++j)
				++p[j];
		for(i = count = 0; i != 401; ++i)
			if(p[i] > count) count = p[i];
			
		printf("%d\n", count * 10);
		
		for(i = 0; i != 401; ++i)
			p[i] = 0;
	}
	return 0;
}