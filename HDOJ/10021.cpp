////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: 长木
////Run ID: 
////Submit time: 2013-12-22 00:57:09
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1002
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:264KB
//////////////////System Comment End//////////////////
//hdu 1002
#include <stdio.h>
#include <string.h>

char a[1002], b[1002], c[1002];
int d[1002];

int main()
{
	int n, count = 1, maxlen;
	scanf( "%d", &n );	
	while( n-- )
	{
		memset( a, '\0', sizeof( a ) );
		memset( b, '\0', sizeof( b ) );
		memset( c, '\0', sizeof( c ) );  //保存进位1
		memset( d, 0, sizeof( d ) ); //存初始和
		scanf( "%s%s", a + 1, b + 1 ); //前面留一位来保存进位
		//scanf( "%s", a + 1 );
		//scanf( "%s", b + 1 );
		a[ 0 ] = b[ 0 ] = '0';
		int a1 = strlen( a ); 
		int b1 = strlen( b );
		maxlen = a1 > b1 ? a1 : b1;
		maxlen -= 1;  //最大下标
		int i = a1 - 1, j = b1 - 1;  //i为数组a最后一位的下标
		while( i > 0 && j > 0 )
		{
			int t = ( a[ i-- ] - '0' ) + ( b[ j-- ] - '0' );
			if( t > 9 )
			{
				t -= 10;
				c[ maxlen - 1 ] = '1';
				d[ maxlen-- ] = t;
			}
			else
				d[ maxlen-- ] = t;
		}
		while( i > 0 )
			d[ maxlen-- ] = a[ i-- ] - '0';
		while( j > 0 )
			d[ maxlen-- ] = b[ j-- ] - '0';
		maxlen = a1 > b1 ? a1 : b1;
		maxlen -= 1;
		for( int i = 0; i <= maxlen; ++i )//补充进位
			if( c[i] )
				++d[i];
		//memset( c, '\0', sizeof( c ) );  //保存进位1
		for( int i = maxlen; i >= 0; --i )
			if( d[i] > 9 )
			{
				++d[ i - 1 ];
				d[i] -= 10;
			}
		//删除前面的0
		/*int begin;
		for( begin = 0; begin < maxlen; ++begin )
		if( d[begin] )
		break;*/
		/*int aa = 0, bb = 0;
		for( aa = 0; aa < a1 - 1; ++aa )
		if( a[aa] != '0' )
		break;
		for( bb = 0; bb < b1 - 1; ++bb )
		if( a[bb] != '0' )
		break;*/
		printf( "Case %d:\n%s + %s = ", count++, a + 1, b + 1 );
		if( c[0] )
			for( int i = 0; i <= maxlen; ++i )
				printf( "%d", d[i] );
		else
			for( int i = 1; i <= maxlen; ++i )
				printf( "%d", d[i] );
		printf( "\n" );
		if( n != 0 )
			printf( "\n" );
	}
	return 0;
}
/*Sample Input
2
1 2
112233445566778899 998877665544332211


Sample Output
Case 1:
1 + 2 = 3

Case 2:
112233445566778899 + 998877665544332211 = 1111111111111111110
*/