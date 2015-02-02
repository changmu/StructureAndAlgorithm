////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-07-31 17:20:15
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2094
////Problem Title: 
////Run result: Accept
////Run time:93MS
////Run memory:344KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <set>
#include <string>
using namespace std;

int main()
{
	int n, count;
	string a, b;
	set<string> st, total;
	while(scanf("%d", &n), n){
		st.clear(); total.clear();
		count = 0;
		while(n--){
			cin >> a >> b;
			total.insert(a);
			total.insert(b);
			if(!st.count(b)){
				++count; st.insert(b);
			}
		}
		if(total.size() - st.size() == 1) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}