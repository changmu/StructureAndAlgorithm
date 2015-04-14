#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int T, cas, i, L, N, ret;
    int pos, x, left, right;
    bool dir;

    scanf("%d", &T);
    for (cas = 1; cas <= T; ++cas) {
        priority_queue<int, vector<int>, greater<int> > PQ_min;
        priority_queue<int> PQ_max;
        ret = pos = 0;
        dir = true;     // to right

        scanf("%d%d", &L, &N);

        while (N--) {
            scanf("%d", &x);
            if (0 == x) {
                scanf("%d", &x);
                if (x <= pos) {
                    PQ_max.push(x);
                } else {
                    PQ_min.push(x);
                }
            } else {
                while (!PQ_min.empty() && PQ_min.top() <= pos) {
                    PQ_max.push(PQ_min.top());
                    PQ_min.pop();
                }
                while (!PQ_max.empty() && PQ_max.top() > pos) {
                    PQ_min.push(PQ_max.top());
                    PQ_max.pop();
                }

                if (!PQ_max.empty())
                    left = pos - PQ_max.top();
                else left = -1;

                if (!PQ_min.empty())
                    right = PQ_min.top() - pos;
                else right = -1;

                if (-1 == left || -1 == right) {
                    if (-1 == left && -1 == right)
                        continue;
                    else if (-1 == left) {
                        ret += right;
                        dir = true;
                        pos += right;
                        PQ_min.pop();
                    } else {
                        ret += left;
                        if (left != 0)
                            dir = false;    // to left
                        pos -= left;
                        PQ_max.pop();
                    }
                } else if (left < right || (left == right && dir == false)) {
                    ret += left;
                    if (left != 0)
                        dir = false;    // to left
                    pos -= left;
                    PQ_max.pop();
                } else if (left > right || (left == right && dir)) {
                    ret += right;
                    dir = true;
                    pos += right;
                    PQ_min.pop();
                }
            }
        }
        printf("Case %d: %d\n", cas, ret);
    }
    return 0;
}
