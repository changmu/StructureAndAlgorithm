/*************************************************************
 * The set [1,2,3,бн,n] contains a total of n! unique permutations.
 * 
 * By listing and labeling all of the permutations in order,
 * We get the following sequence (ie, for n = 3):
 * 
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 * Given n and k, return the kth permutation sequence.
 * 
 * Note: Given n will be between 1 and 9 inclusive.
 *************************************************************/ 
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        int fac[10] = {1, 1};
        bool vis[10] = {false};
        if (n == 1) return "1";
        int j, x;

        for (int i = 2; i < 10; ++i) fac[i] = i * fac[i - 1];
        string result;

        for (int i = 1; i <= n; ++i) {
            j = (k - 1) / fac[n - i] + 1;
            k -= (j - 1) * fac[n - i];

            for (x = 1; x <= n; ++x)
                if (!vis[x] && !--j) break;

            vis[x] = true;
            result += '0' + x;
        }

        return result;
    }
};

int main()
{
    Solution sol;
    int n, k;
    while (cin >> n >> k) {
        cout << sol.getPermutation(n, k) << endl;
    }
    return 0;
}
