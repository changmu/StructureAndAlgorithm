////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-02-20 09:27:24
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1106
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:328KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX 1000 + 2
char str[MAX];
int a[MAX];

int main(){
	int count;
	char *p;
	while(scanf("%s", str) == 1){
		count = 0;
		p = strtok(str, "5");
		while(p != NULL){
			sscanf(p, "%d", &a[count++]);
			p = strtok(NULL, "5");
		}
		sort(a, a + count);
		int flag = 0;
		for(int i = 0; i != count; ++i)
			if(!flag) printf("%d", a[i]), flag = 1;
			else printf(" %d", a[i]);
		putchar('\n');
	}
	return 0;
}