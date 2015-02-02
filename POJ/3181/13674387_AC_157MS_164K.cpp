#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

#define maxn 1002
typedef long long LL;
const LL UP = 1000000000000000000;

struct Node {
    LL u, v;
    Node(LL x = 0, LL y = 0) {
        u = x; v = y;
    }
    friend Node operator + (Node a, Node b) {
        a.u += b.u; a.v += b.v;
        if(a.v >= UP) {
            a.v -= UP; ++a.u;
        }
        return a;
    }
} c1[maxn], c2[maxn], a, b(0, 1);


int main() {
    int N, K, i, j, k;
    scanf("%d%d",&N, &K);
    c1[0] = b;
    for(i = 1; i <= K; ++i) {
        for(j = 0; j <= N; ++j)
            for(k = 0; k + j <= N; k += i)
                c2[j+k] = c2[j+k] + c1[j];
        for(j = 0; j <= N; ++j) {
            c1[j] = c2[j]; c2[j] = a;
        } 
    }
    if(c1[N].u)
        printf("%lld%017lld\n", c1[N].u, c1[N].v);
    else printf("%lld\n", c1[N].v);
    
    return 0;
}
