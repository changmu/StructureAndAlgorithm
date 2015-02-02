////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2015-01-15 20:35:13
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2093
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1136KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
	string name;
	int sol_num, time_use;
};
vector<Node> stu;

bool cmp(Node a, Node b) {
	if (a.sol_num == b.sol_num) {
		if (a.time_use == b.time_use)
			return a.name.compare(b.name) < 0;
		return a.time_use < b.time_use;
	}
	return a.sol_num > b.sol_num;
}

int main() {
	// freopen("stdin.txt", "r", stdin);
	string name, buf;
	Node tmp;
	int prob_num, time_pen, time_p, pos, tmp2, tmp3, sol_num;

	scanf("%d%d", &prob_num, &time_pen);
	while (cin >> name) {
		time_p = sol_num = 0;
		for (int i = 0; i < prob_num; ++i) {
			cin >> buf;
			if (buf[0] == '-' || buf[0] == '0') continue;
			sscanf(buf.c_str(), "%d", &tmp2);
			pos = buf.find('(');
			if (pos != string::npos) {
				sscanf(buf.c_str() + pos + 1, "%d", &tmp3);
				tmp2 += tmp3 * time_pen;
			}
			time_p += tmp2;
			++sol_num;
		}	
		tmp.name = name;
		tmp.sol_num = sol_num;
		tmp.time_use = time_p;
		stu.push_back(tmp);
	}
	sort(stu.begin(), stu.end(), cmp);
	for (vector<Node>::iterator it = stu.begin(); it != stu.end(); ++it) {
		printf("%-10s %2d %4d\n", (it->name).c_str(), it->sol_num, it->time_use);
	}
	return 0;
}
