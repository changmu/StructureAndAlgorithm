////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: 长木
////Run ID: 
////Submit time: 2014-01-23 10:02:32
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1022
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:396KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <string>
using namespace std;
char *sam[] = { "Yes.", "No.", "in", "out", "FINISH" };

int main(){
	vector<int> count;  //记录火车进出
	stack<char> s;  
	int n, A, B, i;
	string a, b;  //现串和目标串
	while( cin >> n >> a >> b ){
		A = B = i = 0;
		while( B < n ){
			if( a[A] == b[B] ){
				count.push_back( 2 );
				count.push_back( 3 );
				++A;
				++B;
			}
			else if( !s.empty() && s.top() == b[B] ){
				s.pop();
				count.push_back( 3 );
				++B;
			}
			else if( A < n ){
				count.push_back( 2 );
				s.push( a[A] );
				++A;
			}
			else{
				i = 1;
				break;
			}
		}
		if( i )
			printf( "%s\n%s\n", sam[1], sam[4] );
		else{
			printf( "Yes.\n" );
			for( int i = 0; i != count.size(); ++i )
				printf( "%s\n", sam[ count[i] ] );
			printf( "FINISH\n" );
		}		
		count.clear();
		while( !s.empty() )
			s.pop();
	}		
	return 0;
}