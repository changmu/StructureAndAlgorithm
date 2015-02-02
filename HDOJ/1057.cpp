////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-05-12 23:12:57
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1057
////Problem Title: 
////Run result: Accept
////Run time:218MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int arr[22][22], temp[22][22], d[17];
char sign[] = {'.', '!', 'X', '#'};

int main(){
	int t, n, k;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 0; i < 16; ++i)
			scanf("%d", &d[i]);
		for(int i = 1; i < 21; ++i)
			for(int j = 1; j < 21; ++j)
				scanf("%d", &arr[i][j]);			
		while(n--){
			for(int i = 1; i < 21; ++i)
				for(int j = 1; j < 21; ++j){
					k = arr[i][j] + arr[i][j+1] + 
						arr[i][j-1] + arr[i-1][j] + arr[i+1][j];
					temp[i][j] = arr[i][j] + d[k];
					if(temp[i][j] < 0) temp[i][j] = 0;
					else if(temp[i][j] > 3) temp[i][j] = 3;
				}
			for(int i = 1; i < 21; ++i)
				for(int j = 1; j < 21; ++j) arr[i][j] = temp[i][j];
		}
		for(int i = 1; i < 21; ++i){
			for(int j = 1; j < 21; ++j)
				putchar(sign[arr[i][j]]);			
			putchar('\n');
		}
		if(t) putchar('\n');
	}
	return 0;
}