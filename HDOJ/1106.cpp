////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-01-23 22:31:07
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1106
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:380KB
//////////////////System Comment End//////////////////

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 1000 + 5
char s[MAX];

int main(){
	vector<int> vec;
	int t, sign;
	while( scanf( "%s", s ) == 1 ){
		t = sign = 0;
		for( int i = 0; i != strlen(s); ++i ){
			if( s[i] == '5' ){
				if( sign ){
					vec.push_back( t );
					t = sign = 0;
				}
				continue;
			}
			t = t * 10 + s[i] - '0';
			sign = 1;
		}
		if( sign )
			vec.push_back( t );
		sort( vec.begin(), vec.end() );
		cout << vec[0];
		for( int i = 1; i != vec.size(); ++i )
			cout << ' ' << vec[i];
		cout << endl;
		vec.clear();
	}
	return 0;
}
