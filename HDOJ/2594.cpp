////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-07-17 22:18:24
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2594
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:740KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#define maxn 50002

char str1[maxn << 1], str2[maxn];
int ans, next[maxn << 1], len2;

void getNext()
{
	int i = 0, j = -1;
	next[0] = -1;
	while(str1[i]){
		if(j == -1 || str1[i] == str1[j]){
			++i; ++j;
			next[i] = j;
		}else j = next[j];
	}
	str1[ans = next[i]] = '\0';	
}

int main()
{	
	//freopen("stdin.txt", "r", stdin);
	while(scanf("%s%s", str1, str2) == 2){
		strcat(str1, " ");
		strcat(str1, str2); getNext();
		ans ? printf("%s %d\n", str1, ans) : printf("0\n");
	}
}
