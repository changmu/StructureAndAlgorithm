class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        return addDigit(digits, 1);       
    }

private:
    vector<int>& addDigit(vector<int> &digits, int digit) {
        int c = digit;
        for (auto i = digits.rbegin(); i != digits.rend(); ++i) {
            *i += c;
            c = *i / 10;
            *i %= 10;
        }

        if (c != 0) digits.insert(digits.begin(), 1);

        return digits;
    }
};
