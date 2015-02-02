////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-04-19 16:08:36
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1073
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:376KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
	int t, pe, wa, sign;
	int sum0, sum1;
	string str, str0, str1;
	vector<string> vec[2];
	scanf("%d", &t);
	while(t--){
		sign = pe = wa = 0;
		while(getline(cin, str)){
			if(str.compare("END") == 0 && sign == 1) break;
			if(str.compare("END") == 0) { ++sign; continue; }
			if(str.compare("START") == 0) continue;
			
			vec[sign].push_back(str);
		}		
		
		str0 = str1 = "";
		
		for(int i = 0; i < vec[0].size(); ++i){
			if(vec[0][i].size() == 0) str0 += '\n';
			else for(int j = 0; j < vec[0][i].size(); ++j)
				str0 += vec[0][i][j];
		}
		for(int i = 0; i < vec[1].size(); ++i){
			if(vec[1][i].size() == 0) str1 += '\n';
			else for(int j = 0; j < vec[1][i].size(); ++j)
				str1 += vec[1][i][j];
		}
		
		if(str0.compare(str1)) pe = 1;
		int i, j;
		
		i = str0.find(' ');
		while(i != string::npos){
			str0.erase(i, 1);
			i = str0.find(' ', i - 1);
		}
		i = str0.find('\t');
		while(i != string::npos){
			str0.erase(i, 1);
			i = str0.find('\t', i - 1);
		}
		i = str0.find('\n');
		while(i != string::npos){
			str0.erase(i, 1);
			i = str0.find('\n', i - 1);
		}
		
		i = str1.find(' ');
		while(i != string::npos){
			str1.erase(i, 1);
			i = str1.find(' ', i - 1);
		}
		i = str1.find('\t');
		while(i != string::npos){
			str1.erase(i, 1);
			i = str1.find('\t', i - 1);
		}
		i = str1.find('\n');
		while(i != string::npos){
			str1.erase(i, 1);
			i = str1.find('\n', i - 1);
		}
		if(str0.compare(str1)) wa = 1;
		
		if(wa) printf("Wrong Answer\n");
		else if(pe) printf("Presentation Error\n");
		else printf("Accepted\n");	
		
		vec[0].clear();
		vec[1].clear();
	}
	return 0;
}
