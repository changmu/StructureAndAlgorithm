////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-07-26 16:13:59
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1709
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:260KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxn 10002

int arr[102], store[maxn];
bool c1[maxn], c2[maxn];

int main()
{
    int n, i, j, k, sum, count;
    while(scanf("%d", &n) != EOF){
        memset(c1, 0, sizeof(c1));
        memset(c2, 0, sizeof(c2));
        for(i = sum = 0; i < n; ++i)
            scanf("%d", arr + i);
        c1[0] = c1[sum = arr[0]] = 1;
        for(i = 1; i < n; ++i){
            for(j = 0; j <= sum; ++j)
                for(k = 0; k <= arr[i]; k += arr[i]){
                    c2[k + j] += c1[j];
                    c2[abs(k - j)] += c1[j];
                }
            sum += arr[i];
            for(k = 0; k <= sum; ++k){
                c1[k] = c2[k]; c2[k] = 0;
            }
        }
        for(count = 0, i = 1; i <= sum; ++i){
            if(!c1[i]) store[count++] = i;
        }
        printf("%d\n", count);
        if(count) 
            for(i = 0; i < count; ++i)
                if(i != count - 1) printf("%d ", store[i]);
                else printf("%d\n", store[i]);
    }
    return 0;
}