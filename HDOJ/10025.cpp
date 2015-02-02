////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-05-02 11:07:59
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1002
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:216KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
int sum[1005];
char a[1005], b[1005];

int findHead(){
    int i = 1005;
    while(sum[--i] == 0 && i > 0)
		;
    return i;
}

int main(){
    int t, i, lena, lenb, id, jin, j;
    scanf("%d", &t);
    for(i = 1; i <= t; ++i){
        scanf("%s%s", a, b);
        printf("Case %d:\n", i);
        printf("%s + %s = ", a, b);
        lena = strlen(a) - 1;
        lenb = strlen(b) - 1;
        id = 0;
        memset(sum, 0, sizeof(sum));
        while(lena >= 0 && lenb >= 0){
            sum[id++] = a[lena--] - '0' + b[lenb--] - '0';
        }
        while(lena >= 0) sum[id++] = a[lena--] - '0';
        while(lenb >= 0) sum[id++] = b[lenb--] - '0';        
        
        for(j = 0; j <= id || sum[j]; ++j){            
            if(sum[j] > 9){
                sum[j+1] += 1;
                sum[j] -= 10;
            }
        }
        j = findHead();
        while(j >= 0) printf("%d", sum[j--]);
        printf("\n");
        if(i != t) printf("\n");
    }
    return 0;
}