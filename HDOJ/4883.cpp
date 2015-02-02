////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-07-27 22:05:07
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4883
////Problem Title: 
////Run result: Accept
////Run time:625MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define maxn 1500
using std::max_element;

int arr[maxn];

int main()
{
    int t, n, i, h, m, h2, m2, people, j;
    scanf("%d", &t);
    while(t--){
        memset(arr, 0, sizeof(arr));
        scanf("%d", &n);
        for(i = 0; i < n; ++i){
            scanf("%d %d:%d %d:%d", &people, &h, &m, &h2, &m2);
            m += h * 60; m2 += h2 * 60;
            for(j = m; j < m2; ++j) arr[j] += people;
        }
        printf("%d\n", *max_element(arr, arr + 1500));
    }
    return 0;
}