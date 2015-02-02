////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-12-09 09:32:37
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1282
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1092KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<string.h>
int num[2014];
int main()
{
      int flag,n,count,i,id,temp;
      char a[10],b[10];
      while(scanf("%d",&n)==1)
       {
              count=0;
              flag=1;
              id=0;
              while(flag)
              {
                   num[id++]=n;
                   sprintf(a,"%d",n);
                   strcpy(b,a);
                   strrev(b);
                   if(strcmp(a,b)==0) flag=0;
                   else
                   {
                         count++;
                         sscanf(b,"%d",&temp);
                         n+=temp;
                    }
                }
               printf("%d\n",count);
               printf("%d",num[0]);
               for(i=1;i<id;i++)
                  printf("--->%d",num[i]);
               printf("\n");
          }
return 0;
}