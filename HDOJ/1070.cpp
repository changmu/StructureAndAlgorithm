////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-06 22:35:26
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1070
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:224KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define maxn 102
using std::sort;

struct Node{
	char name[102];
	int price, vol;
	double dayPrice;
} arr[maxn];

bool cmp(Node a, Node b){
	if(a.price == b.price) return a.vol > b.vol;
	return a.dayPrice < b.dayPrice;
}

int main()
{
	int t, n, i, tmp, id;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(i = id = 0; i < n; ++i){
			scanf("%s%d%d", arr[id].name, &arr[id].price, &arr[id].vol);
			tmp = arr[id].vol / 200;
			if(arr[id].vol < 200)
				continue;			
			if(tmp > 5) tmp = 5;
			arr[id].dayPrice = arr[id].price * 1.0 / tmp;
			++id;
		}
		sort(arr, arr + id, cmp);
		printf("%s\n", arr[0].name);
	}
	return 0;
}
