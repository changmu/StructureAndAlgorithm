////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-07-26 16:56:35
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2072
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:372KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <set>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;

char str2[10000], *p;

int main()
{
    set<string> st;
    char str[1000];
    int count = 0;
    while(gets(str2)){
        if(!strcmp(str2, "#")) break;
        p = strtok(str2, " ");
        while(p){
        	sscanf(p, "%s", str);
        	if(!st.count(str)) st.insert(str);
        	p = strtok(NULL, " ");
        }
        cout << st.size() << endl;
        st.clear();
    }
    return 0;
}
