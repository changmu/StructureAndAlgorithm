////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-01-23 22:43:21
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1228
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:392KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

char *p[] = { "zero", "one", "two", "three", "four", "five", 
			  "six", "seven", "eight", "nine", "+", "=" };
			  
int main(){
	int a , b;
	string str;
	while( 1 ){
		a = b = 0;
		while( cin >> str && str != p[10] )
			for( int m = 0; m != 10; ++m )
				if( p[m] == str )
					a = a * 10 + m;
		while( cin >> str && str != p[11] )
                for( int m = 0; m != 10; ++m )
                    if( p[m] == str )
                        b = b * 10 + m;
        if( a == 0 && b == 0 )
            break;
        cout << a + b << endl;        
	}
	return 0;
}