////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: 长木
////Run ID: 
////Submit time: 2015-01-19 00:06:40
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2062
////Problem Title: 
////Run result: Accept
////Run time:124MS
////Run memory:1216KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<iostream>
#define LL long long int
using namespace std;
int main(){
    int n,a[21],i;
    LL m,t;
    LL p[21]={0,1};
    for(i=2;i<=20;i++){
        p[i]=p[i-1]*(i-1)+1;//0、1、2、5、16
    }
    while(cin>>n>>m){
        for(i=0;i<=20;i++)
            a[i]=i;
        while(n--&&m){
            t=m/p[n+1]+((m%p[n+1])?1:0);
            cout<<a[t];//当前的首数字
            for(i=t;i<=n;i++)
                a[i]=a[i+1];//回到n-1个数字，更新输出数组
            m-=((t-1)*p[i]+1);//去掉前面的小于t开头的组合，且将去掉一个仅有t的集合
            printf(m==0?"\n":" ");
        }
    }
    return 0;
}