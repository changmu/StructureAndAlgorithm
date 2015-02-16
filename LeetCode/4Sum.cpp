/*************************************************************
 * Given an array S of n integers, are there elements a, b, c, 
 * and d in S such that a + b + c + d = target? Find all unique
 * quadruplets in the array which gives the sum of target.
 * 
 * Note:
 * Elements in a quadruplet (a,b,c,d) must be in non-descending order. 
 *    (ie, a ¡Ü b ¡Ü c ¡Ü d)
 * The solution set must not contain duplicate quadruplets.
 *     For example, given array S = {1 0 -1 0 -2 2}, and target = 0.
 * 
 *     A solution set is:
 *     (-1,  0, 0, 1)
 *     (-2, -1, 1, 2)
 *     (-2,  0, 0, 2)
 *************************************************************/ 
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > result;
        if (num.size() < 4) return result;

        sort(num.begin(), num.end());
        typedef vector<int>::iterator Viter;
        Viter last = num.end();

        for (Viter i = num.begin(); i < last - 3; ++i) {
            if (i != num.begin() && *i == *(i - 1))
                continue;

            for (Viter j = i + 1; j < last - 2; ++j) {
                if (j - 1 > i && *(j - 1) == *j)
                    continue;

                Viter x = j + 1, y = last - 1;
                while (x < y) {
                    int sum = *i + *j + *x + *y;
                    if (sum == target) {
                        result.push_back({*i, *j, *x++, *y--});
                        while (x < y && *x == *(x - 1)) ++x;
                        while (x < y && *y == *(y + 1)) --y;
                    } else if (sum < target) ++x;
                    else --y;
                }
            }
        }

        return result;
    }
};
