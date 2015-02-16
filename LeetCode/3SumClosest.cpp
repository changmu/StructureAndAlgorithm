/*************************************************************
 * Given an array S of n integers, find three integers in S such that 
 * the sum is closest to a given number, target. Return the sum of the 
 * three integers. You may assume that each input would have exactly one solution.
 * 
 * For example, given array S = {-1 2 1 -4}, and target = 1.
 * 
 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 *************************************************************/ 
class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        int result = num[0] + num[1] + num[2];
        auto last = num.end();

        for (auto i = num.begin(); i < last - 2; ++i) {
            auto j = i + 1;
            auto k = last - 1;
            while (j < k) {
                int sum = *i + *j + *k;
                if (abs(sum - target) < abs(result - target))
                    result = sum;

                if (sum < target) ++j;
                else if (sum > target) --k;
                else return target;
            }
        }

        return result;
    }
};
