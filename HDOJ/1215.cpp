////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2013-12-11 19:04:57
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1215
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:2212KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#define MAX 500000

static int a[MAX + 1];

void dabiao( void )
{
     int i, j;
     for( i = 1; i <= MAX / 2; i++ )
          for( j = i + i; j <= MAX; j += i )
          {
               a[j] += i;
               }
     
     }

int main()
{
    dabiao();
    int t, n;
    scanf( "%d", &t );
    while( t-- )
    {
           scanf( "%d", &n );
           printf( "%d\n", a[n] );
           }
    return 0;
    }