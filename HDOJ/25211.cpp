////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: 长木
////Run ID: 
////Submit time: 2014-07-08 12:04:06
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2521
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:216KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <algorithm>
#define maxn 5000 + 2
using std::max_element;
int arr[maxn];
int main(){
    int t, a, b;
    for(a = 1; a < maxn; ++a) //这里要注意
        for(b = a; b < maxn; b += a)
            ++arr[b];
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &a, &b);
        printf("%d\n", max_element(arr + a, arr + b + 1) - arr);
    }
    return 0;
}