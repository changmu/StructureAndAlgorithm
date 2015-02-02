////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-07-31 17:53:13
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2094
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:224KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>

char str[2002][22];
int inDegree[2002], id;

int find(char str1[])
{
	for(int i = 0; i < id; ++i)
		if(!strcmp(str1, str[i])) return i;
	return -1;
}

void insert(char str1[])
{
	if(find(str1) != -1) return;
	strcpy(str[id++], str1);
}

int main()
{
	int n, i, count;
	char str1[22], str2[22];
	while(scanf("%d", &n), n){
		memset(inDegree, 0, sizeof(inDegree));
		id = count = 0;
		while(n--){
			scanf("%s%s", str1, str2);
			insert(str1); insert(str2);
			++inDegree[find(str2)];
		}
		for(i = 0; i < id; ++i)
			if(!inDegree[i]) ++count;
		if(count == 1) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}