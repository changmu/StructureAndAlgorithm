#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <set>
#include <map>

#define maxn 1000005

int P[maxn];

int main() {
    int n, i, tar, s, ans, num;
    while(scanf("%d", &n) == 1) {
        std::set<int> st;
        std::map<int, int> mp;
        for(i = 0; i < n; ++i) {
            scanf("%d", &P[i]); // 知识点的范围未限定
            st.insert(P[i]);
        }
        tar = st.size();
        ans = n; num = 0;
        for(i = s = 0; i < n; ++i) {
            if(mp[P[i]]++ == 0) {
                ++num;
                while(num == tar) {
                    ans = std::min(ans, i - s + 1);
                    if(!--mp[P[s++]]) --num;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}