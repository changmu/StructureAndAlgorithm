/************************************************************* 
 * KMP: 求模式串在主串中出现的次数
 *************************************************************/ 
#include <stdio.h>
#include <string.h>

const int maxn = 10010;
const int maxm = 1000010;
char str1[maxn], str2[maxm];
int next[maxn];

void getNext(char *str) {
    int i = 0, j = -1;
    next[i] = j;

    while (str[i] != '\0') {
        if (j == -1 || str[i] == str[j]) {
//             next[++i] = ++j;
            ++i; ++j;
            if (str[i] == str[j]) next[i] = next[j];
            else next[i] = j;
        } else j = next[j];
    }
}

int KMP() {
    int cnt = 0, i = 0, j = 0;
    getNext(str1);

    while (str2[i] != '\0') {
        if (j == -1 || str1[j] == str2[i]) {
            if (++i, str1[++j] == '\0')
                ++cnt;
        } else j = next[j];
    }

    return cnt;
}

int main() {
    int N;
    scanf("%d", &N);
    while (N--) {
        scanf("%s%s", str1, str2);
        printf("%d\n", KMP());
    }
    return 0;
}
