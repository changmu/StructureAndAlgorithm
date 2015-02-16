/************************************************************* 
 * Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 * You are given a target value to search. If found in the array return its index, otherwise return -1.
 * You may assume no duplicate exists in the array.
 *************************************************************/ 
class Solution {
public:
    int search(int A[], int n, int target) {
        int left = 0, right = n - 1;

        while (left <= right) {
            int mid = left + right >> 1;
            if (target == A[mid]) return mid;

            if (A[mid] >= A[left]) {
                if (target < A[mid] && target >= A[left]) right = mid - 1;
                else left = mid + 1;
            } else {
                if (target > A[mid] && target <= A[right]) left = mid + 1;
                else right = mid - 1;
            }
        }

        return -1;
    }
};
