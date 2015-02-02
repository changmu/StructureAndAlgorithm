////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-06-10 20:34:43
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2023
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:236KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int main(){
	int n, m, count;
	double arr[52][7], ave[7], temp;
	while(scanf("%d%d", &n, &m) == 2){
		for(int i = 0; i < 7; ++i) ave[i] = 0;
		for(int i = 0; i < n; ++i){
			temp = 0;
			for(int j = 0; j < m; ++j){
				scanf("%lf", &arr[i][j]);
				temp += arr[i][j];
				ave[j] += arr[i][j];
			}
			arr[i][m] = temp / m;
		}
		for(int i = 0; i < m; ++i) ave[i] /= n;
		count = 0;
		for(int i = 0; i < n; ++i){
			int ok = 1;
			for(int j = 0; j < m; ++j)
				if(arr[i][j] < ave[j]) ok = 0;
			if(ok) ++count;
		}
		for(int i = 0; i < n; ++i)
			if(i == 0) printf("%.2lf", arr[i][m]);
			else printf(" %.2lf", arr[i][m]);
		printf("\n");
		for(int i = 0; i < m; ++i)
			if(i == 0) printf("%.2lf", ave[i]);
			else printf(" %.2lf", ave[i]);
		printf("\n%d\n\n", count);
	}
	return 0;
}