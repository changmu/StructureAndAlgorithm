class Solution {
public:
    int trap(int A[], int n) {
        if (n < 1) return 0;

        int *max_left = new int[n];
        int *max_right = new int[n];
        int result = 0;

        max_left[0] = A[0];
        max_right[n - 1] = A[n - 1];
        for (int i = 1; i < n; ++i) {
            max_left[i] = max(A[i], max_left[i - 1]);
            max_right[n - i - 1] = max(A[n - i - 1], max_right[n - i]);
        }

        for (int i = 0; i < n; ++i) {
            result += min(max_left[i], max_right[i]) - A[i];
        }

        delete[] max_right;
        delete[] max_left;

        return result;
    }
};
