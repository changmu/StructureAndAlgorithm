#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <set>

using namespace std;

const int maxn = 80;
char buf[maxn], str[3];
int len;
set<string> st;

int main()
{
    int i, j, k;
    bool flag;

    while (~scanf("%s", buf) && *buf != '*') {
        len = strlen(buf);
        flag = false;

        for (k = 1; k < len; ++k) {
            st.clear();
            for (i = 0; i + k < len; ++i) {
                str[0] = buf[i];
                str[1] = buf[i + k];
                // printf("%s..\n", str);
                if (st.find(str) != st.end()) {
                    flag = true;
                    break;
                } else st.insert(str);
            }
            if (flag) break;
        }

        printf("%s is%ssurprising.\n", buf, flag ? " NOT " : " ");
    }
    return 0;
}
