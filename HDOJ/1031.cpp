////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-04-22 16:30:27
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1031
////Problem Title: 
////Run result: Accept
////Run time:125MS
////Run memory:256KB
//////////////////System Comment End//////////////////
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct Node{
	int id;
	double val;
}temp;

bool cmp(Node a, Node b){
	return a.val > b.val;
}

int main(){
	int n, m, k;
	vector<Node> vec;
	vector<int> v;
	
	while(scanf("%d%d%d", &n, &m, &k) == 3){
		for(int i = 1; i <= m; ++i){
			scanf("%lf", &temp.val);
			temp.id = i;
			vec.push_back(temp);
		}
		
		while(--n){
			for(int i = 1; i <= m; ++i){
				scanf("%lf", &temp.val);
				vec[i - 1].val += temp.val;
			}
		}
		
		stable_sort(vec.begin(), vec.end(), cmp);
		
		for(int i = 0; i < k; ++i)
			v.push_back(vec[i].id);
		
		sort(v.begin(), v.end());
		
		vector<int>::reverse_iterator it;
		int flag = 1;
		for(it = v.rbegin(); it != v.rend(); ++it){
			if(flag) printf("%d", *it), flag = 0;
			else printf(" %d", *it);
		}		
		printf("\n");
		
		vec.clear();
		v.clear();
	}
	return 0;
}