////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-01-27 21:10:41
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2043
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
char s[51];

int main(){
	int n, t, i, sign[4];
	scanf("%d", &n);
	getchar();
	while(n-- && gets(s)){
		for(i = 0; i != 4; ++i)
			sign[i] = 0;
		t = strlen(s);
		if(t < 8 || t > 16){
			printf("NO\n");
			continue;
		}
		for(i = 0; i != t; ++i)
			if(s[i] >= 'A' && s[i] <= 'Z') sign[0] = 1;
			else if(s[i] >= 'a' && s[i] <= 'z') sign[1] = 1;
			else if(s[i] >= '0' && s[i] <= '9') sign[2] = 1;
			else sign[3] = 1;
		for(i = t = 0; i != 4; ++i)
			t += sign[i];
		if(t >= 3) printf("YES\n");
		else printf("NO\n");
	}	
	return 0;
}