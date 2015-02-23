class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        int total = 1 << n;
        result.reserve(total);

        for (int i = 0; i < total; ++i) {
            result.push_back(i ^ (i >> 1));
        }

        return result;
    }
};

// method 2
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        result.reserve(1 << n);

        result.push_back(0);
        for (int i = 0; i < n; ++i) {
            const int highest = 1 << i;
            for (auto j = result.rbegin(); j != result.rend(); ++j)
                result.push_back(highest | *j);
        }

        return result;
    }
};
