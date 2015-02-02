////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: 长木
////Run ID: 
////Submit time: 2014-01-29 16:36:52
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2054
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:260KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#define MAX 100000
char a[MAX], b[MAX];

char *simp(char *s){
	if(s[0] == '+') s[0] = '0';
	//删掉小数点之前的前导0
	if(s[0] == '-')
		while(s[1] == '0') ++s, s[0] = '-';
	while(s[0] == '0') ++s;
	//删掉小数尾0
	int len = strlen(s);
	if(strchr(s, '.'))
		while(s[--len] == '0') s[len] = '\0';
	if(s[len] == '.') s[len] = '\0';
	if(strlen(s) == 0 || strlen(s) == 1 && s[0] == '-') s[0] = '0', s[1] = '\0';
	return s;
}

int main(){
	char *x, *y;
	while(scanf("%s%s", a, b) == 2){
		x = a, y = b;
		if( !strcmp(simp(x), simp(y)) ) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}