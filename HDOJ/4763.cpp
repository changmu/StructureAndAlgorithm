////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-07-17 20:44:51
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4763
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:5096KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#define maxn 1000002

char str[maxn];
int next[maxn];

void getNext()
{
	int i = 0, j = -1;
	next[0] = -1;
	while(str[i]){
		if(j == -1 || str[i] == str[j]){
			++i; ++j;
			next[i] = j; //mode 1
		}else j = next[j];
	}
}

int KMP()
{
	getNext();
	int i, j, len = strlen(str);

	for(i = next[len]; i; i = next[i]){
		for(j = i << 1; j <= len - i; ++j){
			if(next[j] == i) return i;
		}			
	}

	return 0;
}

int main()
{
	//freopen("stdin.txt", "r", stdin);
	int cas;
	scanf("%d", &cas);
	while(cas--){
		scanf("%s", str);
		printf("%d\n", KMP());
	}	
	return 0;
}
