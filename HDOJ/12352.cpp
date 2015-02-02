////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-28 09:52:23
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1235
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:232KB
//////////////////System Comment End//////////////////
//not mine
#include<stdio.h>
#define MAX 1000
int arr[MAX+5] ;
int main()
{
	int n,i,m,count;
	while(scanf("%d",&n),n)
	{
		for(i=0;i<n;i++)
			scanf("%d",arr+i);
	    	scanf("%d",&m);
			count=0;
		for(i=0;i<n;i++)
		{
			if(m==arr[i])count++;
		}
		printf("%d\n",count);

	}
	return 0;
}