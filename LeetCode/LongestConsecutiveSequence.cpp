/************************************************************* 
 * Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
 * 
 * For example, Given [100, 4, 200, 1, 3, 2],
 * The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
 * 
 * Your algorithm should run in O(n) complexity.
 *************************************************************/ 
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_map<int, bool> used;        
        for (auto i : num) used[i] = false;

        int longest = 0;
        for (auto i : num) {
            if (used[i]) continue;

            int length = 1;
            used[i] = true;

            for (int j = i + 1; used.find(j) != used.end(); ++j) {
                used[j] = true;
                ++length;
            }

            for (int j = i - 1; used.find(j) != used.end(); --j) {
                used[j] = true;
                ++length;
            }

            longest = max(longest, length);
        }

        return longest;
    }
};

int main()
{
    Solution sol;
    int a[] = {100, 4, 200, 1, 3, 2};
    vector<int> num(a, a + 6);
    printf("%d\n", sol.longestConsecutive(num));
    return 0;
}
