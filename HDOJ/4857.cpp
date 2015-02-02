////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-07-21 10:47:07
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4857
////Problem Title: 
////Run result: Accept
////Run time:296MS
////Run memory:4432KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#define maxn 30002
using std::vector;
using std::priority_queue;

vector<int> vec[maxn];
vector<int>::iterator it;
int inDegree[maxn], ans[maxn];

int main()
{
	int t, n, m, a, b, i, count;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		memset(vec, 0, sizeof(vec));
		memset(inDegree, 0, sizeof(inDegree));
		while(m--){
			scanf("%d%d", &a, &b);
			vec[b].push_back(a);
			++inDegree[a];
		}
		priority_queue<int> Q;
		for(i = 1; i <= n; ++i)
			if(!inDegree[i]) Q.push(i);
		count = 1;
		while(!Q.empty()){
			m = Q.top();
			Q.pop();		
			for(it = vec[m].begin(); it != vec[m].end(); ++it){
				--inDegree[*it];
				if(!inDegree[*it]) Q.push(*it);
			}
			ans[count++] = m;
		}
		for(i = n; i >= 1; --i)
			if(i != 1) printf("%d ", ans[i]);
			else printf("%d\n", ans[i]);
	}
	return 0;
}
