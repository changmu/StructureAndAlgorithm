////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: 长木
////Run ID: 
////Submit time: 2014-12-17 22:12:12
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2222
////Problem Title: 
////Run result: Accept
////Run time:327MS
////Run memory:28424KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <queue>
using std::queue;

#define maxn 500010

char buf[52], str[1000010];

struct Trie {
    int ch[maxn][26];
    int val[maxn], sz, ret;

    void clear() { 
        memset(ch[0], 0, sizeof(ch[0])); 
        sz = 1; val[0] = ret = 0; 
    }
    int idx(char ch) { return ch - 'a'; }

    void insert(const char *str) {
        int i, u = 0, c, len = strlen(str);
        for (i = 0; i < len; ++i) {
            c = idx(str[i]);
            if (!ch[u][c]) {
                memset(ch[sz], 0, sizeof(ch[sz]));
                val[sz] = 0; ch[u][c] = sz++;
            }
            u = ch[u][c];
        }
        ++val[u];
    }

    int f[maxn], last[maxn];
    void getFail() {
        queue<int> Q;
        last[0] = f[0] = 0;
        for (int c = 0; c < 26; ++c) {
            int u = ch[0][c];
            if(u) {
                f[u] = last[u] = 0;
                Q.push(u);
            }
        }
        while (!Q.empty()) {
            int u = Q.front(); Q.pop();
            for (int c = 0; c < 26; ++c) {
                int v = ch[u][c];
                if(!v) {
                    ch[u][c] = ch[f[u]][c]; // 优化版本 
                    continue;
                }
                Q.push(v);
                int x = f[u];
                while (x && !ch[x][c]) x = f[x];
                f[v] = ch[x][c];
                last[v] = val[f[v]] ? f[v] : last[f[v]];
            }
        }
    }

    int find(char *str) {
        int len = strlen(str);
        int j = 0;
        for (int i = 0; i < len; ++i) {
            int c = idx(str[i]);
            // while (j && !ch[j][c]) j = f[j];
            j = ch[j][c];
            if (val[j]) Add(j);
            else if (last[j]) Add(last[j]);
        }
        return ret;
    }

    void Add(int x) {
        if(!x) return;
        ret += val[x];
        val[x] = 0;
        Add(last[x]);
    }
} AC;

int main() {
    // freopen("stdin.txt", "r", stdin);
    int T, N;
    scanf("%d", &T);
    while (T--) {
        AC.clear();
        scanf("%d", &N);
        while (N--) {
            scanf("%s", buf);
            AC.insert(buf);
        }
        AC.getFail();
        scanf("%s", str);
        printf("%d\n", AC.find(str));
    }
    return 0;
}