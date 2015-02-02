////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-09-22 08:22:59
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2161
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<math.h>
int prime(int n)
{
int i;
for(i=2;i*i<=n;i++)
{
if(n%i==0)
return 0;
}
return 1;
}
int main()
{
int n,count=0;
while(scanf("%d",&n)!=EOF,n > 0)
{
if(n==1||n==2)
{
printf("%d: no\n",++count);
continue;
}
if(prime(n))
printf("%d: yes\n",++count);
else
printf("%d: no\n",++count);
}
return 0;
}