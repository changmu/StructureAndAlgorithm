#include <iostream>
#include <memory>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    const static int occur = 1;
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= occur) return nums.size();

        int index = occur;
        for (int i = occur; i < nums.size(); ++i) {
            if (nums[i] != nums[index - occur])
                nums[index++] = nums[i];
        }
        return index;
    }
};

int main()
{
    Solution s;
    int tmp;
    vector<int> nums;
    cout << "input nums: \n";
    while (cin >> tmp) {
        nums.push_back(tmp);
    }
    cout << s.removeDuplicates(nums) << endl;
    return 0;
}
