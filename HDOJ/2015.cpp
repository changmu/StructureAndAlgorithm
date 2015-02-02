////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-01-25 22:29:53
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2015
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:252KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <vector>
int a[101];
using std::vector;

int main(){
	for( int i = 1; i != 101; ++i )
		a[i] = 2 * i;
	int n, m, s, i, t, count;
	vector<int> vec;
	while( scanf( "%d%d", &n, &m ) == 2 ){
		s = 0;
		for( i = 1; i <= n; ++i ){
			s += a[i];
			if( i % m == 0 ){
				vec.push_back( s );
				s = 0;
			}
		}
		if( s ) vec.push_back( s );
		for( i = 0; i != vec.size() - 1; ++i )
			printf( "%d ", vec[i] / m );
		if( s )
			printf( "%d\n", vec[i] / ( n % m ) );
		else
			printf( "%d\n", vec[i] / m );
			vec.clear();
	}
	return 0;
}