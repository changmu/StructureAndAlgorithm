#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string ret;
        int carry = 0;

        for (auto i = a.rbegin(), j = b.rbegin(); i != a.rend() || j != b.rend(); ) {
            ret += (i == a.rend() ? '0' : *i++) + (j == b.rend() ? '0' : *j++) + carry - '0';
            carry = 0;

            if (ret.back() >= '2') {
                ret.back() -= 2;
                carry = 1;
            }
        }
        if (carry) ret.append(1, '1');
        reverse(ret.begin(), ret.end());

        return ret;
    }
};

int main()
{
    Solution ac;
    string str1, str2;
    while (cin >> str1 >> str2) {
        cout << ac.addBinary(str1, str2) << endl;
    }
    return 0;
}
