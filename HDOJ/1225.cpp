////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-05-18 10:20:15
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1225
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:244KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <algorithm>
using std::sort;
struct Node{
	char name[1000];
	int win, lost, points, net;
} arr[100000];

int find(char str[], int k){
	for(int i = 0; i < k; ++i)
		if(!strcmp(str, arr[i].name)) return i;
	return -1;
}

bool cmp(Node a, Node b){
	if(a.points > b.points) return true;
	if(a.points == b.points && a.net > b.net) return true;
	if(a.points == b.points && a.net == b.net && a.win > b.win)
		return true;
	if(a.points == b.points && a.net == b.net && 
		a.win == b.win && strcmp(a.name, b.name) < 0)
		return true;
	return false;
}

int main(){
	int n, win, lost, pos, id, sign;
	char name1[1000], name2[1000];
	while(scanf("%d", &n) == 1){
		id = 0;
		for(int i = 0; i < n * (n - 1); ++i){
			scanf("%s%*s%s %d:%d", name1, name2, &win, &lost);
			sign = win - lost;
			if((pos = find(name1, id)) != -1){
				arr[pos].win += win;
				arr[pos].lost += lost;
				if(sign > 0) arr[pos].points += 3;
				else if(sign == 0) arr[pos].points += 1;
			}else{
				strcpy(arr[id].name, name1);
				arr[id].win = win;
				arr[id].lost = lost;
				if(sign > 0) arr[id].points = 3;
				else if(sign == 0) arr[id].points = 1;
				else arr[id].points = 0;
				++id;
			}
			if((pos = find(name2, id)) != -1){
				arr[pos].win += lost;
				arr[pos].lost += win;
				if(sign < 0) arr[pos].points += 3;
				else if(sign == 0) arr[pos].points += 1;
			}else{
				strcpy(arr[id].name, name2);
				arr[id].win = lost;
				arr[id].lost = win;
				if(sign < 0) arr[id].points = 3;
				else if(sign == 0) arr[id].points = 1;
				else arr[id].points = 0;
				++id;
			}
		}
		for(int i = 0; i < n; ++i)
			arr[i].net = arr[i].win - arr[i].lost;
		sort(arr, arr + n, cmp);
		for(int i = 0; i < n; ++i)
			printf("%s %d\n", arr[i].name, arr[i].points);
		printf("\n");
	}
	return 0;
}