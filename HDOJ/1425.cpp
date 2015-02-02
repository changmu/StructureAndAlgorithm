////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-17 17:42:27
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1425
////Problem Title: 
////Run result: Accept
////Run time:359MS
////Run memory:2220KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <algorithm>
#define maxn 1000002
using namespace std;

int arr[maxn];

int main()
{
    int n, m, i;
    while(scanf("%d%d", &n, &m) == 2){
        for(i = 0; i < n; ++i)
            scanf("%d", &arr[i]);
        make_heap(arr, arr + n);
        printf("%d", arr[0]);
        for(i = 0; i < m - 1; ++i){
            pop_heap(arr, arr + n - i);
            printf(" %d", arr[0]);
        }
        printf("\n");        
    }
    return 0;
}