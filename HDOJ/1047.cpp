////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: 长木
////Run ID: 
////Submit time: 2014-02-14 12:50:35
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1047
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#define MAX 100 + 5
char s[MAX], buf[MAX];

void Compu(int len){
	//s[MAX - 1]为个位
	int jin, i, j, t;
	for(jin = 0, i = MAX - 2, j = len - 1; j >= 0; --j, --i){
		t = buf[j] - '0' + s[i] - '0' + jin; jin = 0;
		if(t > 9){
			jin = 1;
			t -= 10;
		}
		s[i] = t + '0';
	}
	while(jin){ //处理类似999+1的情况
		t = s[i] - '0' + jin; jin = 0;
		if(t > 9){
			jin = 1;
			t -= 10;
		}
		s[i] = t + '0';
	}
}

int main(){
	int t, len, i;
	scanf("%d", &t);
	while(t--){
		memset(s, '0', sizeof(s));
		s[MAX - 1] = '\0';
		while(scanf("%s", buf) == 1){
			len = strlen(buf);
			if(buf[0] == '0' && len == 1) break;
			Compu(len);
		}
		for(i = 0; s[i] == '0'; ++i)
			;
		if(i == MAX - 1) putchar('0');
		while(i < MAX - 1)			
			putchar(s[i++]);
		if(t) puts("\n");
		else puts("");
	}
	return 0;
}