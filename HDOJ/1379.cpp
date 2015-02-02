////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-04-15 11:32:15
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1379
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:396KB
//////////////////System Comment End//////////////////
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

struct Node{
	string str;
	int val;
};

int cmp(Node a, Node b){
	return a.val < b.val;
}

int main(){
	int n, m, i, val, t;
	vector<Node> vec;	
	string str;
	Node temp;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		for(i = 0; i < m; ++i){
			cin >> str;
			
			val = 0; //ÇóÄæÐòÊý
			for(int j = 0; j < str.size(); ++j)
				for(int k = j + 1; k < str.size(); ++k)
					if(str[k] < str[j]) ++val;				
			
			temp.val = val;
			temp.str = str;
			vec.push_back(temp);
		}
		
		stable_sort(vec.begin(), vec.end(), cmp);
		
		for(i = 0; i < vec.size(); ++i)
			cout << vec[i].str << endl;
		
		vec.clear();
	}
	return 0;
}