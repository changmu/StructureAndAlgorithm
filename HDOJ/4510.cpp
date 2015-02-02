////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-03-31 22:09:35
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4510
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:248KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#define con 12 * 3600

int main(){
	int h, m, s, hh, mm, ss, n, totalSecond, t;
	scanf("%d", &n);
	while(n--){
		scanf("%d:%d:%d %d:%d:%d", &h, &m, &s, &hh, &mm, &ss);
		totalSecond = h * 3600 + m * 60 + s;
		hh %= 12;
		t = hh * 3600 + mm * 60 + ss;
		t %= con;
		t = con - t;
		totalSecond += t;
		if(totalSecond >= con)
			totalSecond -= con;
		h = totalSecond / 3600;
		m = (totalSecond - h * 3600) / 60;
		s = totalSecond - h * 3600 - m * 60;
		printf("%02d:%02d:%02d\n", h, m, s);
	}
	return 0;
}