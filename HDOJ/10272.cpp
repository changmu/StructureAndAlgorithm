////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-07-21 15:51:51
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1027
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:252KB
//////////////////System Comment End//////////////////
#include <cstdio>
#include <algorithm>
using namespace std;

int arr[1002];

int main()
{
	int n, m, i;
	while(scanf("%d%d", &n, &m) != EOF){
		for(i = 0; i < n; ++i)
			arr[i] = i + 1;
		while(--m) next_permutation(arr, arr + n);
		for(i = 0; i < n; ++i)
			if(i != n - 1) printf("%d ", arr[i]);
			else printf("%d\n", arr[i]);
	}
	return 0;
}
