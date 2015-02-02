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
    str[j++] = '?'; // 必须跟其余字符不一样，否则可能造成越界
    while(buf[i]) {
        str[j++] = buf[i++];
        str[j++] = '.';
    }
    str[j++] = '#'; // 同防越界
    str[j] = '\0';
    strEnd = j;
}

int Manacher() {
    /* 
    ** i表示字符串当前对称中心下标
    ** j表示覆盖半径，k表示到对称中心的距离
    */
    int i, j, k, len = 0;
    for(i = 1, j = 0; i != strEnd; ) {
        // 延长半径
        while(str[i-(j+1)] == str[i+(j+1)]) ++j;
        rad[i] = j;
        // 更新当前回文子串中有效字符长度
        if(isalpha(str[i-j])) len = max(len, j + 1);
        else len = max(len, j);
        /* 
        ** 根据当前已确定的对称中心和半径向右更新rad值
        ** 有两种情况：1、rad[i-k] != rad[i] - k 此时
        ** rad[i+k] = min(rad[i-k], rad[i] - k);
        ** 2、rad[i-k] == rad[i] - k 此时rad[i+k]的值
        ** 至少为rad[i-k]也就是j - k，所以下一步i就需要
        ** 跳到i + k的位置在覆盖半径为j - k的基础上进行
        ** 更新。
        */
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