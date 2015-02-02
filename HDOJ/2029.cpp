////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-01-27 11:08:09
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2029
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:384KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <string>
using namespace std;

int main(){
	int n, l, r;
	char ch;
	string str;
	cin >> n;
	while(n-- && cin >> str){
		l = 0; r = str.size() - 1;
		while(l <= r)
			if(str[l] == str[r])
				++l, --r;
			else break;
		if(l > r)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}