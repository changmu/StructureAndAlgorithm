/*************************************************************
 * Given an array S of n integers, are there elements a, b, c in S
 * such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
 * 
 * Note:
 * Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ¡Ü b ¡Ü c)
 * The solution set must not contain duplicate triplets.
 * For example, given array S = {-1 0 1 2 -1 -4},
 * 
 * A solution set is:
 * (-1, 0, 1)
 * (-1, -1, 2) 
 *************************************************************/ 
class Solution { // 62ms
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > result;
        if (num.size() < 3) return result;

        sort(num.begin(), num.end());
        auto last = num.end();
        const int target = 0;

        for (auto i = num.begin(); i < last - 2; ++i) {
            if (i != num.begin() && *i == *(i - 1)) 
                continue;
            else if (*i > 0) break;

            auto j = i + 1;
            auto k = last - 1;
            while (j < k) {
                int tempSum = *i + *j + *k;

                if (tempSum == target) {
                    result.push_back({*i, *j++, *k--});

                    while (j < k && *j == *(j - 1)) ++j;
                } else if (tempSum < target) {
                    ++j;
                } else --k;
            }
        }

        return result;
    }
};
