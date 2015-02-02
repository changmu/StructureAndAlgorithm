////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-09-23 11:33:44
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2137
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#define maxn 100

char str[maxn];

void putBackspace(int n) {
    while(n--) putchar(' ');
}

void rotate(int cent, int n) {
    switch(n) {
        case 0:
        puts(str); return;
        case 1:
        for(int i = cent << 1, j = cent << 1; i >= 0; --j) {
            putBackspace(i--);
            printf("%c\n", str[j]);
        } return;
        case 2:
        for(int j = cent << 1; j >= 0; --j) {
            putBackspace(cent);
            printf("%c\n", str[j]);
        } return;
        case 3:
        for(int j = cent << 1, i = 0; j >= 0; --j) {
            putBackspace(i++);
            printf("%c\n", str[j]);
        } return;
        case 4:
        for(int j = cent << 1; j >= 0; --j) {
            printf("%c", str[j]);            
        } putchar('\n'); return;
        case 5:
        for(int j = 0, i = cent << 1; i >= 0; ++j) {
            putBackspace(i--);
            printf("%c\n", str[j]);
        } return;
        case 6:
        for(int j = 0; j <= cent << 1; ++j) {
            putBackspace(cent);
            printf("%c\n", str[j]);
        } return;
        case 7:
        for(int j = 0, i = 0; j <= cent << 1; ++j) {
            putBackspace(i++);
            printf("%c\n", str[j]);
        } return;
    }
}

int main() {
    int n, i, cent;
    while(scanf("%s%d", str, &n) != EOF) {
        cent = strlen(str) >> 1;
        n = (n % 8 + 8) % 8;
        rotate(cent, n);
    }
    return 0;
}