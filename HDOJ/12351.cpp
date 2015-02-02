////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-28 09:50:00
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1235
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:200KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#define maxn 102

int arr[maxn];

int main()
{
    int n, m;
    while(scanf("%d", &n), n){
        memset(arr, 0, sizeof(arr));
        while(n--){
            scanf("%d", &m);
            ++arr[m];
        }
        scanf("%d", &m);
        printf("%d\n", arr[m]);
    }
    return 0;
}