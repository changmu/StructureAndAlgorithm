////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-02-13 13:40:07
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2502
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
struct Node{
	long long cas;
	long long num;
};

int main(){
	int t, n, s, i;
	Node a[21];
	a[0].cas = a[0].num = 0;
	a[1].cas = a[1].num = 1;
	a[2].cas = 2; a[2].num = 3;
	for(i = 3; i != 21; ++i){
		a[i].cas = a[i - 1].cas * 2;
		a[i].num = a[i - 1].num * 2 - a[i- 1].cas + a[i].cas;
	}
	scanf("%d", &t);		
	while(t-- && scanf("%d", &n))
		printf("%d\n", a[n].num);	
	return 0;
}