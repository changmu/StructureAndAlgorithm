#include <iostream>
#include <memory>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        int index = 0;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[index] != nums[i]) {
                nums[++index] = nums[i];
            }
        }
        return index + 1;
    }
};

int main()
{
    vector<int> nums = {1, 1, 2};
    Solution s;
    cout << s.removeDuplicates(nums) << endl;
    return 0;
}
