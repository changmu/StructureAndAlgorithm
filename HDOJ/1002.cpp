////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2013-12-22 00:32:36
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1002
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:260KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,a1,b1,k;
    char a[1010],b[1010],aa[1010],bb[1010],c[1010];
    scanf("%d",&n);
    getchar();
    k=1;
    while(n--)
    {
        scanf("%s%s",aa,bb);
        a1=strlen(aa);
        b1=strlen(bb);
        for(i=0;i<a1;i++)
            a[a1-i-1]=aa[i];
        for(i=0;i<b1;i++)
            b[b1-i-1]=bb[i];
        if(a1>=b1)
        {
            for(i=0;i<b1;i++)
                c[i]=a[i]+b[i]-'0';
            for(;i<a1;i++)
                c[i]=a[i];
            c[a1]='0';
            c[a1+1]='\0';
            for(i=0;i<a1;i++)
                if(c[i]>'9')
                {
                    c[i]-=10;
                    c[i+1]++;
                }
            printf("Case %d:\n",k);
            for(i=a1-1;i>=0;i--)
                printf("%c",a[i]);
            printf(" + ");
            for(i=b1-1;i>=0;i--)
                printf("%c",b[i]);
            printf(" = ");
            if(c[a1]!='0')
            {
                for(i=a1;i>=0;i--)
                    printf("%c",c[i]);
                printf("\n");
            }    
            else 
            {
                for(i=a1-1;i>=0;i--)
                    printf("%c",c[i]);
                printf("\n");
            }
            if(n!=0)
            printf("\n");
        }
        else
        {
            for(i=0;i<a1;i++)
                c[i]=a[i]+b[i]-'0';
            for(;i<b1;i++)
                c[i]=b[i];
            c[b1]='0';
            c[b1+1]='\0';
            for(i=0;i<b1;i++)
                if(c[i]>'9')
                {
                    c[i]-=10;
                    c[i+1]++;
                }
            printf("Case %d:\n",k);
            for(i=a1-1;i>=0;i--)
                printf("%c",a[i]);
            printf(" + ");
            for(i=b1-1;i>=0;i--)
                printf("%c",b[i]);
            printf(" = ");
            if(c[b1]!='0')
            {
                for(i=b1;i>=0;i--)
                    printf("%c",c[i]);
                printf("\n");
            }
            else 
            {
                for(i=b1-1;i>=0;i--)
                    printf("%c",c[i]);
                printf("\n");
            }
            if(n!=0)
            printf("\n");
        }
        k++;
    }
    return 0;
}