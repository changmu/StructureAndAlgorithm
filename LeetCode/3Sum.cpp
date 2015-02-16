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
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > result;
        if (num.size() < 3) return result;

        sort(num.begin(), num.end());
        auto last = num.end();

        for (auto i = num.begin(); i != last; ++i) {
            if (i != num.begin() && *i == *(i - 1)) 
                continue;
            else if (*i > 0) break;

            for (auto j = last - 1; j != i; --j) {
                if (j != last - 1 && *j == *(j + 1))
                    continue;
                else if (*j < 0) break;

                for (auto k = i + 1; k < j; ++k)
                    if (*i + *j + *k == 0) {
                        vector<int> vec;
                        vec.push_back(*i);
                        vec.push_back(*k);
                        vec.push_back(*j);
                        result.push_back(vec);
                        break;
                    }
            }
        }

        return result;
    }
};
