#include <stdio.h>
#include <string.h>
char str[20];

int main()
{
    int t, n, a, b, len, i, jin;
    scanf("%d", &t);
    while(t--){
        scanf("%s", str);
        len = strlen(str);
        while(len > 1){
            --len;
            if(str[len] >= '5'){
                str[len] = '0'; ++str[len-1];
            }else str[len] = '0';
        }
        jin = 0;
        if(str[0] > '9') jin = 1, str[0] = '0';
        if(jin) putchar('1');
        puts(str);
    }
    return 0;
}