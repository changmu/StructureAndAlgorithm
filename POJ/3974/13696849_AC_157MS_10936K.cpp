#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cctype>
using namespace std;
typedef long long LL;

#define maxn 1000010

char buf[maxn], str[maxn<<1];
int strEnd, rad[maxn<<1];

/* 预处理：字符串首尾都是特殊字符，每两个字符间都插入一个相同的特殊字符 */
void prepro() {
    int i = 0, j = 0;
    str[j++] = '?';
    while(buf[i]) {
        str[j++] = buf[i++];
        str[j++] = '.';
    }
    str[j++] = '#';
    str[j] = '\0';
    strEnd = j;
}

int Manacher() {
    int i, j, k, len = 0;
    for(i = 1, j = 0; i != strEnd; ) {
        while(str[i-(j+1)] == str[i+(j+1)]) ++j;
        rad[i] = j;
        if(isalpha(str[i-j])) len = max(len, j + 1);
        else len = max(len, j);
        for(k = 1; k <= j && rad[i-k] != rad[i] - k; ++k)
            rad[i+k] = min(rad[i-k], rad[i] - k);
        i += k;
        j = max(0, j - k);
    }
    return len;
}

int main() {
    // freopen("stdin.txt", "r", stdin);
    int cas = 1;
    while(scanf("%s", buf), strcmp(buf, "END")) {
        prepro();
        printf("Case %d: %d\n", cas++, Manacher());
    }
    return 0;
}