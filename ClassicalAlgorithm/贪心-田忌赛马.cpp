/*************************************************************
 * 田忌赛马：若tian能赢，则用最小代价赢，若赢不了就让king付出最大
 * 代价。
 *************************************************************/ 
#include <stdio.h>
#include <string.h>

const int maxn = 1010;
int king[maxn], tian[maxn];
int N;

void quickSort(int *A, int L, int R) {
    if (R <= L) return;

    int key = A[L], u = L, v = R;
    while (L < R) {
        while (L < R && A[R] >= key) --R;
        A[L] = A[R];
        while (L < R && A[L] <= key) ++L;
        A[R] = A[L];
    }
    A[L] = key;

    quickSort(A, u, L - 1);
    quickSort(A, L + 1, v);
}

int greedy() {
    int cnt = 0;
    int kh = N, kl = 1;
    int th = N, tl = 1;

    while (tl <= th) {
        if (tian[tl] < king[kl]) {
            ++tl;
            --kh;
            --cnt;
        } else if (tian[tl] > king[kl]) {
            ++tl;
            ++kl;
            ++cnt;
        } else {
            if (tian[th] > king[kh]) {
                --th;
                --kh;
                ++cnt;
            } else if (tian[th] < king[kh]) {
                ++tl;
                --kh;
                --cnt;
            } else {
                if (tian[tl] == tian[th])
                    return cnt;
                ++tl;
                --kh;
                --cnt;
            }
        }
    }

    return cnt;
}

int main() {
    while (scanf("%d", &N), N) {
        for (int i = 1; i <= N; ++i)
            scanf("%d", tian + i);
        for (int i = 1; i <= N; ++i)
            scanf("%d", king + i);

        quickSort(tian, 1, N);
        quickSort(king, 1, N);

        printf("%d\n", greedy() * 200);
    }
    return 0;
}
