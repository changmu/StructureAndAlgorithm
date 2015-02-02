////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-01-27 09:51:13
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2028
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:380KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n, t, s, ok, i;
	vector<int> vec;
	while( cin >> n ){
		while( n-- ){
			cin >> t;
			vec.push_back(t);
		}
		sort(vec.begin(), vec.end());
		s = t = vec[vec.size() - 1];
		ok = 1;
		while( 1 ){
			for( i = 0; i != vec.size(); ++i )
				if(s % vec[i])
					ok = 0;
			if(ok) break;
			else s += t, ok = 1;
		}
		cout << s << endl;
		vec.clear();
	}
	return 0;
}