////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-11-07 21:44:59
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2020
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int arr[105];

bool cmp(int a, int b) {
    return abs(a) > abs(b);
}

int main() {
    int n, i;
    while(scanf("%d", &n), n) {
        for(i = 0; i < n; ++i)
            scanf("%d", &arr[i]);
        sort(arr, arr + n, cmp);
        for(i = 0; i < n; ++i)
            if(i != n - 1) printf("%d ", arr[i]);
            else printf("%d\n", arr[i]);
    }
}