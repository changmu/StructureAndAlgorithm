////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-12-16 22:25:03
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1247
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:6732KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>

#define maxn 1000000

char str[50], str1[50], str2[50], dic[50002][50];
struct Trie {
    int ch[maxn][26];
    int val[maxn], sz;

    Trie() {
        memset(ch[0], 0, sizeof(ch[0]));
        sz = 1;
    }
    int idx(char ch) { return ch - 'a'; };
    void insert(const char *str) {
        int u = 0, i, id, len = strlen(str);
        for (i = 0; i < len; ++i) {
            id = idx(str[i]);
            if (!ch[u][id]) {
                memset(ch[sz], 0, sizeof(ch[sz]));
                ch[u][id] = sz;
                val[sz++] = 0;
            }
            u = ch[u][id];
        }
        val[u] = 1;
    }
    bool find(const char *str) {
        int u = 0, i, id, len = strlen(str);
        for (i = 0; i < len; ++i) {
            id = idx(str[i]);
            if(!ch[u][id]) return false;
            u = ch[u][id];
        }
        return val[u];
    }
} T;

int main() {
    // freopen("stdin.txt", "r", stdin);
    int id = 0, i, j, len;
    while (scanf("%s", str) == 1) {
        T.insert(str);
        strcpy(dic[id++], str);
    }
    for (i = 0; i < id; ++i) {
        len = strlen(dic[i]);
        for (j = 1; j < len; ++j) {
            strncpy(str1, dic[i], j);
            strncpy(str2, dic[i] + j, len - j);
            str1[j] = '\0';
            str2[len-j] = '\0';
            if (T.find(str1) && T.find(str2)) {
                puts(dic[i]); break;
            }
        }
    }
    return 0;
}