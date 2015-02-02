////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-10-14 22:22:56
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4268
////Problem Title: 
////Run result: Accept
////Run time:906MS
////Run memory:1856KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <set>
#include <algorithm>
using namespace std;

#define maxn 100010
#define inf 0x7fffffff

struct Node {
    int x, y;
} A[maxn], B[maxn];
int n;

bool cmp(Node a, Node b) {
    return a.x < b.x;
}

int main() {
    int t, i, j, ans;
    scanf("%d", &t);
    while(t--) {
        multiset<int> mst;
        multiset<int>::iterator it;
        scanf("%d", &n);
        for(i = 0; i < n; ++i)
            scanf("%d%d", &A[i].x, &A[i].y);
        for(i = 0; i < n; ++i)
            scanf("%d%d", &B[i].x, &B[i].y);
        sort(A, A + n, cmp);
        sort(B, B + n, cmp);
        ans = 0;
        for(i = j = 0; i < n; ++i) {
            for( ; j < n && A[i].x >= B[j].x; ++j) {
                mst.insert(B[j].y);
            }
            if(mst.empty()) continue;
            it = mst.lower_bound(A[i].y);
            if(it == mst.end() || A[i].y < *it) {
                --it;
            }
            if(*it <= A[i].y) {
                ++ans; mst.erase(it);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}