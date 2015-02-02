////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-12-16 21:21:21
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1251
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:40256KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>

#define maxNode 1000000

char str[12];
struct Trie {
    int ch[maxNode][26];
    int val[maxNode], sz;

    Trie() {
        memset(ch[0], 0, sizeof(ch[0]));
        sz = 1;
    }
    int idx(char ch) { return ch - 'a'; }
    void insert(char *str) {
        int u = 0, id, i, len = strlen(str);
        for (i = 0; i < len; ++i) {
            id = idx(str[i]);
            if (!ch[u][id]) {
                memset(ch[sz], 0, sizeof(ch[sz]));
                val[sz] = 0;
                ch[u][id] = sz++;
            }
            u = ch[u][id];
            ++val[u];
        }
    }
    int find(char *str) {
        int u = 0, id, i, len = strlen(str);
        for (i = 0; i < len; ++i) {
            id = idx(str[i]);
            if (ch[u][id]) u = ch[u][id];
            else break;
        }
        return i == len ? val[u] : 0;
    }
} T;

int main() {
    // freopen("stdin.txt", "r", stdin);
    while(gets(str), *str)
        T.insert(str);
    while(gets(str))
        printf("%d\n", T.find(str));
    return 0;
}
