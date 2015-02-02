////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-09-12 23:15:03
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2023
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:260KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<string.h>
int main()
{
	int n,m,i,j,s,t;
	int a[55][8];
	while(scanf("%d%d",&n,&m)!=EOF)
	{

	memset(a,0,sizeof(a));
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
		scanf("%d",&a[i][j]);
	    }
	}
	for(j=0;j<m;j++)
	{
	    for(i=0;i<n;i++)
    	{
    	a[n][j]+=a[i][j];
    	}
    }
    for(i=0;i<n;i++)
        {
    	for(j=0;j<m;j++)
     	{
    	a[i][m]+=a[i][j];
    	}
    }
	t=0;
	for(i=0;i<n;i++)
	{
		s=0;
		for(j=0;j<m;j++)
		{
		if(a[i][j]*1.0>=(a[n][j]*1.0)/n) 
		s++;
	    }
		if(s==m)
		t++;
	} 
	printf("%.2lf",(a[0][m]*1.0)/m);
	for(i=1;i<n;i++)
	printf(" %.2lf",(a[i][m]*1.0)/m);
	printf("\n");
	printf("%.2lf",(a[n][0]*1.0)/n);
	for(i=1;i<m;i++)
	printf(" %.2lf",(a[n][i]*1.0)/n);
	printf("\n"); 
	printf("%d\n\n",t);
    }
    return 0;
}