class Solution {
public:
    int climbStairs(int n) {
        int a = 0, b = 1;
        for (int i = 0; i < n; ++i) {
            a += b;
            swap(a, b);
        }
        return b;
    }
};
