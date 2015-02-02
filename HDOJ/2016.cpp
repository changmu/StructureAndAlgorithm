////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-01-26 15:03:18
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2016
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:364KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n, t, temp, j;
	vector<int> vec;
	while( cin >> n, n ){
		while( n-- ){
			cin >> t;
			vec.push_back( t );
		}
		j = 0; temp = vec[0];
		for( int i = 1; i != vec.size(); ++i )
			if( vec[i] < temp )
				j = i, temp = vec[i];			
		t = vec[0], vec[0] = vec[j], vec[j] = t;
		for( int i = 0; i != vec.size() - 1; ++i )
			printf( "%d ", vec[i] );
		printf( "%d\n", vec[vec.size() - 1] );
		vec.clear();
	}
	return 0;
}