void rotateCore(int a[], int L, int R) {
    int t;
    while (L < R) {
        t = a[L]; a[L] = a[R]; a[R] = t;
        ++L; --R;
    }
}

void rotate(int nums[], int n, int k) {
    if (nums == NULL || n < 1 || k < 1)
        return;
    k %= n;
    rotateCore(nums, 0, n - 1);
    rotateCore(nums, 0, k - 1);
    rotateCore(nums, k, n - 1);
}
