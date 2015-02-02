////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-07-29 21:03:37
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2074
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:208KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#define maxn 82

char map[maxn][maxn];

int main()
{
	int n, i, j, k, sign, len, ii, cas = 1;
	char ch[2];
	while(scanf("%d %c %c", &n, &ch[0], &ch[1]) != EOF){
		sign = ((n / 2) & 1);
		for(i = 0; i < n / 2; ++i, sign = !sign){
			len = n - i * 2;
			k = len - 1; j = i;
			while(k--) map[i][j++] = ch[sign];
			k = len - 1; ii = i;
			while(k--) map[ii++][j] = ch[sign];
			k = len - 1;
			while(k--) map[ii][j--] = ch[sign];
			k = len - 1;
			while(k--) map[ii--][j] = ch[sign];
		}
		map[n/2][n/2] = ch[0];
		if(n != 1)
  			map[0][0] = map[0][n-1] = map[n-1][0] = map[n-1][n-1] = ' ';
		if(cas++ != 1) printf("\n");
		for(i = 0; i < n; ++i){
			map[i][n] = '\0';
			printf("%s\n", map[i]);
		}
	}
	return 0;
}
