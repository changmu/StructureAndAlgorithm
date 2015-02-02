////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-07 12:20:00
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1325
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:324KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#define maxn 10002

int in[maxn], pre[maxn], count;
bool vis[maxn];

int ufind(int k)
{
	int a = k;
	while(pre[k] != -1) k = pre[k];
	int b;
	while(pre[a] != -1){
		b = pre[a];
		pre[a] = k;
		a = b;
	}
	return k;
}

int main()
{
	//freopen("stdin.txt", "r", stdin);
	int a, b, ok = 1, cas = 1;
	memset(pre, -1, sizeof(pre));
	while(scanf("%d%d", &a, &b)){
		if(a < 0) break;
		if(a == 0){
			printf("Case %d is ", cas++);
			if(count != 1) ok = 0;
			printf(ok ? "a tree.\n" : "not a tree.\n");
			ok = 1; count = 0;
			memset(in, 0, sizeof(in));
			memset(vis, 0, sizeof(vis));
			memset(pre, -1, sizeof(pre));
			continue;
		}
		if(!ok) continue;
		if(!vis[a]){ ++count; vis[a] = 1; }
		if(!vis[b]){ ++count; vis[b] = 1; }
		if(++in[b] > 1) ok = 0;
		a = ufind(a); b = ufind(b);
		if(a == b) ok = 0;
		else { pre[a] = b; --count; }
	}
	return 0;
}