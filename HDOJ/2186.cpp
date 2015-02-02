////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-02-08 00:59:55
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2186
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int main(){
	int t, c, s, x, y, z;
	scanf("%d", &t);
	while(t-- && scanf("%d", &c)){
		s = 3;
		x = c / 2;
		y = (c - x) * 2 / 3;
		z = c - x - y;
		while((x -= 10) > 0)
			++s;
		while((y -= 10) > 0)
			++s;
		while((z -= 10) > 0)
			++s;
		printf("%d\n", s);
	}
	return 0;
}