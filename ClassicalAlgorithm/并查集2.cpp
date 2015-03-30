/************************************************************* 
 * 并查集：
 * 有N个人，他们分别属于两大组织A/B， 现在有M条信息：
 * D(x, y) 表示x、y属于不同的组织， A(x, y) 回答x、y是否属于
 * 同一个组织.
 *************************************************************/ 
#include <stdio.h>
#include <string.h>

const int maxn = 100005;
int pre[maxn<<1];
int N, M;

int uFind(int x) {
    return pre[x] ? pre[x] = uFind(pre[x]) : x;
}

bool same(int x, int y) {
    return uFind(x) == uFind(y);
}

bool unite(int x, int y) {
    x = uFind(x);
    y = uFind(y);
    if (x == y) return false;
    pre[x] = y; return true;
}

int main() {
    int T, x, y;
    char ch[2];

    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &N, &M);

        memset(pre, 0, sizeof(pre));

        while (M--) {
            scanf("%s%d%d", ch, &x, &y);
            if (*ch == 'D') {
                unite(x, y + N);        // 同时维护两棵互不相连的树
                unite(x + N, y);
            } else {
                if (same(x, y))
                    puts("In the same gang.");
                else if (same(x, y + N))
                    puts("In different gangs.");
                else
                    puts("Not sure yet.");
            }
        }
    }
    return 0;
}
