////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-01-27 12:13:02
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2031
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:384KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <stack>
using namespace std;

int main(){
	int N, R, t, sign;
	stack<char> sta;
	while(cin >> N >> R){
		sign = 0;
		if(N < 0)
			sign = 1, N = -N;
		else if(N == 0)
			cout << '0';
		while(N){
			t = N % R;
			switch(t){
				case 10: t = 'A'; break;
				case 11: t = 'B'; break;
				case 12: t = 'C'; break;
				case 13: t = 'D'; break;
				case 14: t = 'E'; break;
				case 15: t = 'F'; break;
				default: t += '0';
			}
			sta.push(t);
			N /= R;
		}
		if(sign) cout << '-';
		while(!sta.empty()){
			cout << sta.top();
			sta.pop();
		}
		cout << endl;
	}
	return 0;
}