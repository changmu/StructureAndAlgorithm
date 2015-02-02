////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-09-11 19:42:36
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4981
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:236KB
//////////////////System Comment End//////////////////
//Corn
#include <stdio.h>
#include <algorithm>
#define maxn 1000 + 10
using namespace std;
int arr[maxn];
int main()
{
    int n,i;
    double mul,sum;
//    double ave;
    while(~scanf("%d",&n))
    {
        sum=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
            sum+=arr[i];
        }    
        sort(arr,arr+n);
        sum /= n;
        if((n & 1) == 0) --n;
        mul=arr[n/2];
//        ave=sum/n;
        
        if(sum>=mul)
        printf("NO\n");
        else
        printf("YES\n");
    }
    return 0;
}