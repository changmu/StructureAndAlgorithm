/*
 * 矩阵快速幂求第N个斐波那契数， n <= 1e9, f1 = 1, f2 = 2
 * */
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

const int mod = 19999997;

struct MATRIX {
    unsigned long long m[2][2];
    MATRIX() {
        m[0][0] = m[1][1] = 1;
        m[0][1] = m[1][0] = 0;
    }
} Mat;

MATRIX mat_multiply(MATRIX m1, MATRIX m2)
{
    MATRIX ret;
    ret.m[0][0] = (m1.m[0][0] * m2.m[0][0] + m1.m[0][1] * m2.m[1][0]) % mod;
    ret.m[0][1] = (m1.m[0][0] * m2.m[0][1] + m1.m[0][1] * m2.m[1][1]) % mod;
    ret.m[1][0] = (m1.m[1][0] * m2.m[0][0] + m1.m[1][1] * m2.m[1][0]) % mod;
    ret.m[1][1] = (m1.m[1][0] * m2.m[0][1] + m1.m[1][1] * m2.m[1][1]) % mod;
    return ret;
}

MATRIX mat_quick_exp(MATRIX m, int k)
{
    MATRIX ret;
    for ( ; k; k >>= 1) {
        if (k & 1) ret = mat_multiply(ret, m);
        m = mat_multiply(m, m);
    }
    return ret;
}

int main()
{
    int N;
    cin >> N;
    MATRIX B;
    B.m[0][0] = 0;
    B.m[0][1] = B.m[1][0] = B.m[1][1] = 1;
    B = mat_quick_exp(B, N + 1);
    cout << B.m[1][0] << endl;
    return 0;
}
