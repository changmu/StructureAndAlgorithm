////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-17 09:32:08
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2054
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:268KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#define maxn 20000

char s1[maxn], s2[maxn], buf[maxn];
int len1, len2;

void stripTrail(char str[], int len){
    while(str[--len] == '0') str[len] = '\0';
    if(str[len] == '.') str[len--] = '\0';
    if(len < 0) str[0] = '0';
}

void stripHead(char str[], int len)
{
    int a = 0;
    if(str[0] == '-' || str[0] == '+') ++a;
    while(a < len && str[a] == '0')
        ++a;
    if(a == len){
        str[0] = '0'; str[1] = '\0'; return;
    }
    int i = 0;
    while(a <= len) str[i++] = str[a++];
}

int main()
{
    int sign1, sign2;
    while(scanf("%s%s", s1, s2) == 2){
        len1 = strlen(s1);
        len2 = strlen(s2);
        sign1 = sign2 = 0;
        if(s1[0] == '-') sign1 = 1;
        if(s2[0] == '-') sign2 = 1;
        if(strchr(s1, '.')) stripTrail(s1, len1);
        if(strchr(s2, '.')) stripTrail(s2, len2);
        stripHead(s1, len1 = strlen(s1));
        stripHead(s2, len2 = strlen(s2));
        if(strcmp(s1, s2) == 0){
            if(sign1 == sign2) puts("YES");
            else if(s1[0] == '0') puts("YES");
            else puts("NO");
        }else puts("NO");
    }
    return 0;
}