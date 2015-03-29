/************************************************************* 
 * 合法IP检测： 
 * 首先检测是否有非法字符， 
 * 然后检测点的数量， 
 * 最后检测是否有点在开头或结尾或有连续的点连在一起以及每个部分的位数及数值是否合法。
 *************************************************************/ 
#include <stdio.h>
#include <string.h>

const int maxn = 110;
char buf[maxn], buf2[maxn];

bool isValidChar(const char *str) {
    for (int i = 0; str[i]; ++i)
        if (str[i] != '.' && !(str[i] >= '0' && str[i] <= '9'))
            return false;
    return true;
}

int countDot(char * str) {
    int cnt = 0;
    for (int i = 0; str[i]; ++i)
        if (str[i] == '.') ++cnt;
    return cnt;
}

bool check(const char *str) {
    int digit = 0, id = 0, len;
    for (int i = 0; str[i]; ++i) {
        if (str[i] == '.') {
            buf2[id] = '\0';
            if (*buf2 == '\0') return false;    // two '.' connected or begin with '.'
            else if ((len = strlen(buf2)) > 1 && *buf2 == '0' || len > 3)
                return false;                   // .012.
            else if (digit > 255) return false;
            digit = id = 0;
        } else {
            digit = digit * 10 + str[i] - '0';
            buf2[id++] = str[i];
        }
    }

    return true;
}

int main() {
    while (gets(buf)) {
        int len = strlen(buf);
        buf[len++] = '.';       // Easy to handle
        buf[len] = '\0';        
        if (!isValidChar(buf) || countDot(buf) != 4 || !check(buf))
            puts("NO");
        else puts("YES");
    }
    return 0;
}
