////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-07-18 10:57:41
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3746
////Problem Title: 
////Run result: Accept
////Run time:125MS
////Run memory:688KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#define maxn 100002

char str[maxn];
int len, next[maxn];

void getNext()
{
	int i = 0, j = -1;
	next[0] = -1;
	while(str[i]){
		if(j == -1 || str[i] == str[j]){
			++i; ++j; next[i] = j;
		}else j = next[j];
	}
	len = i; //save time
}

int main()
{
	int cas, ans;
	scanf("%d", &cas);
	while(cas--){
		scanf("%s", str);
		getNext();
		ans = len - next[len];
		if(ans != len && len % ans == 0)
			ans = 0;
		else ans = ans - next[len] % ans;
		printf("%d\n", ans);
	}
	return 0;
}
