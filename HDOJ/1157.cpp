////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-27 22:21:34
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1157
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:268KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <algorithm>
using std::sort;
#define maxn 10002

int arr[maxn];

int main()
{
    int n, i;
    while(scanf("%d", &n) == 1){
        for(i = 0; i < n; ++i)
            scanf("%d", &arr[i]);
        sort(arr, arr + n);
        printf("%d\n", arr[(n-1) >> 1]);
    }
    return 0;
}