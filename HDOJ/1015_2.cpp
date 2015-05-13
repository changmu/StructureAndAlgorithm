#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 20;
char buf[maxn], str[maxn];
int tar, len, vis[30];

bool DFS(int k)
{
    if (k == 5) {
        auto f = [](int x, int n) {
            int ret = x;
            while (--n) ret *= x;
            return ret;
        };
        return (str[0] - 'A' + 1) - f(str[1] - 'A' + 1, 2) + f(str[2] - 'A' + 1, 3)
            - f(str[3] - 'A' + 1, 4) + f(str[4] - 'A' + 1, 5) == tar;
    };

    int i, j;
    for (i = 0; i < len; ++i) {
        if (!vis[buf[i] - 'A']) {
            str[k] = buf[i];
            vis[buf[i] - 'A'] = true;
            if (DFS(k + 1)) return true;
            vis[buf[i] - 'A'] = false;
        }
    }
    return false;
}

int main()
{
    while (~scanf("%d%s", &tar, buf)) {
        if (tar == 0 && !strcmp(buf, "END"))
            break;
        memset(vis, 0, sizeof(vis));
        len = strlen(buf);
        sort(buf, buf + len, [](char a, char b) { return a > b; });
        if (DFS(0)) puts(str);
        else puts("no solution");
    }
    return 0;
}
