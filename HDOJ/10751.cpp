////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-10 14:33:29
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1075
////Problem Title: 
////Run result: Accept
////Run time:1593MS
////Run memory:41216KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cctype>
#include <map>
using namespace std;

int main()
{
	char buf[12], s1[12], s2[12], ch;
	map<string, string> mp;
	int id = 0;
	gets(buf); //strip START
	while(scanf("%s%s", s1, s2), strcmp(s1, "END")){
		mp[s2] = s1;
	}
	getchar();
	while(scanf("%c", &ch)){
		if(isalpha(ch)) buf[id++] = ch;
		else{
			buf[id] = '\0'; id = 0;
			if(strcmp(buf, "END") == 0) break;
			if(mp.find(buf) != mp.end()){
				cout << mp[buf];
			}else printf("%s", buf);
			putchar(ch);
		}
	}
	return 0;
}
