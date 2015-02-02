////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-07-30 21:55:20
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1715
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1180KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>

char dp[1002][1000];
char buf[1000];

void cal(char str1[], char str2[], char str[])
{
	int len1 = strlen(str1), id = 0;
	int len2 = strlen(str2), i;
	memset(buf, 0, sizeof(buf));
	while(len1 > 0 && len2 > 0)
		buf[id++] = str1[--len1] - '0' + str2[--len2] - '0';
	while(len1 > 0) buf[id++] = str1[--len1] - '0';
	while(len2 > 0) buf[id++] = str2[--len2] - '0';
	for(i = 0; i <= id; ++i)
		if(buf[i] > 9){
			++buf[i+1];
			buf[i] -= 10;
		}
	if(!buf[id]) --id;
	i = 0;
	while(id >= 0) str[i++] = buf[id--] + '0';
	str[i] = '\0';
}

int main()
{
	dp[1][0] = dp[2][0] = '1';
	dp[1][1] = dp[2][1] = '\0';
	int i, n;
	for(i = 3; i <= 1000; ++i)
		cal(dp[i-1], dp[i-2], dp[i]);
	scanf("%d", &n);
	while(n--){
		scanf("%d", &i);
		printf("%s\n", dp[i]);
	}
	return 0;
}