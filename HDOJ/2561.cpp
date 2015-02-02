////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-01-24 23:30:05
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2561
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:272KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	int t, n, a;
	vector<int> vec;
	scanf( "%d", &t );
	while( t-- && scanf( "%d", &n ) ){		
		while( n-- && scanf( "%d", &a ) )
			vec.push_back( a );
		sort( vec.begin(), vec.end() );
		printf( "%d\n", vec[1] );
		vec.clear();
	}
	return 0;
}