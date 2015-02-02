////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-05 11:28:47
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1257
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <vector>
using std::vector;

int main()
{
	int n, i, a, t, j, ans;
	vector<int> vec;
	vector<bool> vis;
	while(scanf("%d", &n) == 1){
		vec.clear();
		vis.clear();
		for(i = 0; i < n; ++i){
			scanf("%d", &a);
			vec.push_back(a);
			vis.push_back(false);
		}
		for(i = ans = 0; i < n; ++i){
			if(vis[i]) continue;
			a = vec[i]; ++ans;
			for(j = i + 1; j < n; ++j){
				if(vis[j]) continue;
				if(a >= vec[j]){
					vis[j] = 1; a = vec[j];
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}