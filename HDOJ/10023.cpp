////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-05-02 10:49:59
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1002
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<string.h>
#define LEN 2000
int an1[LEN+10];
int an2[LEN+10];
char stra[LEN+10];
char strb[LEN+10];
int main()
{
	int t,n=0,j;
	scanf("%d",&t);
	while(n++<t)
	{
		scanf("%s", stra);
        scanf("%s", strb);
        int i, j;
        int Len1 = strlen( stra);
        for( j = 0, i = Len1 - 1;i >= 0 ; i --)  //&micro;&sup1;&ETH;¨°&acute;&aelig;&micro;&frac12;&Aacute;¨ª&Ograve;&raquo;&cedil;&ouml;&Otilde;&ucirc;&ETH;&Icirc;&Ecirc;&yacute;¡Á¨¦&Ouml;&ETH; 
            an1[j++] = stra[i] - '0';
        int Len2 = strlen(strb);
        for( j = 0, i = Len2 - 1;i >= 0 ; i --)
            an2[j++] = strb[i] - '0';
        for( i = 0;i < LEN ; i ++ ) 
        {  an1[i] += an2[i]; //&Ouml;&eth;&Icirc;&raquo;&Iuml;¨¤&frac14;&Oacute;
           if( an1[i] >= 10 ) 
           { //&iquest;&acute;&Ecirc;&Ccedil;¡¤&ntilde;&Ograve;&ordf;&frac12;&oslash;&Icirc;&raquo;
              an1[i] -= 10;
              an1[i+1] ++; //&frac12;&oslash;&Icirc;&raquo;
           }
        }
         printf("Case %d:\n",n);//&Ecirc;&auml;&sup3;&ouml;&frac12;¨¢&sup1;&ucirc;
         printf("%s + %s = ",stra,strb);
         for(j=LEN+10-1;an1[j]==0;j--);//&acute;&Oacute;&cedil;&szlig;&Icirc;&raquo;¡ã&Ntilde;c&Ouml;&ETH;&Ecirc;&Ccedil;&Aacute;&atilde;&micro;&Auml;&cedil;&oslash;&Aring;&Aring;&sup3;&yacute;
         if(j<0)
            printf("0");
         else
         for(;j>=0;j--)
         {
            printf("%d",an1[j]);
         }
         printf("\n");
         if(n != t)   printf("\n");
         memset(an1, 0, sizeof(an1));
         memset(an2, 0, sizeof(an2));
    }
    return 0;
}
