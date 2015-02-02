////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2013-12-11 19:56:24
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4548
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:8100KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <math.h>
#define MAX 1000000

static int a[MAX + 1], b[MAX + 1];

int sum( int n );
void dabiao( void );
void dabiao2( void );

void dabiao( void )
{
	int i, j;
	a[0] = a[1] = 1;  //'1' stands for not a prime.
	for( i = 2; i <= sqrt( ( double )MAX ); i++ )
	{
		if( a[i] )
			continue;
		for( j = i * i; j <= MAX; j += i )
			a[j] = 1;
	}
	return;
}

void dabiao2( void )
{
	int i;
	for( i = 2; i <= MAX; i++)
		if( a[i] == 0 && a[ sum( i ) ] == 0 )
			b[i] = b[i - 1] + 1;
		else
			b[i] = b[i - 1];
	return;
}

int sum( int n )
{
	int s = 0;
	while( n / 10 != 0 )
	{
		s += n % 10;
		n /= 10;
	}
	return s + n;
}     

int main()
{
	dabiao();
	dabiao2();
	int n, l, r, i = 1;
	scanf( "%d", &n );
	while( n-- && scanf( "%d%d", &l, &r ) )
		printf( "Case #%d: %d\n", i++, b[r] - b[l - 1] ); 
	return 0;
}
