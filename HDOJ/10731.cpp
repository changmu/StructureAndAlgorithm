////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-10-27 22:37:18
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1073
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:236KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>

#define maxn 5010

char str0[maxn], str1[maxn], buf[maxn];

bool isKong(char ch) {
	return ch == ' ' || ch == '\n' || ch == '\t';
}

int main() {
	//freopen("stdin.txt", "r", stdin);
	int t, mode, id0, id1, i, j;
	bool PE, WA;
	scanf("%d", &t);
	while(t--) {
		mode = id1 = id0 = 0;
		PE = WA = false;
		while(gets(buf)) {
			if(!strcmp(buf, "START"))
				continue;
			else if(!strcmp(buf, "END")) {
				if(++mode == 2) break;
				else continue;
			}
			if(0 == mode) {
				for(i = 0; buf[i]; ++i)
					str0[id0++] = buf[i];
				str0[id0++] = '\n';
				str0[id0] = '\0';
			} else {
				for(i = 0; buf[i]; ++i)
					str1[id1++] = buf[i];
				str1[id1++] = '\n';
				str1[id1] = '\0';
			}
		}
		if(id0 != id1) PE = true;
		for(i = j = 0; i < id0 && j < id1; ) {
			bool flag = 0;			
			if(str0[i] != str1[j] && !PE)
				PE = true;
			if(isKong(str0[i])) {
				++i; flag = 1;
			}
			if(isKong(str1[j])) {
				++j; flag = 1;
			}
			if(flag) continue;
			if(str0[i++] != str1[j++]) {
				if(t == 1) printf("%c%c\n", str0[i-1]);
				WA = true; break;
			}
		}
		
		if(WA) {
			printf("Wrong Answer\n");
			continue;
		} 
		while(i < id0) {
			PE = true;
			if(isKong(str0[i++]))
				continue;
			WA = true; break;
		}
		while(j < id1) {
			PE = true;
			if(isKong(str1[j++]))
				continue;
			WA = true; break;
		}
		if(WA) {
			printf("Wrong Answer\n");
			continue;
		} else if(PE) {
			printf("Presentation Error\n");
			continue;
		}
		printf("Accepted\n");
	}
	return 0;
}
