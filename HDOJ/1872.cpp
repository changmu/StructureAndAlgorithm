////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-05-31 16:30:06
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1872
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:276KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <algorithm>
using std::stable_sort;
struct Node{
	char name[52];
	int sco;
} arr[302], tem[302];
bool notStable, error;

bool cmp(Node a, Node b){
	return a.sco > b.sco;
}

int main(){
	int n;
	while(scanf("%d", &n) != EOF){
		for(int i = 0; i < n; ++i)
			scanf("%s%d", arr[i].name, &arr[i].sco);
		stable_sort(arr, arr + n, cmp);
		
		notStable = error = 0;		
		for(int i = 0; i < n; ++i){
			scanf("%s%d", tem[i].name, &tem[i].sco);
			if(tem[i].sco != arr[i].sco) error = 1;
			else if(strcmp(tem[i].name, arr[i].name)) notStable = 1;
		}
		if(notStable == 0 && error == 0){
			printf("Right\n");
			continue;
		}
		if(error) printf("Error\n");
		else if(notStable) printf("Not Stable\n");
		
		for(int i = 0; i < n; ++i)
			printf("%s %d\n", arr[i].name, arr[i].sco);
	}
	return 0;
}