////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: 长木
////Run ID: 
////Submit time: 2014-01-28 18:13:59
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2051
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:380KB
//////////////////System Comment End//////////////////
/*Bitset
	十进制转二进制*/
#include <iostream>
#include <stack>
using namespace std;

int main(){
	int n;
	stack<char> sta;
	while(cin >> n){
		while(n){
			if(n & 1) sta.push('1');
			else sta.push('0');
			n >>= 1;
		}
		while(!sta.empty()){
			putchar(sta.top());
			sta.pop();
		}
		cout << endl;
	}
	return 0;
}