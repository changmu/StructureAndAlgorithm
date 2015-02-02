////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-06-02 20:01:24
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1804
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
struct Node{
	char str1[22], str2[22];
} irr[22];
char str[26]; int len, m, n;

int find(){
	for(int i = 0; i < m; ++i)
		if(!strcmp(str, irr[i].str1)) return i;
	return -1;
}

bool yuanyin(char ch){
	char *yuan = "aeiou";
	for(int i = 0; i < 5; ++i)
		if(ch == yuan[i]) return true;
	return false;
}

void check(){
	int flag = find();
	if(flag > -1){
		puts(irr[flag].str2); return;
	}
	if(str[len-1] == 'o' || str[len-1] == 's' || str[len-1] == 'x'){
		strcat(str, "es"); puts(str); return;
	}
	if(len > 1 && (str[len-1] == 'h' && (str[len-2] == 's' || str[len-2] == 'c'))){
		strcat(str, "es"); puts(str); return;
	}
	if(len > 1 && str[len-1] == 'y' && !yuanyin(str[len-2])){
		str[len-1] = '\0'; strcat(str, "ies"); puts(str); return;		
	}
	strcat(str, "s"); puts(str);
}

int main(){
	while(scanf("%d%d", &m, &n) == 2){
		for(int i = 0; i < m; ++i)
			scanf("%s%s", irr[i].str1, irr[i].str2);
		while(n--){
			scanf("%s", str);
			len = strlen(str);
			check();
		}
	}
	return 0;
}