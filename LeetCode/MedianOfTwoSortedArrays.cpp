/************************************************************* 
 * There are two sorted arrays A and B of size m and n respectively. 
 * Find the median of the two sorted arrays. 
 * The overall run time complexity should be O(log (m+n)).
 *************************************************************/ 
class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int k = m + n;
        if (k & 0x1) {
            k >>= 1;
            return findKthNum(A, m, B, n, k + 1);
        } else {
            k >>= 1;
            return (findKthNum(A, m, B, n, k) + findKthNum(A, m, B, n, k + 1)) / 2.0;
        }
    }

private:
    static int findKthNum(int A[], int m, int B[], int n, int k) {
        if (m > n) return findKthNum(B, n, A, m, k);
        if (m == 0) return B[k - 1];
        if (k == 1) return min(A[0], B[0]);

        int k1 = min(k >> 1, m), k2 = k - k1;
        if (A[k1 - 1] < B[k2 - 1])
            return findKthNum(A + k1, m - k1, B, n, k - k1);
        else if (A[k1 - 1] > B[k2 - 1])
            return findKthNum(A, m, B + k2, n - k2, k - k2);
        else return A[k1 - 1];
    }
};
