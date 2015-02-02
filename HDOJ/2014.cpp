////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-01-25 21:52:29
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2014
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:264KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	vector<double> vec;
	int n;
	double t, s;
	while( scanf( "%d", &n) == 1 ){
		s = 0;
		while( n-- ){
			scanf( "%lf", &t );
			vec.push_back( t );
		}
		sort( vec.begin(), vec.end() );
		for( int i = 1; i != vec.size() - 1; ++i )
			s += vec[i];
		printf( "%.2lf\n", s / ( vec.size() - 2 ) );
		vec.clear();
	}
	return 0;
}