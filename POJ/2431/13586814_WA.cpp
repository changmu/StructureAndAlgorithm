#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>

#define maxn 10010

struct Node {
    int pos, val;
} A[maxn];

bool cmp(Node a, Node b) {
    return a.pos > b.pos;
}

int main() {
    // freopen("stdin.txt", "r", stdin);
    int N, L, P, i, cnt;
    while(scanf("%d", &N) == 1) {
        for(i = 0; i < N; ++i)
            scanf("%d%d", &A[i].pos, &A[i].val);
        scanf("%d%d", &L, &P);
        std::sort(A, A + N, cmp);

        std::priority_queue<int> pq;
        cnt = 0;

        for(i = 0; P < L && i < N; ++i) {
            if(L - A[i].pos <= P) {
                pq.push(A[i].val);
            } else if(!pq.empty()) {
                P += pq.top(); pq.pop();
                ++cnt; --i;
            } else if(pq.empty()) break;
        }
        // int k = 0;
        // while(k < N && L - A[k].pos <= P)
        //  pq.push(A[k++].val);
        // while(P < L && !pq.empty()){
        //  ++cnt;
        //  P += pq.top(); pq.pop();
        //  while(k < N && L - A[k].pos <= P)
        //      pq.push(A[k++].val);
        // }

        if(P < L) cnt = -1;
        printf("%d\n", cnt);
    }
    return 0;
}