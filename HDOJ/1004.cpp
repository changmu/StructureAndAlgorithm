////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-01-23 11:00:17
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1004
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:396KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
	int n;
	string t;
	vector<int> count;
	vector<string> str;
	while( scanf( "%d", &n ), n ){
		while( n-- ){
			cin >> t;
			if( str.empty() ){
				str.push_back( t );
				count.push_back( 1 );
			}			
			for( int i = 0; i != str.size(); ++i )
				if( str[i] == t ){
					++count[i];
					break;
				}
				else if( i + 1 == str.size() ){
					str.push_back( t );
					count.push_back( 1 );
				}			
		}
		int max = 0;
		for( int i = 1; i != count.size(); ++i )
			if( count[i] > count[max] )
				max = i;
		cout << str[max] << endl;
		str.clear();
		count.clear();
	}		
	return 0;
}
