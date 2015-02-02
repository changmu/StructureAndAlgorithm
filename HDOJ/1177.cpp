////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-05-31 14:05:23
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1177
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <algorithm>
#define maxn 132
using std::sort;
struct Node{
	int num, sco, time;
}arr[132];

bool cmp(Node a, Node b){
	if(a.sco == b.sco) return a.time < b.time;
	return a.sco > b.sco;
}

int main(){
	int n, g, s, c, mm;
	int h, m, ss;
	while(scanf("%d%d%d%d%d", &n, &g, &s,
		&c, &mm) != EOF && (n||g||s||c||mm)){
		for(int i = 0; i < n; ++i){
			scanf("%d %d:%d:%d", &arr[i].sco, &h, &m, &ss);
			arr[i].time = ss + m * 60 + h * 3600;
			arr[i].num = i + 1;
		}
		sort(arr, arr + n, cmp);
		for(int i = 0; i < n; ++i){
			if(arr[i].num == mm){
				if(i < g) printf("Accepted today? I've got a golden medal :)\n");
				else if(i < s + g) printf("Accepted today? I've got a silver medal :)\n");
				else if(i < c + s + g) printf("Accepted today? I've got a copper medal :)\n");
				else printf("Accepted today? I've got an honor mentioned :)\n");
				break;
			}
		}
	}
	return 0;
}