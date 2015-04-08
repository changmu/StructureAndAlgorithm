/*
 * 二分各种情况总结
 * */
// 1> 准确找到值为K的任意一个位置，若没有则返回-1
int binary_search(int k) {
    // initialize
    while (L < R) {
        mid = L + R >> 1;
        if (A[mid] < k)
            L = mid + 1;
        else (A[mid] > k)
            R = mid;
        else return L;
    }

    return -1;
}

// 2> 找到第一个>=k的位置，假设数组外界无穷大
int lower_bound(int k) {
    // initialize
    while (L < R) {
        mid = L + R >> 1;
        if (A[mid] < k)
            L = mid + 1;
        else R = mid;
    }

    return L;
}
// 3> 找到第一个>k的位置，假设数组外界无穷大
int upper_bound(int k) {
    // initialize
    while (L < R) {
        mid = L + R >> 1;
        if (A[mid] <= k)
            L = mid + 1;
        else R = mid;
    }

    return L;
}


/************************************************************* 
 * 排序 + 二分
 * 有N个数，取出里面每两个数的绝对值组合成m个绝对值，等价于
 * 已知m个数里的最大值和最小值，找出第m/2小个数.
 *************************************************************/ 
#include <stdio.h>
#include <string.h>

const int maxn = 1e5;
int raw_number[maxn], N, MID;

void quick_sort(int *A, int L, int R) {
    if (R <= L) return;

    int key = A[L], u = L, v = R;
    while (L < R) {
        while (L < R && A[R] >= key) --R;
        A[L] = A[R];
        while (L < R && A[L] <= key) ++L;
        A[R] = A[L];
    }
    A[L] = key;

    quick_sort(A, u, L - 1);
    quick_sort(A, L + 1, v);
}

int lower_bound(int *A, int N, int elem) {      // 返回<=elem的元素个数
    int left = 0, right = N - 1, mid;
    while (left <= right) {
        mid = left + right >> 1;
        if (A[mid] <= elem) left = mid + 1;
        else right = mid - 1;
    }

    return left;
}

int binary_search_ans(int *A, int N, int ans) {
    int count = 0, i;
    for (i = 0; i < N; ++i)
        count += lower_bound(A + i + 1, N - 1 - i, A[i] + ans);
    return count;
}

int main() {
    int left, mid, right;

    while (~scanf("%d", &N)) {
        for (int i = 0; i < N; ++i)
            scanf("%d", raw_number + i);

        quick_sort(raw_number, 0, N - 1);

        MID = N * (N-1) / 2;
        if (MID & 1) ++MID;
        MID >>= 1;

        left = 0;
        right = raw_number[N-1] - raw_number[0];

        while (left <= right) {    // 二分答案
            mid = left + right >> 1;
            if (binary_search_ans(raw_number, N, mid) < MID) {
                left = mid + 1;
            } else right = mid - 1;
        }

        printf("%d\n", left);
    }
    return 0;
}
