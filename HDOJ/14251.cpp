////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-17 17:46:29
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1425
////Problem Title: 
////Run result: Accept
////Run time:671MS
////Run memory:2224KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <algorithm>
#define maxn 1000002
using namespace std;

int arr[maxn];

bool cmp(int a, int b){
    return a > b;
}

int main()
{
    int n, m, i;
    while(scanf("%d%d", &n, &m) == 2){
        for(i = 0; i < n; ++i)
            scanf("%d", &arr[i]);
        sort(arr, arr + n, cmp);
        for(i = 0; i < m; ++i)
            if(i != m - 1) printf("%d ", arr[i]);
            else printf("%d\n", arr[i]);
    }
    return 0;
}