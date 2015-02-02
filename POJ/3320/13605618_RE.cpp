#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <set>

#define maxn 1000005

int P[maxn], vis[maxn];

int main() {
    int n, i, tar, s, ans, num;
    while(scanf("%d", &n) == 1) {
        std::set<int> st;
        for(i = 0; i < n; ++i) {
            scanf("%d", &P[i]);
            st.insert(P[i]);
            vis[i] = 0;
        }
        tar = st.size();
        ans = n; num = 0;
        for(i = s = 0; i < n; ++i) {
            if(vis[P[i]]++ == 0) {
                ++num;
                while(num == tar) {
                    ans = std::min(ans, i - s + 1);
                    if(!--vis[P[s++]])
                        --num;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}