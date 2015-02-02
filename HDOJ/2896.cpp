////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-12-18 00:38:17
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2896
////Problem Title: 
////Run result: Accept
////Run time:312MS
////Run memory:30124KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <queue>
#include <set>
using namespace std;

#define maxnode 100010

char str[10010];
set<int> st;
set<int>::iterator it;
int total;

struct Trie {
    int ch[maxnode][128], val[maxnode], sz;
    int f[maxnode], last[maxnode];

    Trie() {
        memset(ch[0], 0, sizeof(ch[0]));
        sz = 1; val[0] = 0;
    }

    void insert(const char *str, const int num) {
        int u = 0, v, c, i, len = strlen(str);
        for (i = 0; i < len; ++i) {
            v = ch[u][str[i]];
            if (!v) {
                memset(ch[sz], 0, sizeof(ch[sz]));
                val[sz] = 0; v = ch[u][str[i]] = sz++;
            }
            u = v;
        }
        val[u] = num;
    }

    void getFail() {
        int c, u, v, x;
        last[0] = f[0] = 0;
        queue<int> Q;
        for (c = 0; c < 128; ++c)
            if (v = ch[0][c]) {
                Q.push(v);
                f[v] = last[v] = 0;
            }
        while (!Q.empty()) {
            u = Q.front(); Q.pop();
            for (c = 0; c < 128; ++c) {
                v = ch[u][c];
                if (!v) {
                    ch[u][c] = ch[f[u]][c];
                    continue;
                }
                Q.push(v);
                x = f[u];
                while (x && !ch[x][c]) x = f[x];
                f[v] = ch[x][c];
                last[v] = val[f[v]] ? f[v] : last[f[v]];
            }
        }
    }

    void find(const char *str) {
        int i, j = 0, len = strlen(str);
        for (i = 0; i < len; ++i) {
            j = ch[j][str[i]];
            if (val[j]) update(j);
            else if (last[j]) update(last[j]);
        }
    }

    void update(int u) {
        if (u) {
            st.insert(val[u]);
            update(last[u]);
        }
    }
} AC;

int main() {
    // freopen("stdin.txt", "r", stdin);
    int N, M, i;
    scanf("%d", &N);
    for (i = 1; i <= N; ++i) {
        scanf("%s", str);
        AC.insert(str, i);
    }
    AC.getFail();

    scanf("%d", &M);
    for (i = 1; i <= M; ++i) {
        scanf("%s", str);
        AC.find(str);
        if (st.empty()) continue;
        printf("web %d:", i);
        for (it = st.begin(); it != st.end(); ++it)
            printf(" %d", *it);
        printf("\n");
        ++total; st.clear();
    }
    printf("total: %d\n", total);
    return 0;
}
