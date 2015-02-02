////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-01-27 11:25:50
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2030
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:392KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <string>
using namespace std;

int main(){
	int n, s;
	string str;
	cin >> n;
	getchar();
	while(n--){
		s = 0;
		getline(cin, str);
		for(int i = 0; i != str.size(); ++i)
			if(str[i] < 0)
				++s;
		cout << s / 2 << endl;
	}
	return 0;
}